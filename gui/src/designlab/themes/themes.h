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
default_light_medium_theme_initialize(lv_disp_t *disp, lv_theme_t *parent);

lv_theme_t *
default_dark_medium_theme_initialize(lv_disp_t *disp, lv_theme_t *parent);

lv_theme_t *
default_light_small_theme_initialize(lv_disp_t *disp, lv_theme_t *parent);

lv_theme_t *
default_dark_small_theme_initialize(lv_disp_t *disp, lv_theme_t *parent);

lv_theme_t *
default_light_large_theme_initialize(lv_disp_t *disp, lv_theme_t *parent);

lv_theme_t *
default_dark_large_theme_initialize(lv_disp_t *disp, lv_theme_t *parent);

#if defined __cplusplus
}
#endif

#endif // GUI_THEMES_H
