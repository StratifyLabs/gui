//
// Created by Tyler Gilbert on 11/25/21.
//

#ifndef GUI_ABOUT_HPP
#define GUI_ABOUT_HPP

#include "ViewObject.hpp"

class About : public lvgl::ObjectAccess<About> {
public:
  static void setup(Generic generic){
    generic.add(About("about"));
  }
private:
  LVGL_OBJECT_ACCESS_DECLARE_CONSTRUCTOR(About);
};

#endif // GUI_ABOUT_HPP
