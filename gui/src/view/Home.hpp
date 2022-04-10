//
// Created by Tyler Gilbert on 12/23/21.
//

#ifndef GUI_HOME_HPP
#define GUI_HOME_HPP

#include "ViewObject.hpp"

class Home : public ViewObject, public lvgl::ObjectAccess<Home> {
public:
  static void setup(Generic generic){
    generic.add(Home());
  }

private:
  LVGL_OBJECT_ACCESS_DECLARE_CONSTRUCTOR(Home);

  struct Names {
    DESIGN_DECLARE_NAME(container);
    DESIGN_DECLARE_NAME(column);

  };
  static void action_card_clicked(lv_event_t * e);
};

#endif // GUI_HOME_HPP
