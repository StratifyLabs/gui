

#include "fonts.h"


extern const lv_font_t montserrat_r_12;
extern const lv_font_t sourcecode_r_12;
extern const lv_font_t montserrat_sb_12;


static const lvgl_api_font_descriptor_t fonts_list[3] = {
  { .name = "montserrat-r-12", .font = &montserrat_r_12},
  { .name = "sourcecode-r-12", .font = &sourcecode_r_12},
  { .name = "montserrat-sb-12", .font = &montserrat_sb_12}
};


const lvgl_api_font_descriptor_t *fonts_get_font(int offset){
  const int count = sizeof(fonts_list) / sizeof(lvgl_api_font_descriptor_t);
  if(offset >= 0 && offset < count){
    return fonts_list + offset;
  }
  return NULL;
}
void fonts_initialize(){

#if defined __link
  lvgl_api_set_font_callback(fonts_get_font);
#endif

}
