//
// Created by Tyler Gilbert on 11/27/21.
//

#include <fs.hpp>
#include <json.hpp>
#include <lvgl.hpp>
#include <printer.hpp>
#include <var.hpp>

#include "ThemeGenerator.hpp"

ThemeGenerator::ThemeGenerator(const sys::Cli &cli) : m_cli(&cli) {

  printer().set_verbose_level(cli.get_option("verbose"));
  Printer::Array root_array(printer(), "guiThemeGenerator");

  m_name = cli.get_option("name");
  if (m_name.is_empty()) {
    errno = EINVAL;
    API_SYSTEM_CALL("`name` must be specified on the command line", -1);
  }

  if (is_success()) {
    m_variables_object = load_json_file("variables", "$variables");
    m_styles_object = load_json_file("styles", "#styles");
    m_classes_object = load_json_file("classes", "&classes");
  }

  if (is_success()) {
    const auto output_path = cli.get_option("output");
    m_output = File(
      File::IsOverwrite::yes,
      output_path.is_empty() ? StringView("theme.c") : output_path);
  }

  generate_descriptors();
  generate_styles();
  generate_apply_callback();
  generate_theme();

  if (is_error()) {
    printer().object("error", error());
    return;
  }
}

json::JsonObject
ThemeGenerator::load_json_file(const char *option_name, const char *key) {
  Printer::Object po(printer(), option_name);
  const auto json_path = m_cli->get_option(option_name);
  const auto theme_path = m_cli->get_option("theme");
  const auto path = json_path.is_empty() ? theme_path : json_path;

  if (FileSystem().exists(path)) {
    if (!FileSystem().get_info(path).is_file()) {
      API_RETURN_VALUE_ASSIGN_ERROR(
        JsonObject(),
        "path `" | path | "` is not an existing file",
        EINVAL);
    }
  }

  JsonDocument document;
  printer().key("path", path);
  const auto object = document.load(File(path)).to_object();
  if (document.is_error()) {
    printer().object("jsonError", document.error());
    API_RETURN_VALUE_ASSIGN_ERROR(
      JsonObject(),
      "failed to parse `" | path | "`",
      EINVAL);
  }

  const auto result = object.at(key);
  if (!result.is_object()) {
    API_RETURN_VALUE_ASSIGN_ERROR(
      JsonObject(),
      "`" | path | "` does not have an entry for `" | key | "`",
      EINVAL);
  }
  printer().object(key, result, Printer::Level::message);
  return result;
}

void ThemeGenerator::generate_apply_callback() {
  API_RETURN_IF_ERROR();

  const auto key_list = m_classes_object.get_key_list();

  m_output.write(("void " | m_name
                  | "_apply_callback(lv_theme_t * theme, lv_obj_t * object){\n")
                   .string_view());

  auto add_styles = [&](StringView class_name, JsonObject object) {
    write_output(GeneralString().format(
      "  if(%s){\n",
      object.at("condition").to_cstring()));

    const auto styles_object = object.at("styles").to_object();
    const auto key_list = styles_object.get_key_list();
    for (const auto &key : key_list) {
      //"default"
      GeneralString line;
      const auto state_part = get_lv_state_part(key);

      const auto json_value = styles_object.at(key);
      if (json_value.is_array()) {
        for (const auto &value : json_value.to_array()) {
          line |= var::GeneralString().format(
            "    lv_obj_add_style(object, (lv_style_t*)&%s_style, %s);\n",
            value.to_cstring() + 1,
            state_part.cstring());
        }
      } else {
        line = var::GeneralString().format(
          "    lv_obj_add_style(object, (lv_style_t*)&%s_style, %s);\n",
          json_value.to_cstring() + 1,
          state_part.cstring());
      }

      write_output(line);
    }

    write_output("    return;\n");
    write_output("  }\n\n");
  };

  for (const auto &key : key_list) {
    add_styles(key, m_classes_object.at(key).to_object());
  }

  m_output.write("}\n\n");
}

void ThemeGenerator::generate_theme() {
  API_RETURN_IF_ERROR();
  const auto name = m_name;
  write_output("lv_theme_t " | name | "_theme = {\n");
  write_output("  .apply_cb = " | name | "_apply_callback,\n");
  m_output.write("  .parent = NULL,\n")
    .write("  .user_data = NULL,\n")
    .write("  .disp = NULL,\n")
    .write("  .color_primary = 0,\n")
    .write("  .color_secondary = 0,\n")
    .write("  .font_small = NULL,\n")
    .write("  .font_normal = NULL,\n")
    .write("  .font_large = NULL,\n")
    .write("  .flags = 0\n")
    .write("};\n\n");

  write_output(
    "lv_theme_t * " | name
    | "_theme_initialize(lv_disp_t * disp, lv_theme_t * parent){\n");
  write_output("  " | name | "_theme.disp = disp;\n");
  write_output("  " | name | "_theme.parent = parent;\n");
  write_output("  return &" | name | "_theme;\n");
  write_output("}\n");
}

void ThemeGenerator::generate_descriptors() {

  write_output("#include \"themes.h\"\n\n");

  const auto key_list = m_variables_object.get_key_list();
  for (const auto &variable : m_variables_object) {
    if (variable.is_object()) {
      const auto json_object = variable.to_object();
      const auto type = json_object.at("type").to_string_view();
      const auto name = json_object.at("name").to_string_view();
      if (type == "transitionPropertyList") {
        const auto property_list = json_object.at("properties").to_array();

        m_output.write(
          ("static const lv_style_prop_t " | name | "[] = {\n").string_view());

        var::GeneralString property_list_string;
        for (const auto &property : property_list) {
          property_list_string
            |= var::NumberString(
                 u32(Style::property_from_cstring(property.to_cstring())),
                 " (lv_style_prop_t)0x%04X,")
               | "  // " | property.to_string_view() | "\n";
        }
        m_output.write(property_list_string.string_view()).write("};\n\n");
      }
    }
  }

  for (const auto &variable : m_variables_object) {
    if (variable.is_object()) {
      const auto json_object = variable.to_object();
      const auto type = json_object.at("type").to_string_view();
      const auto name = json_object.at("name").to_string_view();
      if (type == "transitionPropertyList") {
        // this is already handled
      } else if (type == "transitionDescriptor") {
        const auto variable_name = var::GeneralString(name);
        const auto delay = get_json_value(json_object.at("delay"));
        const auto period = get_json_value(json_object.at("period"));
        const auto path_type = get_json_value(json_object.at("path"));
        const auto property_list
          = get_json_value(json_object.at("property_list"));

        m_output
          .write(("static const lv_style_transition_dsc_t " | variable_name
                  | " = {\n")
                   .string_view())
          .write(("  .props = " | property_list | ",\n").string_view())
          .write("  .user_data = NULL,\n")
          .write(("  .path_xcb = "
                  | StringView(get_lv_path_animation_path(
                    Animation::path_from_cstring(path_type)))
                  | ",\n")
                   .string_view())
          .write(("  .time = " | period | ",\n").string_view())
          .write(("  .delay = " | delay | ",\n").string_view())
          .write("};\n\n");
      } else if (type == "colorFilterDescriptor") {
        const auto code = get_json_value(json_object.at("code"));
        m_output
          .write(("static lv_color_t " | name
                  | "(const lv_color_filter_dsc_t * filter_descriptor, "
                    "lv_color_t color, lv_opa_t opacity){\n")
                   .string_view())
          .write(("  " | code | "\n}\n\n").string_view());
      }
    }
  }
}

void ThemeGenerator::generate_styles() {
  API_RETURN_IF_ERROR();

  auto get_style_const_list_entry = [&](const char *key, const char *value) {
    const char *property_name = get_lv_style_from_name(key);
    const StringView property = property_name;
    if (property == "unknown") {

      // check for special cases
      if (StringView(key) == "padding") {
        const auto update_value
          = get_property_value(Style::property_from_cstring(key), value);
        return var::GeneralString().format(
          "  { .prop = LV_STYLE_PAD_TOP, .value = { %s } },\n"
          "  { .prop = LV_STYLE_PAD_BOTTOM, .value = { %s } },\n"
          "  { .prop = LV_STYLE_PAD_LEFT, .value = { %s } },\n"
          "  { .prop = LV_STYLE_PAD_RIGHT, .value = { %s } }",
          update_value.cstring(),
          update_value.cstring(),
          update_value.cstring(),
          update_value.cstring());
      }

      if (StringView(key) == "horizontal_padding") {
        const auto update_value
          = get_property_value(Style::property_from_cstring(key), value);
        return var::GeneralString().format(
          "  { .prop = LV_STYLE_PAD_LEFT, .value = { %s } },\n"
          "  { .prop = LV_STYLE_PAD_RIGHT, .value = { %s } }",
          update_value.cstring(),
          update_value.cstring());
      }

      if (StringView(key) == "vertical_padding") {
        const auto update_value
          = get_property_value(Style::property_from_cstring(key), value);
        return var::GeneralString().format(
          "  { .prop = LV_STYLE_PAD_TOP, .value = { %s } },\n"
          "  { .prop = LV_STYLE_PAD_BOTTOM, .value = { %s } }",
          update_value.cstring(),
          update_value.cstring());
      }

      API_RETURN_VALUE_ASSIGN_ERROR(
        var::GeneralString(),
        "`" | StringView(key) | "` does not map to an `LV_STYLE_*` value",
        EINVAL);
    }

    return var::GeneralString().format(
      "  { .prop = %s, .value = { %s } }",
      property_name,
      get_property_value(Style::property_from_cstring(key), value).cstring());
  };

  const auto key_list = m_styles_object.get_key_list();

  /*
   * const lv_style_const_prop_t name_const_list[] = {
   *  { .prop = LV_STYLE_WIDTH, .value = { .color = 0xffffff } }
   * };
   *
   * const lv_style_t name_style = {
   *  .v_p = { .const_props = name_const_list },
   *  .prop1 = 0,
   *  .is_const = 1,
   *  .has_group = 0,
   *  .prop_cnt = VALUE
   * };
   *
   */

  for (const auto &entry : key_list) {
    Printer::Object po(printer(), "process " | entry);
    const auto entry_object = m_styles_object.at(entry).to_object();
    const auto entry_key_list = entry_object.get_key_list();
    printer().object("keys", entry_key_list);
    const auto style_name = KeyString(entry).pop_front();
    m_output.write(
      var::GeneralString()
        .format(
          "static const lv_style_const_prop_t %s_const_list[] = {\n",
          style_name.cstring())
        .string_view());

    for (const auto &key_entry : entry_key_list) {

      const auto entry_value = get_json_value(entry_object.at(key_entry));

      const auto style_entry
        = get_style_const_list_entry(KeyString(key_entry), entry_value);

      m_output.write(var::GeneralString()
                       .format("%s,\n", style_entry.cstring())
                       .string_view());
      API_RETURN_IF_ERROR();
    }
    m_output.write("};\n");
    m_output.write(
      var::GeneralString()
        .format("static const lv_style_t %s_style = {\n", style_name.cstring())
        .string_view());
    m_output.write(var::GeneralString()
                     .format(
                       "  .v_p = { .const_props = %s_const_list },\n",
                       style_name.cstring())
                     .string_view());
    m_output.write("  .prop1 = 0,\n");
    m_output.write("  .has_group = 0,\n");
    m_output.write("  .is_const = 1,\n");
    m_output.write(var::GeneralString()
                     .format("  .prop_cnt = %d\n", entry_key_list.count())
                     .string_view());
    m_output.write("};\n\n");
  }
}

var::GeneralString ThemeGenerator::get_variable(const char *key) {
  const auto key_list = m_variables_object.get_key_list();
  for (const auto &entry : key_list) {
    if (StringView(key) == entry) {
      const auto result = m_variables_object.at(entry);

      if (result.is_string()) {
        return result.to_cstring();
      }

      if (result.is_integer()) {
        return GeneralString(NumberString(result.to_integer()).string_view());
      }

      if (result.is_real()) {
        return GeneralString(NumberString(result.to_real()).string_view());
      }

      if (result.is_true()) {
        return GeneralString("1");
      }

      if (result.is_false()) {
        return GeneralString("0");
      }

      if (result.is_object()) {
        return result.to_object().at("name").to_cstring();
      }

      return m_variables_object.at(entry).to_cstring();
    }
  }
  API_RETURN_VALUE_ASSIGN_ERROR(
    "",
    "could not find variable `" | StringView(key) | "`",
    EINVAL);
  return "";
}

var::GeneralString
ThemeGenerator::get_json_value(const json::JsonValue json_value) {
  if (json_value.is_string()) {
    const auto string_value = json_value.to_cstring();
    if (string_value[0] == '$') {
      return get_variable(string_value);
    }

    return GeneralString(json_value.to_cstring());
  }

  if (json_value.is_integer()) {
    return GeneralString(NumberString(json_value.to_integer()).string_view());
  }

  if (json_value.is_real()) {
    return GeneralString(NumberString(json_value.to_real()).string_view());
  }

  if (json_value.is_true()) {
    return "1";
  }

  if (json_value.is_false()) {
    return "0";
  }

  return {};
}

var::GeneralString
ThemeGenerator::get_property_value(Property property, const char *value) {

  printf("variable %s\n", value);

  auto get_color = [&](const char *value) {
    if (const auto number_value = Color::palette_from_cstring(value);
        number_value != Palette::invalid) {
      return var::GeneralString().format(
        ".color = { .full = 0x%08X } ",
        Color::get_palette(number_value).get_color());
    }

    return var::GeneralString().format(".color = { .full= %s }", value);
  };

  auto get_number = [&](const char *value) {
    if (const auto number_value = Style::text_decoration_from_cstring(value);
        number_value != TextDecoration::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::text_alignment_from_cstring(value);
        number_value != TextAlignment::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::border_side_from_cstring(value);
        number_value != BorderSide::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::gradient_direction_from_cstring(value);
        number_value != GradientDirection::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::base_direction_from_cstring(value);
        number_value != BaseDirection::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::direction_from_cstring(value);
        number_value != Direction::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::alignment_from_cstring(value);
        number_value != Alignment::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::flex_flow_from_cstring(value);
        number_value != FlexFlow::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::flex_align_from_cstring(value);
        number_value != FlexAlign::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::scroll_bar_mode_from_cstring(value);
        number_value != ScrollBarMode::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::scroll_snap_mode_from_cstring(value);
        number_value != ScrollSnap::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::is_animate_mode_from_cstring(value);
        number_value != IsAnimate::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::blend_mode_from_cstring(value);
        number_value != BlendMode::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (const auto number_value = Style::opacity_from_cstring(value);
        number_value != Opacity::invalid) {
      return var::GeneralString().format(".num = 0x%X", u32(number_value));
    }

    if (value == StringView("true")) {
      return var::GeneralString(".num = 1");
    }

    if (value == StringView("false")) {
      return var::GeneralString(".num = 0");
    }

    return var::GeneralString().format(".num = %s", value);
  };

  auto get_pointer = [&](const char *value) {
    return var::GeneralString().format(".ptr = (void*)%s", value);
  };

  auto get_pointer_address = [&](const char *value) {
    return var::GeneralString().format(".ptr = (void*)&%s", value);
  };

  switch (property) {

  case Property::background_color:
  case Property::background_color_filtered:
  case Property::background_gradient_color:
  case Property::background_gradient_color_filtered:
  case Property::border_color:
  case Property::border_color_filtered:
  case Property::outline_color:
  case Property::outline_color_filtered:
  case Property::shadow_color:
  case Property::shadow_color_filtered:
  case Property::line_color:
  case Property::line_color_filtered:
  case Property::arc_color:
  case Property::arc_color_filtered:
  case Property::text_color:
  case Property::text_color_filtered:
    return get_color(value);

  case Property::text_font:
  case Property::arc_image_source:
  case Property::background_image_source:
  case Property::color_filter_descriptor:
    return get_pointer(value);
  case Property::transition:
    return get_pointer_address(value);

  case Property::width:
  case Property::minimum_width:
  case Property::maximum_width:
  case Property::height:
  case Property::minimum_height:
  case Property::maximum_height:
  case Property::x:
  case Property::y:
  case Property::alignment:
  case Property::transform_width:
  case Property::transform_height:
  case Property::translate_x:
  case Property::translate_y:
  case Property::transform_zoom:
  case Property::transform_angle:
  case Property::top_padding:
  case Property::bottom_padding:
  case Property::left_padding:
  case Property::right_padding:
  case Property::row_padding:
  case Property::column_padding:
  case Property::background_opacity:
  case Property::background_gradient_direction:
  case Property::background_gradient_stop:
  case Property::background_image_opacity:
  case Property::background_image_recolor_opacity:
  case Property::background_image_tiled:
  case Property::background_main_stop:
  case Property::background_image_recolor:
  case Property::background_image_recolor_filtered:
  case Property::border_opacity:
  case Property::border_width:
  case Property::border_side:
  case Property::border_post:
  case Property::outline_width:
  case Property::outline_opacity:
  case Property::outline_padding:
  case Property::shadow_width:
  case Property::shadow_x_offset:
  case Property::shadow_y_offset:
  case Property::shadow_spread:
  case Property::shadow_opacity:
  case Property::image_opacity:
  case Property::image_recolor:
  case Property::image_recolor_filtered:
  case Property::image_recolor_opacity:
  case Property::line_width:
  case Property::line_dash_width:
  case Property::line_dash_gap:
  case Property::line_rounded:
  case Property::line_opacity:
  case Property::arc_width:
  case Property::arc_rounded:
  case Property::arc_opacity:
  case Property::text_opacity:
  case Property::text_letter_spacing:
  case Property::text_line_spacing:
  case Property::text_decoration:
  case Property::text_alignment:
  case Property::radius:
  case Property::clip_corner:
  case Property::opacity:
  case Property::color_filter_opacity:
  case Property::animation_time:
  case Property::animation_speed:
  case Property::blend_mode:
  case Property::layout:
  case Property::base_direction:
    return get_number(value);

  case Property::invalid:
  case Property::any:
    break;
  }
  return {};
}

const char *ThemeGenerator::get_lv_path_animation_path(Animation::Path value) {
  switch (value) {
  case Animation::Path::linear:
    return "lv_anim_path_linear";
  case Animation::Path::ease_in:
    return "lv_anim_path_ease_in";
  case Animation::Path::ease_out:
    return "lv_anim_path_ease_out";
  case Animation::Path::ease_in_out:
    return "lv_anim_path_ease_in_out";
  case Animation::Path::bounce:
    return "lv_anim_path_bounce";
  case Animation::Path::overshoot:
    return "lv_anim_path_overshoot";
  case Animation::Path::step:
    return "lv_anim_path_step";
  case Animation::Path::invalid:
    return "lv_anim_path_linear";
  }
  return "NULL";
}

const char *ThemeGenerator::get_lv_style_from_name(const char *property_name) {
  const var::StringView property = property_name;
  if (property == "invalid") {
    return "LV_STYLE_PROP_INV";
  }
  if (property == "width") {
    return "LV_STYLE_WIDTH";
  }
  if (property == "minimum_width") {
    return "LV_STYLE_MIN_WIDTH";
  }
  if (property == "maximum_width") {
    return "LV_STYLE_MAX_WIDTH";
  }
  if (property == "height") {
    return "LV_STYLE_HEIGHT";
  }
  if (property == "minimum_height") {
    return "LV_STYLE_MIN_HEIGHT";
  }
  if (property == "maximum_height") {
    return "LV_STYLE_MAX_HEIGHT";
  }
  if (property == "x") {
    return "LV_STYLE_X";
  }
  if (property == "y") {
    return "LV_STYLE_Y";
  }
  if (property == "alignment") {
    return "LV_STYLE_ALIGN";
  }
  if (property == "transform_width") {
    return "LV_STYLE_TRANSFORM_WIDTH";
  }
  if (property == "transform_height") {
    return "LV_STYLE_TRANSFORM_HEIGHT";
  }
  if (property == "translate_x") {
    return "LV_STYLE_TRANSLATE_X";
  }
  if (property == "translate_y") {
    return "LV_STYLE_TRANSLATE_Y";
  }
  if (property == "transform_zoom") {
    return "LV_STYLE_TRANSFORM_ZOOM";
  }
  if (property == "transform_angle") {
    return "LV_STYLE_TRANSFORM_ANGLE";
  }
  if (property == "top_padding") {
    return "LV_STYLE_PAD_TOP";
  }
  if (property == "bottom_padding") {
    return "LV_STYLE_PAD_BOTTOM";
  }
  if (property == "left_padding") {
    return "LV_STYLE_PAD_LEFT";
  }
  if (property == "right_padding") {
    return "LV_STYLE_PAD_RIGHT";
  }
  if (property == "row_padding") {
    return "LV_STYLE_PAD_ROW";
  }
  if (property == "column_padding") {
    return "LV_STYLE_PAD_COLUMN";
  }
  if (property == "background_color") {
    return "LV_STYLE_BG_COLOR";
  }
  if (property == "background_color_filtered") {
    return "LV_STYLE_BG_COLOR_FILTERED";
  }
  if (property == "background_opacity") {
    return "LV_STYLE_BG_OPA";
  }
  if (property == "background_gradient_color") {
    return "LV_STYLE_BG_GRAD_COLOR";
  }
  if (property == "background_gradient_color_filtered") {
    return "LV_STYLE_BG_GRAD_COLOR_FILTERED";
  }
  if (property == "background_gradient_direction") {
    return "LV_STYLE_BG_GRAD_DIR";
  }
  if (property == "background_main_stop") {
    return "LV_STYLE_BG_MAIN_STOP";
  }
  if (property == "background_gradient_stop") {
    return "LV_STYLE_BG_GRAD_STOP";
  }
  if (property == "background_image_source") {
    return "LV_STYLE_BG_IMG_SRC";
  }
  if (property == "background_image_opacity") {
    return "LV_STYLE_BG_IMG_OPA";
  }
  if (property == "background_image_recolor") {
    return "LV_STYLE_BG_IMG_RECOLOR";
  }
  if (property == "background_image_recolor_filtered") {
    return "LV_STYLE_BG_IMG_RECOLOR_FILTERED";
  }
  if (property == "background_image_recolor_opacity") {
    return "LV_STYLE_BG_IMG_RECOLOR_OPA";
  }
  if (property == "background_image_tiled") {
    return "LV_STYLE_BG_IMG_TILED";
  }
  if (property == "border_color") {
    return "LV_STYLE_BORDER_COLOR";
  }
  if (property == "border_color_filtered") {
    return "LV_STYLE_BORDER_COLOR_FILTERED";
  }
  if (property == "border_opacity") {
    return "LV_STYLE_BORDER_OPA";
  }
  if (property == "border_width") {
    return "LV_STYLE_BORDER_WIDTH";
  }
  if (property == "border_side") {
    return "LV_STYLE_BORDER_SIDE";
  }
  if (property == "border_post") {
    return "LV_STYLE_BORDER_POST";
  }
  if (property == "outline_width") {
    return "LV_STYLE_OUTLINE_WIDTH";
  }
  if (property == "outline_color") {
    return "LV_STYLE_OUTLINE_COLOR";
  }
  if (property == "outline_color_filtered") {
    return "LV_STYLE_OUTLINE_COLOR_FILTERED";
  }
  if (property == "outline_opacity") {
    return "LV_STYLE_OUTLINE_OPA";
  }
  if (property == "outline_padding") {
    return "LV_STYLE_OUTLINE_PAD";
  }
  if (property == "shadow_width") {
    return "LV_STYLE_SHADOW_WIDTH";
  }
  if (property == "shadow_x_offset") {
    return "LV_STYLE_SHADOW_OFS_X";
  }
  if (property == "shadow_y_offset") {
    return "LV_STYLE_SHADOW_OFS_Y";
  }
  if (property == "shadow_spread") {
    return "LV_STYLE_SHADOW_SPREAD";
  }
  if (property == "shadow_color") {
    return "LV_STYLE_SHADOW_COLOR";
  }
  if (property == "shadow_color_filtered") {
    return "LV_STYLE_SHADOW_COLOR_FILTERED";
  }
  if (property == "shadow_opacity") {
    return "LV_STYLE_SHADOW_OPA";
  }

  if (property == "image_opacity") {
    return "LV_STYLE_IMG_OPA";
  }
  if (property == "image_recolor") {
    return "LV_STYLE_IMG_RECOLOR";
  }
  if (property == "image_recolor_filtered") {
    return "LV_STYLE_IMG_RECOLOR_FILTERED";
  }
  if (property == "image_recolor_opacity") {
    return "LV_STYLE_IMG_RECOLOR_OPA";
  }

  if (property == "line_width") {
    return "LV_STYLE_LINE_WIDTH";
  }
  if (property == "line_dash_width") {
    return "LV_STYLE_LINE_DASH_WIDTH";
  }
  if (property == "line_dash_gap") {
    return "LV_STYLE_LINE_DASH_GAP";
  }
  if (property == "line_rounded") {
    return "LV_STYLE_LINE_ROUNDED";
  }
  if (property == "line_color") {
    return "LV_STYLE_LINE_COLOR";
  }
  if (property == "line_color_filtered") {
    return "LV_STYLE_LINE_COLOR_FILTERED";
  }
  if (property == "line_opacity") {
    return "LV_STYLE_LINE_OPA";
  }

  if (property == "arc_width") {
    return "LV_STYLE_ARC_WIDTH";
  }
  if (property == "arc_rounded") {
    return "LV_STYLE_ARC_ROUNDED";
  }
  if (property == "arc_color") {
    return "LV_STYLE_ARC_COLOR";
  }
  if (property == "arc_color_filtered") {
    return "LV_STYLE_ARC_COLOR_FILTERED";
  }
  if (property == "arc_opacity") {
    return "LV_STYLE_ARC_OPA";
  }
  if (property == "arc_image_source") {
    return "LV_STYLE_ARC_IMG_SRC";
  }

  if (property == "text_color") {
    return "LV_STYLE_TEXT_COLOR";
  }
  if (property == "text_color_filtered") {
    return "LV_STYLE_TEXT_COLOR_FILTERED";
  }
  if (property == "text_opacity") {
    return "LV_STYLE_TEXT_OPA";
  }
  if (property == "text_font") {
    return "LV_STYLE_TEXT_FONT";
  }
  if (property == "text_letter_spacing") {
    return "LV_STYLE_TEXT_LETTER_SPACE";
  }
  if (property == "text_line_spacing") {
    return "LV_STYLE_TEXT_LINE_SPACE";
  }
  if (property == "text_decoration") {
    return "LV_STYLE_TEXT_DECOR";
  }
  if (property == "text_alignment") {
    return "LV_STYLE_TEXT_ALIGN";
  }

  if (property == "radius") {
    return "LV_STYLE_RADIUS";
  }
  if (property == "clip_corner") {
    return "LV_STYLE_CLIP_CORNER";
  }
  if (property == "opacity") {
    return "LV_STYLE_OPA";
  }
  if (property == "color_filter_descriptor") {
    return "LV_STYLE_COLOR_FILTER_DSC";
  }
  if (property == "color_filter_opacity") {
    return "LV_STYLE_COLOR_FILTER_OPA";
  }
  if (property == "animation_time") {
    return "LV_STYLE_ANIM_TIME";
  }
  if (property == "animation_speed") {
    return "LV_STYLE_ANIM_SPEED";
  }
  if (property == "transition") {
    return "LV_STYLE_TRANSITION";
  }
  if (property == "blend_mode") {
    return "LV_STYLE_BLEND_MODE";
  }
  if (property == "layout") {
    return "LV_STYLE_LAYOUT";
  }
  if (property == "base_direction") {
    return "LV_STYLE_BASE_DIR";
  }

  if (property == "any") {
    return "LV_STYLE_PROP_ANY";
  }

  return "unknown";
}

var::GeneralString ThemeGenerator::get_lv_state_part(var::StringView key_name) {
  GeneralString result;
  const auto modifier_list = key_name.split("|");
  for (const auto &item : modifier_list) {
    if (item.find("default") != StringView::npos) {
      result |= "LV_STATE_DEFAULT|";
    } else if (item.find("checked") != StringView::npos) {
      result |= "LV_STATE_CHECKED|";
    } else if (item.find("focused") != StringView::npos) {
      result |= "LV_STATE_FOCUSED|";
    } else if (item.find("focus_key") != StringView::npos) {
      result |= "LV_STATE_FOCUS_KEY|";
    } else if (item.find("edited") != StringView::npos) {
      result |= "LV_STATE_EDITED|";
    } else if (item.find("hovered") != StringView::npos) {
      result |= "LV_STATE_HOVERED|";
    } else if (item.find("pressed") != StringView::npos) {
      result |= "LV_STATE_PRESSED|";
    } else if (item.find("scrolled") != StringView::npos) {
      result |= "LV_STATE_SCROLLED|";
    } else if (item.find("disabled") != StringView::npos) {
      result |= "LV_STATE_DISABLED|";
    } else if (item.find("user1") != StringView::npos) {
      result |= "LV_STATE_USER_1|";
    } else if (item.find("user2") != StringView::npos) {
      result |= "LV_STATE_USER_2|";
    } else if (item.find("user3") != StringView::npos) {
      result |= "LV_STATE_USER_3|";
    } else if (item.find("user4") != StringView::npos) {
      result |= "LV_STATE_USER_4|";
    } else if (item.find("scrollbar") != StringView::npos) {
      result |= "LV_PART_SCROLLBAR|";
    } else if (item.find("indicator") != StringView::npos) {
      result |= "LV_PART_INDICATOR|";
    } else if (item.find("selected") != StringView::npos) {
      result |= "LV_PART_SELECTED|";
    } else if (item.find("knob") != StringView::npos) {
      result |= "LV_PART_KNOB|";
    } else if (item.find("items") != StringView::npos) {
      result |= "LV_PART_ITEMS|";
    } else if (item.find("ticks") != StringView::npos) {
      result |= "LV_PART_TICKS|";
    } else if (item.find("cursor") != StringView::npos) {
      result |= "LV_PART_CURSOR|";
    }
  }

  result.pop_back();
  return result;
}