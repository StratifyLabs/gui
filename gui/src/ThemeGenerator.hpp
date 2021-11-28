//
// Created by Tyler Gilbert on 11/27/21.
//

#ifndef GUI_THEMEGENERATOR_HPP
#define GUI_THEMEGENERATOR_HPP

#include <json/Json.hpp>
#include <sys/Cli.hpp>
#include <printer/YamlPrinter.hpp>
#include <var/Vector.hpp>
#include <var/StackString.hpp>
#include <lvgl/Types.hpp>
#include <fs/File.hpp>

class ThemeGenerator : public api::ExecutionContext {
public:
  ThemeGenerator(const sys::Cli & cli);

private:
  const sys::Cli * m_cli;
  printer::YamlPrinter m_printer;

  json::JsonObject m_variables_object;
  json::JsonObject m_styles_object;
  json::JsonObject m_classes_object;
  fs::File m_output;
  var::StringView m_name;

  printer::Printer & printer(){
    return m_printer;
  }

  json::JsonObject load_json_file(const char * option_name, const char * key);

  void generate_descriptors();
  void generate_styles();
  void generate_apply_callback();
  void generate_theme();

  const char * get_lv_style_from_name(const char * property_name);
  var::GeneralString get_property_value(lvgl::Property property, const char * value);
  var::GeneralString  get_variable(const char * key);
  var::GeneralString get_json_value(const json::JsonValue value);
  var::GeneralString get_lv_state_part(var::StringView key_name);

  const char *get_lv_path_animation_path(Animation::Path value);


  void write_output(const var::GeneralString & value){
    m_output.write(value.string_view());
  }
};

#endif // GUI_THEMEGENERATOR_HPP
