

#include "themes.h"




extern const lv_theme_t themes_default_dark_small;
extern const lv_theme_t themes_default_light_small;
extern const lv_theme_t themes_default_dark_medium;
extern const lv_theme_t themes_default_light_medium;
extern const lv_theme_t themes_default_dark_highdpi;
extern const lv_theme_t themes_default_light_highdpi;


static const lvgl_api_theme_descriptor_t themes_list[6] = {
  { .name = "default-dark-small", .theme = &themes_default_dark_small},
  { .name = "default-light-small", .theme = &themes_default_light_small},
  { .name = "default-dark-medium", .theme = &themes_default_dark_medium},
  { .name = "default-light-medium", .theme = &themes_default_light_medium},
  { .name = "default-dark-highdpi", .theme = &themes_default_dark_highdpi},
  { .name = "default-light-highdpi", .theme = &themes_default_light_highdpi}
};


const lvgl_api_theme_descriptor_t *themes_get_theme(int offset){
  const int count = sizeof(themes_list) / sizeof(lvgl_api_theme_descriptor_t);
  if(offset >= 0 && offset < count){
    return themes_list + offset;
  }
  return NULL;
}
extern lv_theme_t * themes_default_dark_small_initialize(lv_disp_t * disp, lv_theme_t * parent);
extern lv_theme_t * themes_default_light_small_initialize(lv_disp_t * disp, lv_theme_t * parent);
extern lv_theme_t * themes_default_dark_medium_initialize(lv_disp_t * disp, lv_theme_t * parent);
extern lv_theme_t * themes_default_light_medium_initialize(lv_disp_t * disp, lv_theme_t * parent);
extern lv_theme_t * themes_default_dark_highdpi_initialize(lv_disp_t * disp, lv_theme_t * parent);
extern lv_theme_t * themes_default_light_highdpi_initialize(lv_disp_t * disp, lv_theme_t * parent);

void themes_initialize(){
#if defined __link
  lvgl_api_set_theme_callback(themes_get_theme);
#endif

  themes_default_dark_small_initialize(lv_disp_get_default(), NULL);
  themes_default_light_small_initialize(lv_disp_get_default(), NULL);
  themes_default_dark_medium_initialize(lv_disp_get_default(), NULL);
  themes_default_light_medium_initialize(lv_disp_get_default(), NULL);
  themes_default_dark_highdpi_initialize(lv_disp_get_default(), NULL);
  themes_default_light_highdpi_initialize(lv_disp_get_default(), NULL);
}

