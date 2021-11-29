//
// Created by Tyler Gilbert on 11/28/21.
//

#ifndef GUI_THEMES_H
#define GUI_THEMES_H

#if defined __cplusplus
extern "C" {
#endif

#include <lvgl.h>

lv_theme_t* dark_theme_initialize(lv_disp_t * disp, lv_theme_t * parent);

#if defined __cplusplus
}
#endif

#endif // GUI_THEMES_H
