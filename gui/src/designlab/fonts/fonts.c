

#include "fonts.h"


extern const lv_font_t montserrat_r_12;
extern const lv_font_t sourcecode_r_12;
extern const lv_font_t montserrat_sb_12;


const lvgl_api_font_descriptor_t lvgl_font_list[] = {
  { .name = "montserrat-r-12", .font = &montserrat_r_12},
  { .name = "sourcecode-r-12", .font = &sourcecode_r_12},
  { .name = "montserrat-sb-12", .font = &montserrat_sb_12}
};



#if defined __link

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

#endif


