#include "themes.h"

extern const lv_font_t montserrat_r_28;
extern const lv_font_t montserrat_r_32;
extern const lv_font_t montserrat_r_36;
extern const lv_font_t montserrat_sb_36;
extern const lv_font_t montserrat_sb_28;
extern const lv_font_t montserrat_r_36;
extern const lv_font_t montserrat_r_36;
extern const lv_font_t montserrat_sb_28;
extern const lv_font_t montserrat_sb_36;
extern const lv_font_t montserrat_sb_36;
extern const lv_font_t montserrat_sb_44;
extern const lv_font_t montserrat_sb_28;
extern const lv_font_t montserrat_sb_36;
extern const lv_font_t montserrat_sb_44;
extern const lv_font_t montserrat_sb_60;
extern const lv_font_t montserrat_sb_52;
extern const lv_font_t montserrat_sb_44;
extern const lv_font_t montserrat_sb_36;
extern const lv_font_t sourcecode_r_12;
extern const lv_font_t sourcecode_r_16;
extern const lv_font_t sourcecode_r_20;
extern const lv_font_t montserrat_sb_36;
extern const lv_font_t montserrat_r_36;

static const lv_style_prop_t transition_property_list[] = {
   (lv_style_prop_t)0x0021 /* background_opacity */,
   (lv_style_prop_t)0x0020 /* background_color */,
   (lv_style_prop_t)0x0068 /* transform_width */,
   (lv_style_prop_t)0x0069 /* transform_height */,
   (lv_style_prop_t)0x006B /* translate_y */,
   (lv_style_prop_t)0x006A /* translate_x */,
   (lv_style_prop_t)0x006C /* transform_zoom */,
   (lv_style_prop_t)0x006D /* transform_angle */,
   (lv_style_prop_t)0x0062 /* color_filter_opacity */,
   (lv_style_prop_t)0x0061 /* color_filter_descriptor */,
   (lv_style_prop_t)0x0060 /* opacity */
};

static const lv_style_prop_t drawer_transition_property_list[] = {
   (lv_style_prop_t)0x006B /* translate_y */,
   (lv_style_prop_t)0x006A /* translate_x */
};

static const lv_style_transition_dsc_t transition_normal = {
  .props = transition_property_list,
  .user_data = NULL,
  .path_xcb = lv_anim_path_linear,
  .time = 20,
  .delay = 0
};
static const lv_style_transition_dsc_t transition_slow = {
  .props = transition_property_list,
  .user_data = NULL,
  .path_xcb = lv_anim_path_linear,
  .time = 90,
  .delay = 0
};
static const lv_style_transition_dsc_t transition_slide_in = {
  .props = transition_property_list,
  .user_data = NULL,
  .path_xcb = lv_anim_path_ease_out,
  .time = 150,
  .delay = 0
};
static const lv_style_transition_dsc_t transition_slide_out = {
  .props = transition_property_list,
  .user_data = NULL,
  .path_xcb = lv_anim_path_ease_in,
  .time = 150,
  .delay = 0
};
static const lv_style_transition_dsc_t transition_ease_out = {
  .props = drawer_transition_property_list,
  .user_data = NULL,
  .path_xcb = lv_anim_path_ease_out,
  .time = 150,
  .delay = 0
};
static const lv_style_transition_dsc_t transition_ease_in = {
  .props = drawer_transition_property_list,
  .user_data = NULL,
  .path_xcb = lv_anim_path_ease_in,
  .time = 150,
  .delay = 0
};
static const lv_style_transition_dsc_t transition_delayed = {
  .props = transition_property_list,
  .user_data = NULL,
  .path_xcb = lv_anim_path_linear,
  .time = 20,
  .delay = 50
};
static const lv_style_transition_dsc_t transition_delayed_slow = {
  .props = transition_property_list,
  .user_data = NULL,
  .path_xcb = lv_anim_path_linear,
  .time = 90,
  .delay = 50
};
static const lv_style_transition_dsc_t transition_long_delayed = {
  .props = transition_property_list,
  .user_data = NULL,
  .path_xcb = lv_anim_path_linear,
  .time = 20,
  .delay = 800
};
static lv_color_t dark_filter_callback(const lv_color_filter_dsc_t * filter_descriptor, lv_color_t color, lv_opa_t opacity){
  LV_UNUSED(filter_descriptor);
  return lv_color_darken(color, opacity);;
}
static const lv_color_filter_dsc_t dark_filter = {
  .filter_cb = dark_filter_callback
};

static lv_color_t light_filter_callback(const lv_color_filter_dsc_t * filter_descriptor, lv_color_t color, lv_opa_t opacity){
  LV_UNUSED(filter_descriptor);
  return lv_color_lighten(color, opacity);;
}
static const lv_color_filter_dsc_t light_filter = {
  .filter_cb = light_filter_callback
};

static lv_color_t grey_filter_callback(const lv_color_filter_dsc_t * filter_descriptor, lv_color_t color, lv_opa_t opacity){
  LV_UNUSED(filter_descriptor);
  return lv_color_mix(lv_palette_lighten(LV_PALETTE_GREY, 2), color, opacity);;
}
static const lv_color_filter_dsc_t grey_filter = {
  .filter_cb = grey_filter_callback
};

static const lv_style_const_prop_t h1_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_60 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 / 2 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(100) } }
};

static LV_STYLE_CONST_INIT(h1_style, h1_const_list);

static const lv_style_const_prop_t h2_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_52 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 / 2 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(100) } }
};

static LV_STYLE_CONST_INIT(h2_style, h2_const_list);

static const lv_style_const_prop_t h3_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_44 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 / 2 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(100) } }
};

static LV_STYLE_CONST_INIT(h3_style, h3_const_list);

static const lv_style_const_prop_t h4_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_36 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 / 2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 / 2 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(100) } }
};

static LV_STYLE_CONST_INIT(h4_style, h4_const_list);

static const lv_style_const_prop_t container_const_list[] = {
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 0 } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } }
};

static LV_STYLE_CONST_INIT(container_style, container_const_list);

static const lv_style_const_prop_t naked_const_list[] = {
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 0 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 0 } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(naked_style, naked_const_list);

static const lv_style_const_prop_t text_font_small_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_r_28 } }
};

static LV_STYLE_CONST_INIT(text_font_small_style, text_font_small_const_list);

static const lv_style_const_prop_t text_font_large_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_r_36 } }
};

static LV_STYLE_CONST_INIT(text_font_large_style, text_font_large_const_list);

static const lv_style_const_prop_t row_const_list[] = {
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 0 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 0 } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 10 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_SIZE_CONTENT } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = LV_SIZE_CONTENT } }
};

static LV_STYLE_CONST_INIT(row_style, row_const_list);

static const lv_style_const_prop_t col_const_list[] = {
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 0 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 0 } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 10 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_SIZE_CONTENT } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = LV_SIZE_CONTENT } }
};

static LV_STYLE_CONST_INIT(col_style, col_const_list);

static const lv_style_const_prop_t bg_primary_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } }
};

static LV_STYLE_CONST_INIT(bg_primary_style, bg_primary_const_list);

static const lv_style_const_prop_t bg_secondary_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x30,0x38,0x46)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } }
};

static LV_STYLE_CONST_INIT(bg_secondary_style, bg_secondary_const_list);

static const lv_style_const_prop_t bg_warning_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xc1,0x07)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } }
};

static LV_STYLE_CONST_INIT(bg_warning_style, bg_warning_const_list);

static const lv_style_const_prop_t bg_info_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x0d,0xca,0xf0)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } }
};

static LV_STYLE_CONST_INIT(bg_info_style, bg_info_const_list);

static const lv_style_const_prop_t bg_danger_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0xdc,0x35,0x45)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } }
};

static LV_STYLE_CONST_INIT(bg_danger_style, bg_danger_const_list);

static const lv_style_const_prop_t bg_success_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x19,0x87,0x54)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } }
};

static LV_STYLE_CONST_INIT(bg_success_style, bg_success_const_list);

static const lv_style_const_prop_t bg_light_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0xbb,0xbb,0xbb)  } }
};

static LV_STYLE_CONST_INIT(bg_light_style, bg_light_const_list);

static const lv_style_const_prop_t bg_dark_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x44,0x44,0x44)  } }
};

static LV_STYLE_CONST_INIT(bg_dark_style, bg_dark_const_list);

static const lv_style_const_prop_t prompt_accept_btn_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(prompt_accept_btn_style, prompt_accept_btn_const_list);

static const lv_style_const_prop_t prompt_reject_btn_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0xdc,0x35,0x45)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0xdc,0x35,0x45)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(prompt_reject_btn_style, prompt_reject_btn_const_list);

static const lv_style_const_prop_t btn_primary_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(btn_primary_style, btn_primary_const_list);

static const lv_style_const_prop_t btn_secondary_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x30,0x38,0x46)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x30,0x38,0x46)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(btn_secondary_style, btn_secondary_const_list);

static const lv_style_const_prop_t btn_warning_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xc1,0x07)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xc1,0x07)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(btn_warning_style, btn_warning_const_list);

static const lv_style_const_prop_t btn_info_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x0d,0xca,0xf0)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x0d,0xca,0xf0)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(btn_info_style, btn_info_const_list);

static const lv_style_const_prop_t btn_danger_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0xdc,0x35,0x45)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0xdc,0x35,0x45)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(btn_danger_style, btn_danger_const_list);

static const lv_style_const_prop_t btn_success_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x19,0x87,0x54)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x19,0x87,0x54)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(btn_success_style, btn_success_const_list);

static const lv_style_const_prop_t btn_light_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0xbb,0xbb,0xbb)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0xbb,0xbb,0xbb)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } }
};

static LV_STYLE_CONST_INIT(btn_light_style, btn_light_const_list);

static const lv_style_const_prop_t btn_dark_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x44,0x44,0x44)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x44,0x44,0x44)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(btn_dark_style, btn_dark_const_list);

static const lv_style_const_prop_t btn_outline_default_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 - 4 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 - 4 } }
};

static LV_STYLE_CONST_INIT(btn_outline_default_style, btn_outline_default_const_list);

static const lv_style_const_prop_t btn_outline_primary_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 - 4 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 - 4 } }
};

static LV_STYLE_CONST_INIT(btn_outline_primary_style, btn_outline_primary_const_list);

static const lv_style_const_prop_t btn_outline_secondary_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x30,0x38,0x46)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x30,0x38,0x46)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 - 4 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 - 4 } }
};

static LV_STYLE_CONST_INIT(btn_outline_secondary_style, btn_outline_secondary_const_list);

static const lv_style_const_prop_t btn_outline_warning_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xc1,0x07)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xc1,0x07)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 - 4 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 - 4 } }
};

static LV_STYLE_CONST_INIT(btn_outline_warning_style, btn_outline_warning_const_list);

static const lv_style_const_prop_t btn_outline_info_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x0d,0xca,0xf0)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x0d,0xca,0xf0)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 - 4 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 - 4 } }
};

static LV_STYLE_CONST_INIT(btn_outline_info_style, btn_outline_info_const_list);

static const lv_style_const_prop_t btn_outline_danger_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0xdc,0x35,0x45)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xdc,0x35,0x45)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 - 4 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 - 4 } }
};

static LV_STYLE_CONST_INIT(btn_outline_danger_style, btn_outline_danger_const_list);

static const lv_style_const_prop_t btn_outline_success_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x19,0x87,0x54)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x19,0x87,0x54)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 - 4 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 - 4 } }
};

static LV_STYLE_CONST_INIT(btn_outline_success_style, btn_outline_success_const_list);

static const lv_style_const_prop_t btn_outline_light_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0xbb,0xbb,0xbb)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 - 4 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 - 4 } }
};

static LV_STYLE_CONST_INIT(btn_outline_light_style, btn_outline_light_const_list);

static const lv_style_const_prop_t btn_outline_dark_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x44,0x44,0x44)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 - 4 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 - 4 } }
};

static LV_STYLE_CONST_INIT(btn_outline_dark_style, btn_outline_dark_const_list);

static const lv_style_const_prop_t paragraph_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_r_32 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(100) } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 } }
};

static LV_STYLE_CONST_INIT(paragraph_style, paragraph_const_list);

static const lv_style_const_prop_t form_const_list[] = {
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *4 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 } }
};

static LV_STYLE_CONST_INIT(form_style, form_const_list);

static const lv_style_const_prop_t form_select_file_modal_const_list[] = {
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(80) } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = LV_PCT(80) } }
};

static LV_STYLE_CONST_INIT(form_select_file_modal_style, form_select_file_modal_const_list);

static const lv_style_const_prop_t form_row_const_list[] = {
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 10 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(100) } }
};

static LV_STYLE_CONST_INIT(form_row_style, form_row_const_list);

static const lv_style_const_prop_t form_col_const_list[] = {
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 10 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(80) } }
};

static LV_STYLE_CONST_INIT(form_col_style, form_col_const_list);

static const lv_style_const_prop_t form_label_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_36 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 } }
};

static LV_STYLE_CONST_INIT(form_label_style, form_label_const_list);

static const lv_style_const_prop_t form_field_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_r_36 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 /2 } }
};

static LV_STYLE_CONST_INIT(form_field_style, form_field_const_list);

static const lv_style_const_prop_t form_switch_const_list[] = {
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_RADIUS, .value = { .num = LV_RADIUS_CIRCLE } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = 128 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = 64 } }
};

static LV_STYLE_CONST_INIT(form_switch_style, form_switch_const_list);

static const lv_style_const_prop_t form_hint_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_28 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 / 2 *2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 / 2 *2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 / 2 *2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 / 2 *2 } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } }
};

static LV_STYLE_CONST_INIT(form_hint_style, form_hint_const_list);

static const lv_style_const_prop_t form_filesystem_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_r_36 } }
};

static LV_STYLE_CONST_INIT(form_filesystem_style, form_filesystem_const_list);

static const lv_style_const_prop_t form_dropdown_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_r_36 } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 /2 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 } }
};

static LV_STYLE_CONST_INIT(form_dropdown_style, form_dropdown_const_list);

static const lv_style_const_prop_t form_dropdown_list_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_r_36 } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 /2 } },
  { .prop = LV_STYLE_MAX_HEIGHT, .value = { .num = 500 } },
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 } }
};

static LV_STYLE_CONST_INIT(form_dropdown_list_style, form_dropdown_list_const_list);

static const lv_style_const_prop_t form_error_badge_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_36 } },
  { .prop = LV_STYLE_RADIUS, .value = { .num = LV_RADIUS_CIRCLE } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 0 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0xdc,0x35,0x45)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(form_error_badge_style, form_error_badge_const_list);

static const lv_style_const_prop_t text_light_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xbb,0xbb,0xbb)  } }
};

static LV_STYLE_CONST_INIT(text_light_style, text_light_const_list);

static const lv_style_const_prop_t text_dark_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x44,0x44,0x44)  } }
};

static LV_STYLE_CONST_INIT(text_dark_style, text_dark_const_list);

static const lv_style_const_prop_t text_primary_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(text_primary_style, text_primary_const_list);

static const lv_style_const_prop_t text_secondary_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(text_secondary_style, text_secondary_const_list);

static const lv_style_const_prop_t text_info_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(text_info_style, text_info_const_list);

static const lv_style_const_prop_t text_warning_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(text_warning_style, text_warning_const_list);

static const lv_style_const_prop_t text_danger_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(text_danger_style, text_danger_const_list);

static const lv_style_const_prop_t text_success_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(text_success_style, text_success_const_list);

static const lv_style_const_prop_t text_color_primary_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } }
};

static LV_STYLE_CONST_INIT(text_color_primary_style, text_color_primary_const_list);

static const lv_style_const_prop_t text_color_secondary_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x30,0x38,0x46)  } }
};

static LV_STYLE_CONST_INIT(text_color_secondary_style, text_color_secondary_const_list);

static const lv_style_const_prop_t text_color_info_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x0d,0xca,0xf0)  } }
};

static LV_STYLE_CONST_INIT(text_color_info_style, text_color_info_const_list);

static const lv_style_const_prop_t text_color_warning_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xc1,0x07)  } }
};

static LV_STYLE_CONST_INIT(text_color_warning_style, text_color_warning_const_list);

static const lv_style_const_prop_t text_color_danger_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xdc,0x35,0x45)  } }
};

static LV_STYLE_CONST_INIT(text_color_danger_style, text_color_danger_const_list);

static const lv_style_const_prop_t text_color_success_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x19,0x87,0x54)  } }
};

static LV_STYLE_CONST_INIT(text_color_success_style, text_color_success_const_list);

static const lv_style_const_prop_t btn_sm_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_28 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 *2 /2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *2 /2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 /2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 /2 } }
};

static LV_STYLE_CONST_INIT(btn_sm_style, btn_sm_const_list);

static const lv_style_const_prop_t btn_md_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_36 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 } }
};

static LV_STYLE_CONST_INIT(btn_md_style, btn_md_const_list);

static const lv_style_const_prop_t btn_lg_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_44 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 *2 *2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *2 *2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 *3/2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 *3/2 } }
};

static LV_STYLE_CONST_INIT(btn_lg_style, btn_lg_const_list);

static const lv_style_const_prop_t badge_const_list[] = {
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 / 2 *2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 / 2 *2 } },
  { .prop = LV_STYLE_RADIUS, .value = { .num = 8 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = LV_SIZE_CONTENT } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_SIZE_CONTENT } }
};

static LV_STYLE_CONST_INIT(badge_style, badge_const_list);

static const lv_style_const_prop_t rounded_pill_const_list[] = {
  { .prop = LV_STYLE_RADIUS, .value = { .num = 0x7fff } }
};

static LV_STYLE_CONST_INIT(rounded_pill_style, rounded_pill_const_list);

static const lv_style_const_prop_t badge_sm_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_28 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 *2 /2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *2 /2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 / 2 *2 /2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 / 2 *2 /2 } }
};

static LV_STYLE_CONST_INIT(badge_sm_style, badge_sm_const_list);

static const lv_style_const_prop_t badge_md_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_36 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 / 2 *2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 / 2 *2 } }
};

static LV_STYLE_CONST_INIT(badge_md_style, badge_md_const_list);

static const lv_style_const_prop_t badge_lg_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_44 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 *2 *2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *2 *2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 / 2 *2 *3/2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 / 2 *2 *3/2 } }
};

static LV_STYLE_CONST_INIT(badge_lg_style, badge_lg_const_list);

static const lv_style_const_prop_t screen_const_list[] = {
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 10 / 2 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 10 / 2 } }
};

static LV_STYLE_CONST_INIT(screen_style, screen_const_list);

static const lv_style_const_prop_t scrollbar_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_RADIUS, .value = { .num = 0x7fff } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 4 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 4 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = 12 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = 12 } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 0 } },
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_long_delayed } }
};

static LV_STYLE_CONST_INIT(scrollbar_style, scrollbar_const_list);

static const lv_style_const_prop_t scrollbar_scrolled_const_list[] = {
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 153 } },
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_normal } }
};

static LV_STYLE_CONST_INIT(scrollbar_scrolled_style, scrollbar_scrolled_const_list);

static const lv_style_const_prop_t slide_over_from_right_hidden_const_list[] = {
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_slide_out } },
  { .prop = LV_STYLE_TRANSLATE_X, .value = { .num = LV_PCT(100) } }
};

static LV_STYLE_CONST_INIT(slide_over_from_right_hidden_style, slide_over_from_right_hidden_const_list);

static const lv_style_const_prop_t slide_over_from_right_const_list[] = {
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_slide_in } },
  { .prop = LV_STYLE_TRANSLATE_X, .value = { .num = 0 } }
};

static LV_STYLE_CONST_INIT(slide_over_from_right_style, slide_over_from_right_const_list);

static const lv_style_const_prop_t drawer_ease_in_const_list[] = {
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_ease_in } }
};

static LV_STYLE_CONST_INIT(drawer_ease_in_style, drawer_ease_in_const_list);

static const lv_style_const_prop_t drawer_ease_out_const_list[] = {
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_ease_out } }
};

static LV_STYLE_CONST_INIT(drawer_ease_out_style, drawer_ease_out_const_list);

static const lv_style_const_prop_t modal_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(100) } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = LV_PCT(100) } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 0 } },
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_slow } }
};

static LV_STYLE_CONST_INIT(modal_style, modal_const_list);

static const lv_style_const_prop_t modal_enabled_const_list[] = {
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 204 } },
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_delayed_slow } }
};

static LV_STYLE_CONST_INIT(modal_enabled_style, modal_enabled_const_list);

static const lv_style_const_prop_t modal_content_const_list[] = {
  { .prop = LV_STYLE_OPA, .value = { .num = 0 } },
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_slow } }
};

static LV_STYLE_CONST_INIT(modal_content_style, modal_content_const_list);

static const lv_style_const_prop_t modal_content_enabled_const_list[] = {
  { .prop = LV_STYLE_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_TRANSLATE_Y, .value = { .num = 50 } },
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_delayed_slow } }
};

static LV_STYLE_CONST_INIT(modal_content_enabled_style, modal_content_enabled_const_list);

static const lv_style_const_prop_t card_const_list[] = {
  { .prop = LV_STYLE_RADIUS, .value = { .num = 8 *2 } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_BORDER_POST, .value = { .num = 1 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 10 } },
  { .prop = LV_STYLE_LINE_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_LINE_WIDTH, .value = { .num = 1 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = LV_SIZE_CONTENT } },
  { .prop = LV_STYLE_CLIP_CORNER, .value = { .num = 1 } }
};

static LV_STYLE_CONST_INIT(card_style, card_const_list);

static const lv_style_const_prop_t toast_const_list[] = {
  { .prop = LV_STYLE_RADIUS, .value = { .num = 8 *2 } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_BORDER_POST, .value = { .num = 1 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 10 } },
  { .prop = LV_STYLE_LINE_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_LINE_WIDTH, .value = { .num = 1 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = LV_SIZE_CONTENT } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(25) } },
  { .prop = LV_STYLE_CLIP_CORNER, .value = { .num = 1 } }
};

static LV_STYLE_CONST_INIT(toast_style, toast_const_list);

static const lv_style_const_prop_t toast_top_right_const_list[] = {
  { .prop = LV_STYLE_ALIGN, .value = { .num = 0x3 } },
  { .prop = LV_STYLE_X, .value = { .num = 40 * -1 } },
  { .prop = LV_STYLE_Y, .value = { .num = 40 } }
};

static LV_STYLE_CONST_INIT(toast_top_right_style, toast_top_right_const_list);

static const lv_style_const_prop_t toast_top_left_const_list[] = {
  { .prop = LV_STYLE_ALIGN, .value = { .num = 0x1 } },
  { .prop = LV_STYLE_X, .value = { .num = 40 } },
  { .prop = LV_STYLE_Y, .value = { .num = 40 } }
};

static LV_STYLE_CONST_INIT(toast_top_left_style, toast_top_left_const_list);

static const lv_style_const_prop_t toast_top_const_list[] = {
  { .prop = LV_STYLE_ALIGN, .value = { .num = 0x2 } },
  { .prop = LV_STYLE_Y, .value = { .num = 40 } }
};

static LV_STYLE_CONST_INIT(toast_top_style, toast_top_const_list);

static const lv_style_const_prop_t toast_bottom_right_const_list[] = {
  { .prop = LV_STYLE_ALIGN, .value = { .num = 0x6 } },
  { .prop = LV_STYLE_X, .value = { .num = 40 *-1 } },
  { .prop = LV_STYLE_Y, .value = { .num = 40 *-1 } }
};

static LV_STYLE_CONST_INIT(toast_bottom_right_style, toast_bottom_right_const_list);

static const lv_style_const_prop_t toast_bottom_left_const_list[] = {
  { .prop = LV_STYLE_ALIGN, .value = { .num = 0x4 } },
  { .prop = LV_STYLE_X, .value = { .num = 40 } },
  { .prop = LV_STYLE_Y, .value = { .num = 40 *-1 } }
};

static LV_STYLE_CONST_INIT(toast_bottom_left_style, toast_bottom_left_const_list);

static const lv_style_const_prop_t toast_bottom_const_list[] = {
  { .prop = LV_STYLE_ALIGN, .value = { .num = 0x5 } },
  { .prop = LV_STYLE_Y, .value = { .num = 40 *-1 } }
};

static LV_STYLE_CONST_INIT(toast_bottom_style, toast_bottom_const_list);

static const lv_style_const_prop_t toast_title_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_36 } }
};

static LV_STYLE_CONST_INIT(toast_title_style, toast_title_const_list);

static const lv_style_const_prop_t toast_messsage_const_list[] = {
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_r_36 } }
};

static LV_STYLE_CONST_INIT(toast_messsage_style, toast_messsage_const_list);

static const lv_style_const_prop_t list_group_const_list[] = {
  { .prop = LV_STYLE_RADIUS, .value = { .num = 8 *2 } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_BORDER_POST, .value = { .num = 1 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 10 } },
  { .prop = LV_STYLE_LINE_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_LINE_WIDTH, .value = { .num = 1 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = LV_SIZE_CONTENT } }
};

static LV_STYLE_CONST_INIT(list_group_style, list_group_const_list);

static const lv_style_const_prop_t list_group_flush_const_list[] = {
  { .prop = LV_STYLE_RADIUS, .value = { .num = 8 *2 } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_BORDER_POST, .value = { .num = 1 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 10 } },
  { .prop = LV_STYLE_LINE_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_LINE_WIDTH, .value = { .num = 1 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = LV_SIZE_CONTENT } }
};

static LV_STYLE_CONST_INIT(list_group_flush_style, list_group_flush_const_list);

static const lv_style_const_prop_t card_header_const_list[] = {
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 51 } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_BORDER_SIDE, .value = { .num = 0x1 } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(100) } },
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_44 } }
};

static LV_STYLE_CONST_INIT(card_header_style, card_header_const_list);

static const lv_style_const_prop_t primary_card_const_list[] = {
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(primary_card_style, primary_card_const_list);

static const lv_style_const_prop_t primary_card_header_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 127 } }
};

static LV_STYLE_CONST_INIT(primary_card_header_style, primary_card_header_const_list);

static const lv_style_const_prop_t primary_card_body_const_list[] = {
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 51 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } }
};

static LV_STYLE_CONST_INIT(primary_card_body_style, primary_card_body_const_list);

static const lv_style_const_prop_t primary_card_footer_const_list[] = {
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 127 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } }
};

static LV_STYLE_CONST_INIT(primary_card_footer_style, primary_card_footer_const_list);

static const lv_style_const_prop_t card_body_const_list[] = {
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(100) } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_r_32 } }
};

static LV_STYLE_CONST_INIT(card_body_style, card_body_const_list);

static const lv_style_const_prop_t card_footer_const_list[] = {
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 51 } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_BORDER_SIDE, .value = { .num = 0x2 } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(100) } }
};

static LV_STYLE_CONST_INIT(card_footer_style, card_footer_const_list);

static const lv_style_const_prop_t darker_const_list[] = {
  { .prop = LV_STYLE_COLOR_FILTER_DSC, .value = { .ptr = (void*)&dark_filter } },
  { .prop = LV_STYLE_COLOR_FILTER_OPA, .value = { .num = 40 } }
};

static LV_STYLE_CONST_INIT(darker_style, darker_const_list);

static const lv_style_const_prop_t hline_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = 2 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = LV_PCT(100) } }
};

static LV_STYLE_CONST_INIT(hline_style, hline_const_list);

static const lv_style_const_prop_t button_const_list[] = {
  { .prop = LV_STYLE_RADIUS, .value = { .num = 8 } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = LV_OPA_COVER } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_sb_36 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 3 } },
  { .prop = LV_STYLE_PAD_ROW, .value = { .num = 3 } }
};

static LV_STYLE_CONST_INIT(button_style, button_const_list);

static const lv_style_const_prop_t background_color_primary_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } }
};

static LV_STYLE_CONST_INIT(background_color_primary_style, background_color_primary_const_list);

static const lv_style_const_prop_t background_color_primary_muted_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } }
};

static LV_STYLE_CONST_INIT(background_color_primary_muted_style, background_color_primary_muted_const_list);

static const lv_style_const_prop_t background_color_secondary_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x30,0x38,0x46)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } }
};

static LV_STYLE_CONST_INIT(background_color_secondary_style, background_color_secondary_const_list);

static const lv_style_const_prop_t background_color_secondary_muted_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x30,0x38,0x46)  } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x30,0x38,0x46)  } },
  { .prop = LV_STYLE_OPA, .value = { .num = 51 } }
};

static LV_STYLE_CONST_INIT(background_color_secondary_muted_style, background_color_secondary_muted_const_list);

static const lv_style_const_prop_t background_color_grey_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x44,0x44,0x44)  } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 / 2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 / 2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 / 2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 / 2 } }
};

static LV_STYLE_CONST_INIT(background_color_grey_style, background_color_grey_const_list);

static const lv_style_const_prop_t background_color_white_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0xcc,0xcc,0xcc)  } },
  { .prop = LV_STYLE_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0x44,0x44,0x44)  } }
};

static LV_STYLE_CONST_INIT(background_color_white_style, background_color_white_const_list);

static const lv_style_const_prop_t pressed_const_list[] = {
  { .prop = LV_STYLE_COLOR_FILTER_DSC, .value = { .ptr = (void*)&dark_filter } },
  { .prop = LV_STYLE_COLOR_FILTER_OPA, .value = { .num = 60 } }
};

static LV_STYLE_CONST_INIT(pressed_style, pressed_const_list);

static const lv_style_const_prop_t disabled_const_list[] = {
  { .prop = LV_STYLE_COLOR_FILTER_DSC, .value = { .ptr = (void*)&light_filter } },
  { .prop = LV_STYLE_COLOR_FILTER_OPA, .value = { .num = 127 } }
};

static LV_STYLE_CONST_INIT(disabled_style, disabled_const_list);

static const lv_style_const_prop_t padding_zero_const_list[] = {
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 0 } }
};

static LV_STYLE_CONST_INIT(padding_zero_style, padding_zero_const_list);

static const lv_style_const_prop_t padding_tiny_const_list[] = {
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 / 3 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 / 3 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 / 3 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 / 3 } }
};

static LV_STYLE_CONST_INIT(padding_tiny_style, padding_tiny_const_list);

static const lv_style_const_prop_t padding_small_const_list[] = {
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 / 2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 / 2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 / 2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 / 2 } }
};

static LV_STYLE_CONST_INIT(padding_small_style, padding_small_const_list);

static const lv_style_const_prop_t padding_normal_const_list[] = {
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 } }
};

static LV_STYLE_CONST_INIT(padding_normal_style, padding_normal_const_list);

static const lv_style_const_prop_t padding_gap_const_list[] = {
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 } }
};

static LV_STYLE_CONST_INIT(padding_gap_style, padding_gap_const_list);

static const lv_style_const_prop_t line_space_large_const_list[] = {

};

static LV_STYLE_CONST_INIT(line_space_large_style, line_space_large_const_list);

static const lv_style_const_prop_t text_align_center_const_list[] = {
  { .prop = LV_STYLE_TEXT_ALIGN, .value = { .num = 0x2 } }
};

static LV_STYLE_CONST_INIT(text_align_center_style, text_align_center_const_list);

static const lv_style_const_prop_t outline_border_primary_const_list[] = {
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } }
};

static LV_STYLE_CONST_INIT(outline_border_primary_style, outline_border_primary_const_list);

static const lv_style_const_prop_t outline_border_secondary_const_list[] = {
  { .prop = LV_STYLE_OUTLINE_COLOR, .value = { .color = LV_COLOR_MAKE(0x30,0x38,0x46)  } },
  { .prop = LV_STYLE_OUTLINE_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_OUTLINE_PAD, .value = { .num = 4 } },
  { .prop = LV_STYLE_OUTLINE_OPA, .value = { .num = 127 } }
};

static LV_STYLE_CONST_INIT(outline_border_secondary_style, outline_border_secondary_const_list);

static const lv_style_const_prop_t circle_const_list[] = {
  { .prop = LV_STYLE_RADIUS, .value = { .num = LV_RADIUS_CIRCLE } }
};

static LV_STYLE_CONST_INIT(circle_style, circle_const_list);

static const lv_style_const_prop_t radius_none_const_list[] = {

};

static LV_STYLE_CONST_INIT(radius_none_style, radius_none_const_list);

static const lv_style_const_prop_t clip_corner_const_list[] = {
  { .prop = LV_STYLE_CLIP_CORNER, .value = { .num = 1 } }
};

static LV_STYLE_CONST_INIT(clip_corner_style, clip_corner_const_list);

static const lv_style_const_prop_t progress_bar_background_const_list[] = {
  { .prop = LV_STYLE_HEIGHT, .value = { .num = 20 } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_RADIUS, .value = { .num = 8 } }
};

static LV_STYLE_CONST_INIT(progress_bar_background_style, progress_bar_background_const_list);

static const lv_style_const_prop_t progress_bar_indicator_const_list[] = {
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } }
};

static LV_STYLE_CONST_INIT(progress_bar_indicator_style, progress_bar_indicator_const_list);

static const lv_style_const_prop_t grow_const_list[] = {
  { .prop = LV_STYLE_TRANSFORM_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_TRANSFORM_HEIGHT, .value = { .num = 4 } }
};

static LV_STYLE_CONST_INIT(grow_style, grow_const_list);

static const lv_style_const_prop_t shrink_const_list[] = {
  { .prop = LV_STYLE_TRANSFORM_WIDTH, .value = { .num = -4 } },
  { .prop = LV_STYLE_TRANSFORM_HEIGHT, .value = { .num = -4 } }
};

static LV_STYLE_CONST_INIT(shrink_style, shrink_const_list);

static const lv_style_const_prop_t transition_delayed_const_list[] = {
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_delayed } }
};

static LV_STYLE_CONST_INIT(transition_delayed_style, transition_delayed_const_list);

static const lv_style_const_prop_t transition_normal_const_list[] = {
  { .prop = LV_STYLE_TRANSITION, .value = { .ptr = (void*)&transition_normal } }
};

static LV_STYLE_CONST_INIT(transition_normal_style, transition_normal_const_list);

static const lv_style_const_prop_t animation_const_list[] = {
  { .prop = LV_STYLE_ANIM_TIME, .value = { .num = 200 } }
};

static LV_STYLE_CONST_INIT(animation_style, animation_const_list);

static const lv_style_const_prop_t knob_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 12 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 12 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 12 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 12 } },
  { .prop = LV_STYLE_RADIUS, .value = { .num = 0x7fff } }
};

static LV_STYLE_CONST_INIT(knob_style, knob_const_list);

static const lv_style_const_prop_t indicator_const_list[] = {

};

static LV_STYLE_CONST_INIT(indicator_style, indicator_const_list);

static const lv_style_const_prop_t arc_indicator_const_list[] = {
  { .prop = LV_STYLE_ARC_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_ARC_WIDTH, .value = { .num = 15 } },
  { .prop = LV_STYLE_ARC_ROUNDED, .value = { .num = 1 } }
};

static LV_STYLE_CONST_INIT(arc_indicator_style, arc_indicator_const_list);

static const lv_style_const_prop_t arc_indicator_primary_const_list[] = {
  { .prop = LV_STYLE_ARC_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } }
};

static LV_STYLE_CONST_INIT(arc_indicator_primary_style, arc_indicator_primary_const_list);

static const lv_style_const_prop_t chart_series_const_list[] = {
  { .prop = LV_STYLE_LINE_WIDTH, .value = { .num = 3 } },
  { .prop = LV_STYLE_RADIUS, .value = { .num = 3 } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = 8 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = 8 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 2 } }
};

static LV_STYLE_CONST_INIT(chart_series_style, chart_series_const_list);

static const lv_style_const_prop_t chart_indicator_const_list[] = {
  { .prop = LV_STYLE_RADIUS, .value = { .num = 0x7fff } },
  { .prop = LV_STYLE_WIDTH, .value = { .num = 8 } },
  { .prop = LV_STYLE_HEIGHT, .value = { .num = 8 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = LV_OPA_COVER } }
};

static LV_STYLE_CONST_INIT(chart_indicator_style, chart_indicator_const_list);

static const lv_style_const_prop_t chart_ticks_const_list[] = {

};

static LV_STYLE_CONST_INIT(chart_ticks_style, chart_ticks_const_list);

static const lv_style_const_prop_t chart_background_const_list[] = {
  { .prop = LV_STYLE_BORDER_POST, .value = { .num = 0 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 10 } },
  { .prop = LV_STYLE_LINE_COLOR, .value = { .color = LV_COLOR_MAKE(0x9e,0x9e,0x9e)  } }
};

static LV_STYLE_CONST_INIT(chart_background_style, chart_background_const_list);

static const lv_style_const_prop_t dropdown_list_const_list[] = {
  { .prop = LV_STYLE_MAX_HEIGHT, .value = { .num = 500 } }
};

static LV_STYLE_CONST_INIT(dropdown_list_style, dropdown_list_const_list);

static const lv_style_const_prop_t checkbox_marker_const_list[] = {
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_RADIUS, .value = { .num = 8 } }
};

static LV_STYLE_CONST_INIT(checkbox_marker_style, checkbox_marker_const_list);

static const lv_style_const_prop_t checkbox_marker_checked_const_list[] = {
  { .prop = LV_STYLE_BG_IMG_SRC, .value = { .ptr = (void*)LV_SYMBOL_OK } },
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xcc,0xcc,0xcc)  } },
  { .prop = LV_STYLE_TEXT_FONT, .value = { .ptr = (void*)&montserrat_r_28 } }
};

static LV_STYLE_CONST_INIT(checkbox_marker_checked_style, checkbox_marker_checked_const_list);

static const lv_style_const_prop_t switch_knob_const_list[] = {
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x1c,0x3a,0x87)  } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = -2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = -2 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = -2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = -2 } }
};

static LV_STYLE_CONST_INIT(switch_knob_style, switch_knob_const_list);

static const lv_style_const_prop_t line_const_list[] = {
  { .prop = LV_STYLE_LINE_WIDTH, .value = { .num = 1 } },
  { .prop = LV_STYLE_LINE_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } }
};

static LV_STYLE_CONST_INIT(line_style, line_const_list);

static const lv_style_const_prop_t table_cell_const_list[] = {
  { .prop = LV_STYLE_TEXT_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_BORDER_SIDE, .value = { .num = 0x1 } },
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } }
};

static LV_STYLE_CONST_INIT(table_cell_style, table_cell_const_list);

static const lv_style_const_prop_t meter_marker_const_list[] = {

};

static LV_STYLE_CONST_INIT(meter_marker_style, meter_marker_const_list);

static const lv_style_const_prop_t meter_indicator_const_list[] = {

};

static LV_STYLE_CONST_INIT(meter_indicator_style, meter_indicator_const_list);

static const lv_style_const_prop_t calendar_background_const_list[] = {

};

static LV_STYLE_CONST_INIT(calendar_background_style, calendar_background_const_list);

static const lv_style_const_prop_t calendar_day_const_list[] = {

};

static LV_STYLE_CONST_INIT(calendar_day_style, calendar_day_const_list);

static const lv_style_const_prop_t colorwheel_main_const_list[] = {
  { .prop = LV_STYLE_ARC_WIDTH, .value = { .num = 20 } }
};

static LV_STYLE_CONST_INIT(colorwheel_main_style, colorwheel_main_const_list);

static const lv_style_const_prop_t message_box_background_const_list[] = {

};

static LV_STYLE_CONST_INIT(message_box_background_style, message_box_background_const_list);

static const lv_style_const_prop_t message_box_button_background_const_list[] = {

};

static LV_STYLE_CONST_INIT(message_box_button_background_style, message_box_button_background_const_list);

static const lv_style_const_prop_t keyboard_button_background_const_list[] = {

};

static LV_STYLE_CONST_INIT(keyboard_button_background_style, keyboard_button_background_const_list);

static const lv_style_const_prop_t list_background_const_list[] = {
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 } }
};

static LV_STYLE_CONST_INIT(list_background_style, list_background_const_list);

static const lv_style_const_prop_t list_button_const_list[] = {
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0x66,0x66,0x66)  } },
  { .prop = LV_STYLE_BORDER_SIDE, .value = { .num = 0x1 } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0x22,0x22,0x22)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_RIGHT, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_TOP, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_BOTTOM, .value = { .num = 10 *2 } },
  { .prop = LV_STYLE_PAD_COLUMN, .value = { .num = 10 } }
};

static LV_STYLE_CONST_INIT(list_button_style, list_button_const_list);

static const lv_style_const_prop_t list_item_grow_const_list[] = {

};

static LV_STYLE_CONST_INIT(list_item_grow_style, list_item_grow_const_list);

static const lv_style_const_prop_t list_label_const_list[] = {
  { .prop = LV_STYLE_WIDTH, .value = { .num = 80 } }
};

static LV_STYLE_CONST_INIT(list_label_style, list_label_const_list);

static const lv_style_const_prop_t tab_background_focus_const_list[] = {

};

static LV_STYLE_CONST_INIT(tab_background_focus_style, tab_background_focus_const_list);

static const lv_style_const_prop_t text_area_cursor_const_list[] = {
  { .prop = LV_STYLE_BORDER_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_BORDER_SIDE, .value = { .num = LV_BORDER_SIDE_BOTTOM } },
  { .prop = LV_STYLE_BORDER_OPA, .value = { .num = 255 } },
  { .prop = LV_STYLE_BORDER_WIDTH, .value = { .num = 4 /2 } },
  { .prop = LV_STYLE_BG_COLOR, .value = { .color = LV_COLOR_MAKE(0xff,0xff,0xff)  } },
  { .prop = LV_STYLE_BG_OPA, .value = { .num = 20 } },
  { .prop = LV_STYLE_PAD_LEFT, .value = { .num = -1 } },
  { .prop = LV_STYLE_ANIM_TIME, .value = { .num = 400 } }
};

static LV_STYLE_CONST_INIT(text_area_cursor_style, text_area_cursor_const_list);

static const lv_style_const_prop_t text_area_placeholder_const_list[] = {

};

static LV_STYLE_CONST_INIT(text_area_placeholder_style, text_area_placeholder_const_list);

static const lv_style_const_prop_t tab_button_const_list[] = {

};

static LV_STYLE_CONST_INIT(tab_button_style, tab_button_const_list);

static const lv_style_const_prop_t led_const_list[] = {

};

static LV_STYLE_CONST_INIT(led_style, led_const_list);

static const lvgl_api_style_descriptor_t default_dark_medium_style_descriptor_list[] = {
  { .name = "h1", .style = &h1_style },
  { .name = "h2", .style = &h2_style },
  { .name = "h3", .style = &h3_style },
  { .name = "h4", .style = &h4_style },
  { .name = "container", .style = &container_style },
  { .name = "naked", .style = &naked_style },
  { .name = "text_font_small", .style = &text_font_small_style },
  { .name = "text_font_large", .style = &text_font_large_style },
  { .name = "row", .style = &row_style },
  { .name = "col", .style = &col_style },
  { .name = "bg_primary", .style = &bg_primary_style },
  { .name = "bg_secondary", .style = &bg_secondary_style },
  { .name = "bg_warning", .style = &bg_warning_style },
  { .name = "bg_info", .style = &bg_info_style },
  { .name = "bg_danger", .style = &bg_danger_style },
  { .name = "bg_success", .style = &bg_success_style },
  { .name = "bg_light", .style = &bg_light_style },
  { .name = "bg_dark", .style = &bg_dark_style },
  { .name = "prompt_accept_btn", .style = &prompt_accept_btn_style },
  { .name = "prompt_reject_btn", .style = &prompt_reject_btn_style },
  { .name = "btn_primary", .style = &btn_primary_style },
  { .name = "btn_secondary", .style = &btn_secondary_style },
  { .name = "btn_warning", .style = &btn_warning_style },
  { .name = "btn_info", .style = &btn_info_style },
  { .name = "btn_danger", .style = &btn_danger_style },
  { .name = "btn_success", .style = &btn_success_style },
  { .name = "btn_light", .style = &btn_light_style },
  { .name = "btn_dark", .style = &btn_dark_style },
  { .name = "btn_outline_default", .style = &btn_outline_default_style },
  { .name = "btn_outline_primary", .style = &btn_outline_primary_style },
  { .name = "btn_outline_secondary", .style = &btn_outline_secondary_style },
  { .name = "btn_outline_warning", .style = &btn_outline_warning_style },
  { .name = "btn_outline_info", .style = &btn_outline_info_style },
  { .name = "btn_outline_danger", .style = &btn_outline_danger_style },
  { .name = "btn_outline_success", .style = &btn_outline_success_style },
  { .name = "btn_outline_light", .style = &btn_outline_light_style },
  { .name = "btn_outline_dark", .style = &btn_outline_dark_style },
  { .name = "paragraph", .style = &paragraph_style },
  { .name = "form", .style = &form_style },
  { .name = "form_select_file_modal", .style = &form_select_file_modal_style },
  { .name = "form_row", .style = &form_row_style },
  { .name = "form_col", .style = &form_col_style },
  { .name = "form_label", .style = &form_label_style },
  { .name = "form_field", .style = &form_field_style },
  { .name = "form_switch", .style = &form_switch_style },
  { .name = "form_hint", .style = &form_hint_style },
  { .name = "form_filesystem", .style = &form_filesystem_style },
  { .name = "form_dropdown", .style = &form_dropdown_style },
  { .name = "form_dropdown_list", .style = &form_dropdown_list_style },
  { .name = "form_error_badge", .style = &form_error_badge_style },
  { .name = "text_light", .style = &text_light_style },
  { .name = "text_dark", .style = &text_dark_style },
  { .name = "text_primary", .style = &text_primary_style },
  { .name = "text_secondary", .style = &text_secondary_style },
  { .name = "text_info", .style = &text_info_style },
  { .name = "text_warning", .style = &text_warning_style },
  { .name = "text_danger", .style = &text_danger_style },
  { .name = "text_success", .style = &text_success_style },
  { .name = "text_color_primary", .style = &text_color_primary_style },
  { .name = "text_color_secondary", .style = &text_color_secondary_style },
  { .name = "text_color_info", .style = &text_color_info_style },
  { .name = "text_color_warning", .style = &text_color_warning_style },
  { .name = "text_color_danger", .style = &text_color_danger_style },
  { .name = "text_color_success", .style = &text_color_success_style },
  { .name = "btn_sm", .style = &btn_sm_style },
  { .name = "btn_md", .style = &btn_md_style },
  { .name = "btn_lg", .style = &btn_lg_style },
  { .name = "badge", .style = &badge_style },
  { .name = "rounded_pill", .style = &rounded_pill_style },
  { .name = "badge_sm", .style = &badge_sm_style },
  { .name = "badge_md", .style = &badge_md_style },
  { .name = "badge_lg", .style = &badge_lg_style },
  { .name = "slide_over_from_right_hidden", .style = &slide_over_from_right_hidden_style },
  { .name = "slide_over_from_right", .style = &slide_over_from_right_style },
  { .name = "drawer_ease_in", .style = &drawer_ease_in_style },
  { .name = "drawer_ease_out", .style = &drawer_ease_out_style },
  { .name = "modal", .style = &modal_style },
  { .name = "modal_enabled", .style = &modal_enabled_style },
  { .name = "modal_content", .style = &modal_content_style },
  { .name = "modal_content_enabled", .style = &modal_content_enabled_style },
  { .name = "card", .style = &card_style },
  { .name = "toast", .style = &toast_style },
  { .name = "toast_top_right", .style = &toast_top_right_style },
  { .name = "toast_top_left", .style = &toast_top_left_style },
  { .name = "toast_top", .style = &toast_top_style },
  { .name = "toast_bottom_right", .style = &toast_bottom_right_style },
  { .name = "toast_bottom_left", .style = &toast_bottom_left_style },
  { .name = "toast_bottom", .style = &toast_bottom_style },
  { .name = "toast_title", .style = &toast_title_style },
  { .name = "toast_messsage", .style = &toast_messsage_style },
  { .name = "list_group", .style = &list_group_style },
  { .name = "list_group_flush", .style = &list_group_flush_style },
  { .name = "card_header", .style = &card_header_style },
  { .name = "primary_card", .style = &primary_card_style },
  { .name = "primary_card_header", .style = &primary_card_header_style },
  { .name = "primary_card_body", .style = &primary_card_body_style },
  { .name = "primary_card_footer", .style = &primary_card_footer_style },
  { .name = "card_body", .style = &card_body_style },
  { .name = "card_footer", .style = &card_footer_style },
  { .name = "darker", .style = &darker_style },
  { .name = "hline", .style = &hline_style },
  { .name = "circle", .style = &circle_style }
};

void default_dark_medium_apply_callback(lv_theme_t * theme, lv_obj_t * object){
  if((lv_obj_get_parent(object) == NULL)){
    lv_obj_add_style(object, (lv_style_t*)&screen_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }
  if((lv_obj_check_type(object, &lv_obj_class)) && (lv_obj_check_type(lv_obj_get_parent(object), &lv_tabview_class))){
    return;
  }
  if((lv_obj_check_type(object, &lv_obj_class)) && (lv_obj_check_type(lv_obj_get_parent(lv_obj_get_parent(object)), &lv_tabview_class))){
    lv_obj_add_style(object, (lv_style_t*)&padding_normal_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }
  if(lv_obj_get_index(object) == 0 && (lv_obj_check_type(lv_obj_get_parent(object), &lv_win_class))){
    lv_obj_add_style(object, (lv_style_t*)&background_color_grey_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_tiny_style, LV_STATE_DEFAULT);
    return;
  }
  if(lv_obj_get_index(object) == 0 && (lv_obj_check_type(lv_obj_get_parent(object), &lv_win_class))){
    lv_obj_add_style(object, (lv_style_t*)&screen_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_normal_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }
  if((lv_obj_check_type(object, &lv_obj_class))){
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }
  if((lv_obj_check_type(object, &lv_btn_class))){
    lv_obj_add_style(object, (lv_style_t*)&button_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&transition_delayed_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&shrink_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&transition_normal_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&darker_style, LV_STATE_CHECKED);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED);
    return;
  }
  if((lv_obj_check_type(object, &lv_line_class))){
    return;
  }
  if((lv_obj_check_type(object, &lv_btnmatrix_class)) && (lv_obj_check_type(lv_obj_get_parent(object), &lv_msgbox_class))){
    lv_obj_add_style(object, (lv_style_t*)&button_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_CHECKED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_muted_style, LV_STATE_FOCUS_KEY|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_muted_style, LV_STATE_EDITED|LV_PART_ITEMS);
    return;
  }
  if((lv_obj_check_type(object, &lv_btnmatrix_class)) && (lv_obj_check_type(lv_obj_get_parent(object), &lv_tabview_class))){
    lv_obj_add_style(object, (lv_style_t*)&background_color_white_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&tab_background_focus_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_muted_style, LV_STATE_CHECKED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&tab_button_style, LV_STATE_CHECKED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&tab_background_focus_style, LV_STATE_FOCUS_KEY|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_secondary_style, LV_STATE_EDITED|LV_PART_ITEMS);
    return;
  }
  if((lv_obj_check_type(object, &lv_btnmatrix_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&button_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_CHECKED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_secondary_style, LV_STATE_EDITED|LV_PART_ITEMS);
    return;
  }
  if((lv_obj_check_type(object, &lv_bar_class))){
    lv_obj_add_style(object, (lv_style_t*)&progress_bar_background_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_secondary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    return;
  }
  if((lv_obj_check_type(object, &lv_slider_class))){
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_muted_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_secondary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&knob_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    return;
  }
  if((lv_obj_check_type(object, &lv_table_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_zero_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&radius_none_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_secondary_style, LV_STATE_EDITED);
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
  if((lv_obj_check_type(object, &lv_checkbox_class))){
    lv_obj_add_style(object, (lv_style_t*)&padding_gap_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&checkbox_marker_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&transition_delayed_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_CHECKED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&checkbox_marker_checked_style, LV_STATE_CHECKED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&shrink_style, LV_STATE_PRESSED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&transition_normal_style, LV_STATE_PRESSED|LV_PART_INDICATOR);
    return;
  }
  if((lv_obj_check_type(object, &lv_switch_class))){
    lv_obj_add_style(object, (lv_style_t*)&background_color_grey_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&transition_normal_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&bg_success_style, LV_STATE_CHECKED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_CHECKED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&transition_normal_style, LV_STATE_CHECKED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&knob_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    lv_obj_add_style(object, (lv_style_t*)&switch_knob_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_KNOB);
    return;
  }
  if((lv_obj_check_type(object, &lv_chart_class))){
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
  if((lv_obj_check_type(object, &lv_roller_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&animation_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&line_space_large_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&text_align_center_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_DEFAULT|LV_PART_SELECTED);
    return;
  }
  if((lv_obj_check_type(object, &lv_dropdown_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_small_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&transition_delayed_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&transition_normal_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&transition_normal_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    return;
  }
  if((lv_obj_check_type(object, &lv_dropdownlist_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&clip_corner_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&line_space_large_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&form_dropdown_list_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&background_color_white_style, LV_STATE_DEFAULT|LV_PART_SELECTED);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_CHECKED|LV_PART_SELECTED);
    lv_obj_add_style(object, (lv_style_t*)&text_primary_style, LV_STATE_CHECKED|LV_PART_SELECTED);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_SELECTED);
    return;
  }
  if((lv_obj_check_type(object, &lv_arc_class))){
    lv_obj_add_style(object, (lv_style_t*)&arc_indicator_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&arc_indicator_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&arc_indicator_primary_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&knob_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    return;
  }
  if((lv_obj_check_type(object, &lv_spinner_class))){
    lv_obj_add_style(object, (lv_style_t*)&arc_indicator_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&arc_indicator_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_add_style(object, (lv_style_t*)&arc_indicator_primary_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    return;
  }
  if((lv_obj_check_type(object, &lv_meter_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&circle_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&meter_indicator_style, LV_STATE_DEFAULT|LV_PART_INDICATOR);
    return;
  }
  if((lv_obj_check_type(object, &lv_textarea_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_small_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUSED);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_style, LV_STATE_EDITED);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&text_area_cursor_style, LV_STATE_FOCUSED|LV_PART_CURSOR);
    lv_obj_add_style(object, (lv_style_t*)&text_area_placeholder_style, LV_STATE_DEFAULT);
    return;
  }
  if((lv_obj_check_type(object, &lv_calendar_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&calendar_background_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&calendar_day_style, LV_STATE_DEFAULT|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&disabled_style, LV_STATE_DISABLED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_style, LV_STATE_EDITED);
    return;
  }
  if((lv_obj_check_type(object, &lv_calendar_header_arrow_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    return;
  }
  if((lv_obj_check_type(object, &lv_calendar_header_dropdown_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    return;
  }
  if((lv_obj_check_type(object, &lv_keyboard_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_small_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&outline_border_primary_style, LV_STATE_FOCUS_KEY);
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
  if((lv_obj_check_type(object, &lv_list_class))){
    lv_obj_add_style(object, (lv_style_t*)&list_background_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }
  if((lv_obj_check_type(object, &lv_list_text_class))){
    lv_obj_add_style(object, (lv_style_t*)&background_color_grey_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&list_item_grow_style, LV_STATE_DEFAULT);
    return;
  }
  if((lv_obj_check_type(object, &lv_list_btn_class))){
    lv_obj_add_style(object, (lv_style_t*)&list_button_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&list_item_grow_style, LV_STATE_FOCUS_KEY);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&list_item_grow_style, LV_STATE_PRESSED);
    lv_obj_add_style(object, (lv_style_t*)&pressed_style, LV_STATE_CHECKED);
    return;
  }
  if((lv_obj_check_type(object, &lv_msgbox_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&message_box_background_style, LV_STATE_DEFAULT);
    return;
  }
  if((lv_obj_check_type(object, &lv_spinbox_class))){
    lv_obj_add_style(object, (lv_style_t*)&card_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_small_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&background_color_grey_style, LV_STATE_CHECKED|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_muted_style, LV_STATE_FOCUS_KEY|LV_PART_ITEMS);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_DEFAULT|LV_PART_CURSOR);
    return;
  }
  if((lv_obj_check_type(object, &lv_tileview_class))){
    lv_obj_add_style(object, (lv_style_t*)&screen_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }
  if((lv_obj_check_type(object, &lv_tileview_tile_class))){
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_style, LV_STATE_DEFAULT|LV_PART_SCROLLBAR);
    lv_obj_add_style(object, (lv_style_t*)&scrollbar_scrolled_style, LV_STATE_SCROLLED|LV_PART_SCROLLBAR);
    return;
  }
  if((lv_obj_check_type(object, &lv_tabview_class))){
    lv_obj_add_style(object, (lv_style_t*)&screen_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_zero_style, LV_STATE_DEFAULT);
    return;
  }
  if((lv_obj_check_type(object, &lv_colorwheel_class))){
    lv_obj_add_style(object, (lv_style_t*)&colorwheel_main_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&padding_normal_style, LV_STATE_DEFAULT);
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    lv_obj_add_style(object, (lv_style_t*)&padding_normal_style, LV_STATE_DEFAULT|LV_PART_KNOB);
    return;
  }
  if((lv_obj_check_type(object, &lv_led_class))){
    lv_obj_add_style(object, (lv_style_t*)&led_style, LV_STATE_DEFAULT);
    return;
  }
  if(object->user_data && ((uint32_t*)(object->user_data))[0] == 0x6D697270){
    lv_obj_add_style(object, (lv_style_t*)&background_color_primary_style, LV_STATE_DEFAULT);
    return;
  }
  if(object->user_data && ((uint32_t*)(object->user_data))[0] == 0x6F636573){
    lv_obj_add_style(object, (lv_style_t*)&background_color_secondary_style, LV_STATE_DEFAULT);
    return;
  }
}

const lvgl_api_style_descriptor_t * default_dark_medium_get_style_callback(int offset){
  const size_t size = sizeof(default_dark_medium_style_descriptor_list) / sizeof(lvgl_api_style_descriptor_t);
  if(offset < size){
    return &(default_dark_medium_style_descriptor_list[offset]);
  }
  return NULL;
}

lv_theme_t themes_default_dark_medium = {
  .apply_cb = default_dark_medium_apply_callback,
  .parent = NULL,
  .user_data = (void*)default_dark_medium_get_style_callback,
  .disp = NULL,
  .color_primary = 0,
  .color_secondary = 0,
  .font_small = &montserrat_r_28,
  .font_normal = &montserrat_r_32,
  .font_large = &montserrat_r_36,
  .flags = 0
};

lv_theme_t * themes_default_dark_medium_initialize(lv_disp_t * disp, lv_theme_t * parent){
  themes_default_dark_medium.disp = disp;
  themes_default_dark_medium.parent = parent;
  return &themes_default_dark_medium;
}

