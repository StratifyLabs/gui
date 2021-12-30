//
// Created by Tyler Gilbert on 12/23/21.
//

#ifndef GUI_HOME_HPP
#define GUI_HOME_HPP

#include "ViewObject.hpp"

class Home : public ViewObject {
public:
  static void configure(Generic generic);

private:
  struct Names {
    DESIGN_DECLARE_NAME(container);
    DESIGN_DECLARE_NAME(column);

  };
  static void action_card_clicked(lv_event_t * e);
};

#endif // GUI_HOME_HPP
