//
// Created by Tyler Gilbert on 12/26/21.
//

#ifndef GUI_SRC_DESIGNLAB_THEMES_THEMES_H
#define GUI_SRC_DESIGNLAB_THEMES_THEMES_H

#if defined __cplusplus
extern "C" {
#endif

#include <lvgl.h>
#include <lvgl_api.h>

typedef struct {
  const lvgl_api_style_descriptor_t  * (*get_style_callback)(int);
} design_api_theme_user_data_t;

lv_theme_t* lvgl_small_dark_theme_initialize(lv_disp_t * disp, lv_theme_t * parent);
lv_theme_t* lvgl_small_light_theme_initialize(lv_disp_t * disp, lv_theme_t * parent);


#if defined __cplusplus
}
#endif

#endif // GUI_SRC_DESIGNLAB_THEMES_THEMES_H
