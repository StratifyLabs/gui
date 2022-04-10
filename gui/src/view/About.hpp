//
// Created by Tyler Gilbert on 11/25/21.
//

#ifndef GUI_ABOUT_HPP
#define GUI_ABOUT_HPP

#include "ViewObject.hpp"

class About : public ViewObject, public lvgl::ObjectAccess<About> {
public:
  static void setup(Generic generic){
    generic.add(About("about"));
  }


private:
  LVGL_OBJECT_ACCESS_DECLARE_CONSTRUCTOR(About);

  struct Names {
    DESIGN_DECLARE_NAME(dark_button);
    DESIGN_DECLARE_NAME(light_button);
  };

  static void update_theme(lv_event_t *e);
};

#endif // GUI_ABOUT_HPP
