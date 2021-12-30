//
// Created by Tyler Gilbert on 11/25/21.
//

#ifndef GUI_ABOUT_HPP
#define GUI_ABOUT_HPP

#include "ViewObject.hpp"

class About : public ViewObject {
public:
  static void setup(Generic generic);


private:
  struct Names {
    DESIGN_DECLARE_NAME(dark_button);
    DESIGN_DECLARE_NAME(light_button);
  };

  static void update_theme(lv_event_t *e);
};

#endif // GUI_ABOUT_HPP
