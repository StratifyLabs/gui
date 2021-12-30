//
// Created by Tyler Gilbert on 11/25/21.
//

#ifndef GUI_FILES_HPP
#define GUI_FILES_HPP

#include "ViewObject.hpp"

class Files : public ViewObject {
public:
  static void setup(Generic container);

private:
  struct Names {
    DESIGN_DECLARE_NAME(select_file);
  };
  static void entered(lv_event_t*e);
};

#endif // GUI_FILES_HPP
