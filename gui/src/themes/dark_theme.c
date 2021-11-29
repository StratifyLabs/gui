#include "themes.h"

static const lv_style_prop_t transition_property_list[] = {
 (lv_style_prop_t)0x0021,  // background_opacity
 (lv_style_prop_t)0x0020,  // background_color
 (lv_style_prop_t)0x080A,  // transform_width
 (lv_style_prop_t)0x080B,  // transform_height
 (lv_style_prop_t)0x300D,  // translate_y
 (lv_style_prop_t)0x300C,  // translate_x
 (lv_style_prop_t)0x080E,  // transform_zoom
 (lv_style_prop_t)0x080F,  // transform_angle
 (lv_style_prop_t)0x0064,  // color_filter_opacity
 (lv_style_prop_t)0x0063,  // color_filter_descriptor
};

static const lv_style_transition_dsc_t transition_normal = {
  .props = transition_property_list,
  .user_data = NULL,
  .path_xcb = lv_anim_path_linear,
  .time = 100,
  .delay = 0,
};

static const lv_style_transition_dsc_t transition_delayed = {
  .props = transition_property_list,
  .user_data = NULL,
  .path_xcb = lv_anim_path_linear,
  .time = 100,
  .delay = 70,
};

static lv_color_t dark_filter_callback(const lv_color_filter_dsc_t * filter_descriptor, lv_color_t color, lv_opa_t opacity){
  LV_UNUSED(filter_descriptor);
  return lv_color_darken(color, opacity);
}

static lv_color_t grey_filter_callback(const lv_color_filter_dsc_t * filter_descriptor, lv_color_t color, lv_opa_t opacity){
  LV_UNUSED(filter_descriptor);
  return lv_color_mix(lv_palette_lighten(LV_PALETTE_GREY, 2), color, opacity);
}

static const lv_style_const_prop_t screen_const_list[] = {
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = { .full= 0xffffff } } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = { .full= 0xffffff } } },
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 4 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 4 } },
};
static const lv_style_t screen_style = {
  .v_p = { .const_props = screen_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 5
};

static const lv_style_const_prop_t scrollbar_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = { .full = 0xFF9E9E9E }  } },
  { .prop = LV_STYLE_RADIUS, .value = { .num = 0x7fff } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 7 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 7 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = 7 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = 7 } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 102 } },
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_normal } },
};
static const lv_style_t scrollbar_style = {
  .v_p = { .const_props = scrollbar_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 8
};

static const lv_style_const_prop_t scrollbar_scrolled_const_list[] = {
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
};
static const lv_style_t scrollbar_scrolled_style = {
  .v_p = { .const_props = scrollbar_scrolled_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 1
};

static const lv_style_const_prop_t card_const_list[] = {
  { .prop = LV_STYLE_RADIUS, .value = { .num = 12 } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = { .full = 0xFF607D8B }  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = { .full = 0xFF607D8B }  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 10 } },
  { .prop = LV_STYLE_BORDER_POST, .value = { .num = 1 } },
  { .prop = LV_STYLE_PAD_TOP, .value = {  } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = {  } },
  { .prop = LV_STYLE_PAD_LEFT, .value = {  } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = {  } },
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 4 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 4 } },
  { .prop = LV_STYLE_LINE_COLOR, .value = { .color = { .full = 0xFF607D8B }  } },
  { .prop = LV_STYLE_LINE_WIDTH, .value = { .num = 1 } },
};
static const lv_style_t card_style = {
  .v_p = { .const_props = card_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 11
};

static const lv_style_const_prop_t button_const_list[] = {
  { .prop = LV_STYLE_RADIUS, .value = { .num = 12 } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 0xFF } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = { .full = 0xFF607D8B }  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = { .full= 0xFF607D8B } } },
  { .prop = LV_STYLE_PAD_LEFT, .value = {  } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = {  } },
  { .prop = LV_STYLE_PAD_TOP, .value = {  } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = {  } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 3 } },
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 3 } },
};
static const lv_style_t button_style = {
  .v_p = { .const_props = button_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 8
};

static const lv_style_const_prop_t background_color_primary_const_list[] = {
};
static const lv_style_t background_color_primary_style = {
  .v_p = { .const_props = background_color_primary_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t background_color_primary_muted_const_list[] = {
};
static const lv_style_t background_color_primary_muted_style = {
  .v_p = { .const_props = background_color_primary_muted_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t background_color_secondary_const_list[] = {
};
static const lv_style_t background_color_secondary_style = {
  .v_p = { .const_props = background_color_secondary_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t background_color_secondary_muted_const_list[] = {
};
static const lv_style_t background_color_secondary_muted_style = {
  .v_p = { .const_props = background_color_secondary_muted_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t background_color_grey_const_list[] = {
};
static const lv_style_t background_color_grey_style = {
  .v_p = { .const_props = background_color_grey_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t background_color_white_const_list[] = {
};
static const lv_style_t background_color_white_style = {
  .v_p = { .const_props = background_color_white_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t pressed_const_list[] = {
  { .prop = LV_STYLE_COLOR_FILTER_DSC, .value = { .ptr = (void*)dark_filter_callback } },
  { .prop = LV_STYLE_COLOR_FILTER_OPA, .value = { .num = 35 } },
};
static const lv_style_t pressed_style = {
  .v_p = { .const_props = pressed_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 2
};

static const lv_style_const_prop_t disabled_const_list[] = {
  { .prop = LV_STYLE_COLOR_FILTER_DSC, .value = { .ptr = (void*)grey_filter_callback } },
  { .prop = LV_STYLE_COLOR_FILTER_OPA, .value = { .num = 35 } },
};
static const lv_style_t disabled_style = {
  .v_p = { .const_props = disabled_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 2
};

static const lv_style_const_prop_t padding_zero_const_list[] = {
};
static const lv_style_t padding_zero_style = {
  .v_p = { .const_props = padding_zero_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t padding_tiny_const_list[] = {
};
static const lv_style_t padding_tiny_style = {
  .v_p = { .const_props = padding_tiny_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t padding_small_const_list[] = {
};
static const lv_style_t padding_small_style = {
  .v_p = { .const_props = padding_small_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t padding_normal_const_list[] = {
};
static const lv_style_t padding_normal_style = {
  .v_p = { .const_props = padding_normal_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t padding_gap_const_list[] = {
};
static const lv_style_t padding_gap_style = {
  .v_p = { .const_props = padding_gap_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t line_space_large_const_list[] = {
};
static const lv_style_t line_space_large_style = {
  .v_p = { .const_props = line_space_large_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t text_align_center_const_list[] = {
};
static const lv_style_t text_align_center_style = {
  .v_p = { .const_props = text_align_center_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t outline_primary_const_list[] = {
  { .prop = LV_STYLE_OUTLINE_COLOR, .value = { .color = { .full= 0xffffff } } },
  { .prop = LV_STYLE_OUTLINE_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_OUTLINE_PAD, .value = { .num = 4 } },
  { .prop = LV_STYLE_OUTLINE_OPA, .value = { .num = 127 } },
};
static const lv_style_t outline_primary_style = {
  .v_p = { .const_props = outline_primary_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 4
};

static const lv_style_const_prop_t outline_secondary_const_list[] = {
  { .prop = LV_STYLE_OUTLINE_COLOR, .value = { .color = { .full= 0xffffff } } },
  { .prop = LV_STYLE_OUTLINE_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_OUTLINE_PAD, .value = { .num = 4 } },
  { .prop = LV_STYLE_OUTLINE_OPA, .value = { .num = 127 } },
};
static const lv_style_t outline_secondary_style = {
  .v_p = { .const_props = outline_secondary_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 4
};

static const lv_style_const_prop_t circle_const_list[] = {
};
static const lv_style_t circle_style = {
  .v_p = { .const_props = circle_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t radius_none_const_list[] = {
};
static const lv_style_t radius_none_style = {
  .v_p = { .const_props = radius_none_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t clip_corner_const_list[] = {
  { .prop = LV_STYLE_CLIP_CORNER, .value = { .num = 1 } },
};
static const lv_style_t clip_corner_style = {
  .v_p = { .const_props = clip_corner_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 1
};

static const lv_style_const_prop_t grow_const_list[] = {
};
static const lv_style_t grow_style = {
  .v_p = { .const_props = grow_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t transition_delayed_const_list[] = {
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_delayed } },
};
static const lv_style_t transition_delayed_style = {
  .v_p = { .const_props = transition_delayed_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 1
};

static const lv_style_const_prop_t transition_normal_const_list[] = {
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_normal } },
};
static const lv_style_t transition_normal_style = {
  .v_p = { .const_props = transition_normal_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 1
};

static const lv_style_const_prop_t animation_const_list[] = {
};
static const lv_style_t animation_style = {
  .v_p = { .const_props = animation_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t knob_const_list[] = {
};
static const lv_style_t knob_style = {
  .v_p = { .const_props = knob_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t indicator_const_list[] = {
};
static const lv_style_t indicator_style = {
  .v_p = { .const_props = indicator_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t arc_indicator_const_list[] = {
};
static const lv_style_t arc_indicator_style = {
  .v_p = { .const_props = arc_indicator_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t arc_indicator_primary_const_list[] = {
};
static const lv_style_t arc_indicator_primary_style = {
  .v_p = { .const_props = arc_indicator_primary_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t chart_series_const_list[] = {
  { .prop = LV_STYLE_LINE_WIDTH, .value = { .num = 3 } },
  { .prop = LV_STYLE_RADIUS, .value = { .num = 3 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = 8 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = 8 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 2 } },
};
static const lv_style_t chart_series_style = {
  .v_p = { .const_props = chart_series_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 5
};

static const lv_style_const_prop_t chart_indicator_const_list[] = {
  { .prop = LV_STYLE_RADIUS, .value = { .num = 0x7fff } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = 8 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = 8 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = { .full= 0xffffff } } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 0xFF } },
};
static const lv_style_t chart_indicator_style = {
  .v_p = { .const_props = chart_indicator_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 5
};

static const lv_style_const_prop_t chart_ticks_const_list[] = {
};
static const lv_style_t chart_ticks_style = {
  .v_p = { .const_props = chart_ticks_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t chart_background_const_list[] = {
  { .prop = LV_STYLE_BORDER_POST, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 10 } },
  { .prop = LV_STYLE_LINE_COLOR, .value = { .color = { .full = 0xFF9E9E9E }  } },
};
static const lv_style_t chart_background_style = {
  .v_p = { .const_props = chart_background_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 3
};

static const lv_style_const_prop_t dropdown_list_const_list[] = {
};
static const lv_style_t dropdown_list_style = {
  .v_p = { .const_props = dropdown_list_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t checkbox_marker_const_list[] = {
};
static const lv_style_t checkbox_marker_style = {
  .v_p = { .const_props = checkbox_marker_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t checkbox_marker_checked_const_list[] = {
};
static const lv_style_t checkbox_marker_checked_style = {
  .v_p = { .const_props = checkbox_marker_checked_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t switch_knob_const_list[] = {
};
static const lv_style_t switch_knob_style = {
  .v_p = { .const_props = switch_knob_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t line_const_list[] = {
};
static const lv_style_t line_style = {
  .v_p = { .const_props = line_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t table_cell_const_list[] = {
};
static const lv_style_t table_cell_style = {
  .v_p = { .const_props = table_cell_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t meter_marker_const_list[] = {
};
static const lv_style_t meter_marker_style = {
  .v_p = { .const_props = meter_marker_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t meter_indicator_const_list[] = {
};
static const lv_style_t meter_indicator_style = {
  .v_p = { .const_props = meter_indicator_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t calendar_background_const_list[] = {
};
static const lv_style_t calendar_background_style = {
  .v_p = { .const_props = calendar_background_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t calendar_day_const_list[] = {
};
static const lv_style_t calendar_day_style = {
  .v_p = { .const_props = calendar_day_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t colorwheel_main_const_list[] = {
};
static const lv_style_t colorwheel_main_style = {
  .v_p = { .const_props = colorwheel_main_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t message_box_background_const_list[] = {
};
static const lv_style_t message_box_background_style = {
  .v_p = { .const_props = message_box_background_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t message_box_button_background_const_list[] = {
};
static const lv_style_t message_box_button_background_style = {
  .v_p = { .const_props = message_box_button_background_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t keyboard_button_background_const_list[] = {
};
static const lv_style_t keyboard_button_background_style = {
  .v_p = { .const_props = keyboard_button_background_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t list_background_const_list[] = {
};
static const lv_style_t list_background_style = {
  .v_p = { .const_props = list_background_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t list_button_const_list[] = {
};
static const lv_style_t list_button_style = {
  .v_p = { .const_props = list_button_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t list_item_grow_const_list[] = {
};
static const lv_style_t list_item_grow_style = {
  .v_p = { .const_props = list_item_grow_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t list_label_const_list[] = {
};
static const lv_style_t list_label_style = {
  .v_p = { .const_props = list_label_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t tab_background_focus_const_list[] = {
};
static const lv_style_t tab_background_focus_style = {
  .v_p = { .const_props = tab_background_focus_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t text_area_cursor_const_list[] = {
};
static const lv_style_t text_area_cursor_style = {
  .v_p = { .const_props = text_area_cursor_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t text_area_placeholder_const_list[] = {
};
static const lv_style_t text_area_placeholder_style = {
  .v_p = { .const_props = text_area_placeholder_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t tab_button_const_list[] = {
};
static const lv_style_t tab_button_style = {
  .v_p = { .const_props = tab_button_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

static const lv_style_const_prop_t led_const_list[] = {
};
static const lv_style_t led_style = {
  .v_p = { .const_props = led_const_list },
  .prop1 = 0,
  .has_group = 0,
  .is_const = 1,
  .prop_cnt = 0
};

void dark_apply_callback(lv_theme_t * theme, lv_obj_t * object){
  if(lv_obj_get_parent(object) == NULL){
    lv_obj_add_style(object, (lv_style_t*)&screen_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }

  if(lv_obj_check_type(object, &lv_obj_class) && lv_obj_check_type(lv_obj_get_parent(object), &lv_tabview_class)){
    return;
  }

  if(lv_obj_check_type(object, &lv_obj_class) && lv_obj_check_type(lv_obj_get_parent(lv_obj_get_parent(object)), &lv_tabview_class)){
    lv_obj_add_style(object, (lv_style_t*)&padding_normal_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }

  if(lv_obj_get_child_id(object) == 0 && lv_obj_check_type(lv_obj_get_parent(object), &lv_win_class)){
    lv_obj_add_style(object, (lv_style_t*)&background_color_grey_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_tiny_style, LV_STATE_DEFAULT);
    return;
  }

  if(lv_obj_get_child_id(object) == 0 && lv_obj_check_type(lv_obj_get_parent(object), &lv_win_class)){
    lv_obj_add_style(object, (lv_style_t*)&screen_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_normal_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }

  if(lv_obj_check_type(object, &lv_obj_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }

  if(lv_obj_check_type(object, &lv_btn_class)){
    lv_obj_add_style(object, (lv_style_t*)&button_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&transition_delayed_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&grow_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&transition_normal_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_style, LV_STATE_CHECKED);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED);
    return;
  }

  if(lv_obj_check_type(object, &lv_line_class)){
    return;
  }

  if(lv_obj_check_type(object, &lv_btnmatrix_class) && lv_obj_check_type(lv_obj_get_parent(object), &lv_msgbox_class)){
    lv_obj_add_style(object, (lv_style_t*)&button_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_CHECKED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_muted_style, LV_STATE_FOCUS_KEY|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_muted_style, LV_STATE_EDITED|LV_PART_ITEMS);
    return;
  }

  if(lv_obj_check_type(object, &lv_btnmatrix_class) && lv_obj_check_type(lv_obj_get_parent(object), &lv_tabview_class)){
    lv_obj_add_style(object, (lv_style_t*)&background_color_white_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&tab_background_focus_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_muted_style, LV_STATE_CHECKED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&tab_button_style, LV_STATE_CHECKED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&tab_background_focus_style, LV_STATE_FOCUS_KEY|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&outline_secondary_style, LV_STATE_EDITED|LV_PART_ITEMS);
    return;
  }

  if(lv_obj_check_type(object, &lv_btnmatrix_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&button_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_CHECKED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&outline_secondary_style, LV_STATE_EDITED|LV_PART_ITEMS);
    return;
  }

  if(lv_obj_check_type(object, &lv_bar_class)){
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_muted_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&outline_secondary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    return;
  }

  if(lv_obj_check_type(object, &lv_slider_class)){
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_muted_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&outline_secondary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&knob_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    return;
  }

  if(lv_obj_check_type(object, &lv_table_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_zero_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&radius_none_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&outline_secondary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&background_color_white_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&padding_normal_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&table_cell_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_FOCUS_KEY|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_style, LV_STATE_EDITED|LV_PART_ITEMS);
    return;
  }

  if(lv_obj_check_type(object, &lv_checkbox_class)){
    lv_obj_add_style(object, (lv_style_t*)&padding_gap_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&checkbox_marker_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&transition_delayed_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_CHECKED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&checkbox_marker_checked_style, LV_STATE_CHECKED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&grow_style, LV_STATE_PRESSED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&transition_normal_style, LV_STATE_PRESSED|LV_PART_INDICATOR);
    return;
  }

  if(lv_obj_check_type(object, &lv_switch_class)){
    lv_obj_add_style(object, (lv_style_t*)&background_color_grey_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_CHECKED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&knob_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    lv_obj_add_style(object, (lv_style_t*)&background_color_white_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    lv_obj_add_style(object, (lv_style_t*)&switch_knob_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_KNOB);
    return;
  }

  if(lv_obj_check_type(object, &lv_chart_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_small_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&chart_background_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&chart_series_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&chart_indicator_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&chart_ticks_style, LV_STATE_DEFAULT|LV_PART_TICKS);
    return;
  }

  if(lv_obj_check_type(object, &lv_roller_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&animation_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&line_space_large_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&text_align_center_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_DEFAULT|LV_PART_SELECTED);
    return;
  }

  if(lv_obj_check_type(object, &lv_dropdown_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_small_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&transition_delayed_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&transition_normal_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&transition_normal_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    return;
  }

  if(lv_obj_check_type(object, &lv_dropdownlist_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&clip_corner_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&line_space_large_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&dropdown_list_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&background_color_white_style, LV_STATE_DEFAULT|LV_PART_SELECTED);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_CHECKED|LV_PART_SELECTED);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_SELECTED);
    return;
  }

  if(lv_obj_check_type(object, &lv_arc_class)){
    lv_obj_add_style(object, (lv_style_t*)&arc_indicator_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&arc_indicator_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&arc_indicator_primary_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&knob_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    return;
  }

  if(lv_obj_check_type(object, &lv_spinner_class)){
    lv_obj_add_style(object, (lv_style_t*)&arc_indicator_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&arc_indicator_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&arc_indicator_primary_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    return;
  }

  if(lv_obj_check_type(object, &lv_meter_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&meter_indicator_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    return;
  }

  if(lv_obj_check_type(object, &lv_textarea_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_small_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&text_area_cursor_style, LV_STATE_FOCUSED|LV_PART_CURSOR);
    lv_obj_add_style(object, (lv_style_t*)&text_area_placeholder_style, LV_STATE_DEFAULT);
    return;
  }

  if(lv_obj_check_type(object, &lv_calendar_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&calendar_background_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&calendar_day_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_style, LV_STATE_EDITED);
    return;
  }

  if(lv_obj_check_type(object, &lv_calendar_header_arrow_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    return;
  }

  if(lv_obj_check_type(object, &lv_calendar_header_dropdown_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    return;
  }

  if(lv_obj_check_type(object, &lv_keyboard_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_small_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&button_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_white_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&keyboard_button_background_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_grey_style, LV_STATE_CHECKED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_muted_style, LV_STATE_FOCUS_KEY|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_muted_style, LV_STATE_EDITED|LV_PART_ITEMS);
    return;
  }

  if(lv_obj_check_type(object, &lv_list_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&list_background_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }

  if(lv_obj_check_type(object, &lv_list_text_class)){
    lv_obj_add_style(object, (lv_style_t*)&background_color_grey_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&list_item_grow_style, LV_STATE_DEFAULT);
    return;
  }

  if(lv_obj_check_type(object, &lv_list_btn_class)){
    lv_obj_add_style(object, (lv_style_t*)&background_color_white_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&list_button_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&list_item_grow_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&list_item_grow_style, LV_STATE_PRESSED);
    return;
  }

  if(lv_obj_check_type(object, &lv_msgbox_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&message_box_background_style, LV_STATE_DEFAULT);
    return;
  }

  if(lv_obj_check_type(object, &lv_spinbox_class)){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_small_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&background_color_grey_style, LV_STATE_CHECKED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_muted_style, LV_STATE_FOCUS_KEY|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_DEFAULT|LV_PART_CURSOR);
    return;
  }

  if(lv_obj_check_type(object, &lv_tileview_class)){
    lv_obj_add_style(object, (lv_style_t*)&screen_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }

  if(lv_obj_check_type(object, &lv_tileview_tile_class)){
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }

  if(lv_obj_check_type(object, &lv_tabview_class)){
    lv_obj_add_style(object, (lv_style_t*)&screen_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_zero_style, LV_STATE_DEFAULT);
    return;
  }

  if(lv_obj_check_type(object, &lv_colorwheel_class)){
    lv_obj_add_style(object, (lv_style_t*)&colorwheel_main_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_normal_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&background_color_white_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    lv_obj_add_style(object, (lv_style_t*)&padding_normal_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    return;
  }

  if(lv_obj_check_type(object, &lv_led_class)){
    lv_obj_add_style(object, (lv_style_t*)&led_style, LV_STATE_DEFAULT);
    return;
  }

}

lv_theme_t dark_theme = {
  .apply_cb = dark_apply_callback,
  .parent = NULL,
  .user_data = NULL,
  .disp = NULL,
  .color_primary = 0,
  .color_secondary = 0,
  .font_small = NULL,
  .font_normal = NULL,
  .font_large = NULL,
  .flags = 0
};

lv_theme_t * dark_theme_initialize(lv_disp_t * disp, lv_theme_t * parent){
  dark_theme.disp = disp;
  dark_theme.parent = parent;
  return &dark_theme;
}
