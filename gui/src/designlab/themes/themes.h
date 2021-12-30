//
// Created by Tyler Gilbert on 12/30/21.
//

#ifndef GUI_THEMES_H
#define GUI_THEMES_H

#include <lvgl.h>
#include <lvgl_api.h>

#if defined __cplusplus
extern "C" {
#endif


lv_theme_t *
lvgl_small_dark_theme_initialize(lv_disp_t *disp, lv_theme_t *parent);

lv_theme_t *
lvgl_small_light_theme_initialize(lv_disp_t *disp, lv_theme_t *parent);

#if defined __cplusplus
}
#endif

#endif // GUI_THEMES_H
