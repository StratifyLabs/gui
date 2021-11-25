#include <lvgl.h>
#include <lvgl_api.h>

extern const lv_font_t montserrat_r_8;
extern const lv_font_t montserrat_r_12;
extern const lv_font_t montserrat_r_16;
extern const lv_font_t montserrat_r_20;
extern const lv_font_t montserrat_r_24;
extern const lv_font_t montserrat_r_28;
extern const lv_font_t montserrat_r_32;
extern const lv_font_t montserrat_r_36;
extern const lv_font_t montserrat_r_40;
extern const lv_font_t montserrat_r_44;
extern const lv_font_t montserrat_r_48;
extern const lv_font_t montserrat_r_52;
extern const lv_font_t montserrat_r_56;
extern const lv_font_t montserrat_r_60;
extern const lv_font_t montserrat_r_64;
extern const lv_font_t montserrat_r_68;
extern const lv_font_t montserrat_r_72;

extern const lv_font_t montserrat_i_8;
extern const lv_font_t montserrat_i_12;
extern const lv_font_t montserrat_i_16;
extern const lv_font_t montserrat_i_20;
extern const lv_font_t montserrat_i_24;
extern const lv_font_t montserrat_i_28;
extern const lv_font_t montserrat_i_32;
extern const lv_font_t montserrat_i_36;
extern const lv_font_t montserrat_i_40;
extern const lv_font_t montserrat_i_44;
extern const lv_font_t montserrat_i_48;
extern const lv_font_t montserrat_i_52;
extern const lv_font_t montserrat_i_56;
extern const lv_font_t montserrat_i_60;
extern const lv_font_t montserrat_i_64;
extern const lv_font_t montserrat_i_68;
extern const lv_font_t montserrat_i_72;

extern const lv_font_t montserrat_i_72;
extern const lv_font_t montserrat_l_12;
extern const lv_font_t montserrat_l_8;
extern const lv_font_t montserrat_l_16;
extern const lv_font_t montserrat_l_20;
extern const lv_font_t montserrat_l_24;
extern const lv_font_t montserrat_l_28;
extern const lv_font_t montserrat_l_32;
extern const lv_font_t montserrat_l_36;
extern const lv_font_t montserrat_l_40;
extern const lv_font_t montserrat_l_44;
extern const lv_font_t montserrat_l_48;
extern const lv_font_t montserrat_l_52;
extern const lv_font_t montserrat_l_56;
extern const lv_font_t montserrat_l_60;
extern const lv_font_t montserrat_l_64;
extern const lv_font_t montserrat_l_68;
extern const lv_font_t montserrat_l_72;

extern const lv_font_t montserrat_sb_8;
extern const lv_font_t montserrat_sb_12;
extern const lv_font_t montserrat_sb_16;
extern const lv_font_t montserrat_sb_20;
extern const lv_font_t montserrat_sb_24;
extern const lv_font_t montserrat_sb_28;
extern const lv_font_t montserrat_sb_32;
extern const lv_font_t montserrat_sb_36;
extern const lv_font_t montserrat_sb_40;
extern const lv_font_t montserrat_sb_44;
extern const lv_font_t montserrat_sb_48;
extern const lv_font_t montserrat_sb_52;
extern const lv_font_t montserrat_sb_56;
extern const lv_font_t montserrat_sb_60;
extern const lv_font_t montserrat_sb_64;
extern const lv_font_t montserrat_sb_68;
extern const lv_font_t montserrat_sb_72;

extern const lv_font_t sourcecode_r_8;
extern const lv_font_t sourcecode_r_12;
extern const lv_font_t sourcecode_r_16;
extern const lv_font_t sourcecode_r_20;
extern const lv_font_t sourcecode_r_24;
extern const lv_font_t sourcecode_r_28;
extern const lv_font_t sourcecode_r_32;
extern const lv_font_t sourcecode_r_36;
extern const lv_font_t sourcecode_r_40;
extern const lv_font_t sourcecode_r_44;
extern const lv_font_t sourcecode_r_48;
extern const lv_font_t sourcecode_r_52;
extern const lv_font_t sourcecode_r_56;
extern const lv_font_t sourcecode_r_60;
extern const lv_font_t sourcecode_r_64;
extern const lv_font_t sourcecode_r_68;
extern const lv_font_t sourcecode_r_72;

static const lvgl_api_font_descriptor_t lvgl_font_list[] = {
  {.name = "montserrat-r-8", .font = &montserrat_r_8},
  {.name = "montserrat-r-12", .font = &montserrat_r_12},
  {.name = "montserrat-r-16", .font = &montserrat_r_16},
  {.name = "montserrat-r-20", .font = &montserrat_r_20},
  {.name = "montserrat-r-24", .font = &montserrat_r_24},
  {.name = "montserrat-r-28", .font = &montserrat_r_28},
  {.name = "montserrat-r-32", .font = &montserrat_r_32},
  {.name = "montserrat-r-36", .font = &montserrat_r_36},
  {.name = "montserrat-r-40", .font = &montserrat_r_40},
  {.name = "montserrat-r-44", .font = &montserrat_r_44},
  {.name = "montserrat-r-48", .font = &montserrat_r_48},
  {.name = "montserrat-r-52", .font = &montserrat_r_52},
  {.name = "montserrat-r-56", .font = &montserrat_r_56},
  {.name = "montserrat-r-60", .font = &montserrat_r_60},
  {.name = "montserrat-r-64", .font = &montserrat_r_64},
  {.name = "montserrat-r-68", .font = &montserrat_r_68},
  {.name = "montserrat-r-72", .font = &montserrat_r_72},
  {.name = "montserrat-i-8", .font = &montserrat_i_8},
  {.name = "montserrat-i-12", .font = &montserrat_i_12},
  {.name = "montserrat-i-16", .font = &montserrat_i_16},
  {.name = "montserrat-i-20", .font = &montserrat_i_20},
  {.name = "montserrat-i-24", .font = &montserrat_i_24},
  {.name = "montserrat-i-28", .font = &montserrat_i_28},
  {.name = "montserrat-i-32", .font = &montserrat_i_32},
  {.name = "montserrat-i-36", .font = &montserrat_i_36},
  {.name = "montserrat-i-40", .font = &montserrat_i_40},
  {.name = "montserrat-i-44", .font = &montserrat_i_44},
  {.name = "montserrat-i-48", .font = &montserrat_i_48},
  {.name = "montserrat-i-52", .font = &montserrat_i_52},
  {.name = "montserrat-i-56", .font = &montserrat_i_56},
  {.name = "montserrat-i-60", .font = &montserrat_i_60},
  {.name = "montserrat-i-64", .font = &montserrat_i_64},
  {.name = "montserrat-i-68", .font = &montserrat_i_68},
  {.name = "montserrat-i-72", .font = &montserrat_i_72},
  {.name = "montserrat-l-8", .font = &montserrat_l_8},
  {.name = "montserrat-l-12", .font = &montserrat_l_12},
  {.name = "montserrat-l-16", .font = &montserrat_l_16},
  {.name = "montserrat-l-20", .font = &montserrat_l_20},
  {.name = "montserrat-l-24", .font = &montserrat_l_24},
  {.name = "montserrat-l-28", .font = &montserrat_l_28},
  {.name = "montserrat-l-32", .font = &montserrat_l_32},
  {.name = "montserrat-l-36", .font = &montserrat_l_36},
  {.name = "montserrat-l-40", .font = &montserrat_l_40},
  {.name = "montserrat-l-44", .font = &montserrat_l_44},
  {.name = "montserrat-l-48", .font = &montserrat_l_48},
  {.name = "montserrat-l-52", .font = &montserrat_l_52},
  {.name = "montserrat-l-56", .font = &montserrat_l_56},
  {.name = "montserrat-l-60", .font = &montserrat_l_60},
  {.name = "montserrat-l-64", .font = &montserrat_l_64},
  {.name = "montserrat-l-68", .font = &montserrat_l_68},
  {.name = "montserrat-l-72", .font = &montserrat_l_72},
  {.name = "montserrat-sb-8", .font = &montserrat_sb_8},
  {.name = "montserrat-sb-12", .font = &montserrat_sb_12},
  {.name = "montserrat-sb-16", .font = &montserrat_sb_16},
  {.name = "montserrat-sb-20", .font = &montserrat_sb_20},
  {.name = "montserrat-sb-24", .font = &montserrat_sb_24},
  {.name = "montserrat-sb-28", .font = &montserrat_sb_28},
  {.name = "montserrat-sb-32", .font = &montserrat_sb_32},
  {.name = "montserrat-sb-36", .font = &montserrat_sb_36},
  {.name = "montserrat-sb-40", .font = &montserrat_sb_40},
  {.name = "montserrat-sb-44", .font = &montserrat_sb_44},
  {.name = "montserrat-sb-48", .font = &montserrat_sb_48},
  {.name = "montserrat-sb-52", .font = &montserrat_sb_52},
  {.name = "montserrat-sb-56", .font = &montserrat_sb_56},
  {.name = "montserrat-sb-60", .font = &montserrat_sb_60},
  {.name = "montserrat-sb-64", .font = &montserrat_sb_64},
  {.name = "montserrat-sb-68", .font = &montserrat_sb_68},
  {.name = "montserrat-sb-72", .font = &montserrat_sb_72},
  {.name = "sourcecode-r-8", .font = &sourcecode_r_8},
  {.name = "sourcecode-r-12", .font = &sourcecode_r_12},
  {.name = "sourcecode-r-16", .font = &sourcecode_r_16},
  {.name = "sourcecode-r-20", .font = &sourcecode_r_20},
  {.name = "sourcecode-r-24", .font = &sourcecode_r_24},
  {.name = "sourcecode-r-28", .font = &sourcecode_r_28},
  {.name = "sourcecode-r-32", .font = &sourcecode_r_32},
  {.name = "sourcecode-r-36", .font = &sourcecode_r_36},
  {.name = "sourcecode-r-40", .font = &sourcecode_r_40},
  {.name = "sourcecode-r-44", .font = &sourcecode_r_44},
  {.name = "sourcecode-r-48", .font = &sourcecode_r_48},
  {.name = "sourcecode-r-52", .font = &sourcecode_r_52},
  {.name = "sourcecode-r-56", .font = &sourcecode_r_56},
  {.name = "sourcecode-r-60", .font = &sourcecode_r_60},
  {.name = "sourcecode-r-64", .font = &sourcecode_r_64},
  {.name = "sourcecode-r-68", .font = &sourcecode_r_68},
  {.name = "sourcecode-r-72", .font = &sourcecode_r_72},

};

static const lvgl_api_font_descriptor_t *get_font(int offset) {
  const int count = sizeof(lvgl_font_list) / sizeof(lvgl_api_font_descriptor_t);
  if (offset >= 0 && offset < count) {
    return lvgl_font_list + offset;
  }
  return NULL;
}

void fonts_initialize() { lvgl_api_set_font_callback(get_font); }
