#ifndef DESIGNLAB_FONTS_H_
#define DESIGNLAB_FONTS_H_


#include <lvgl_api.h>

#if defined __cplusplus
extern "C" {
#endif

#if defined __link
void fonts_initialize();
#else
extern const lvgl_api_font_descriptor_t lvgl_font_list[11];
#endif

#if defined __cplusplus
}
#endif

#endif // DESIGNLAB_FONTS_H_

