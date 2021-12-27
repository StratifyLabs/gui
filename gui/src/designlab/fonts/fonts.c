

#include "fonts.h"
#include <lvgl.h>
#include <lvgl_api.h>


extern const lv_font_t montserrat_r_28;
extern const lv_font_t montserrat_r_32;
extern const lv_font_t montserrat_r_36;
extern const lv_font_t sourcecode_r_12;
extern const lv_font_t sourcecode_r_16;
extern const lv_font_t sourcecode_r_20;
extern const lv_font_t montserrat_sb_28;
extern const lv_font_t montserrat_sb_36;
extern const lv_font_t montserrat_sb_44;
extern const lv_font_t montserrat_sb_52;
extern const lv_font_t montserrat_sb_60;


static const lvgl_api_font_descriptor_t lvgl_font_list[] = {
  { .name = "montserrat-r-28", .font = &montserrat_r_28},
  { .name = "montserrat-r-32", .font = &montserrat_r_32},
  { .name = "montserrat-r-36", .font = &montserrat_r_36},
  { .name = "sourcecode-r-12", .font = &sourcecode_r_12},
  { .name = "sourcecode-r-16", .font = &sourcecode_r_16},
  { .name = "sourcecode-r-20", .font = &sourcecode_r_20},
  { .name = "montserrat-sb-28", .font = &montserrat_sb_28},
  { .name = "montserrat-sb-36", .font = &montserrat_sb_36},
  { .name = "montserrat-sb-44", .font = &montserrat_sb_44},
  { .name = "montserrat-sb-52", .font = &montserrat_sb_52},
  { .name = "montserrat-sb-60", .font = &montserrat_sb_60}
};


static const lvgl_api_font_descriptor_t *get_font(int offset){
  const int count = sizeof(lvgl_font_list) / sizeof(lvgl_api_font_descriptor_t);
  if(offset >= 0 && offset < count){
    return lvgl_font_list + offset;
  }
  return NULL;
}
void fonts_initialize(){
  lvgl_api_set_font_callback(get_font);
}
