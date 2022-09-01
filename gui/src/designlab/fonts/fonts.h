#ifndef DESIGNLAB_FONTS_H_
#define DESIGNLAB_FONTS_H_


#include <lvgl_api.h>

#if defined __cplusplus
extern "C" {
#endif

const lvgl_api_font_descriptor_t *fonts_get_font(int offset);
#if defined __link
void fonts_initialize();
#else
extern static const lvgl_api_font_descriptor_t fonts_list[3];
#endif

#if defined __cplusplus
}
#endif

#endif // DESIGNLAB_FONTS_H_

