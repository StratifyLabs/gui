//
// Created by Tyler Gilbert on 11/25/21.
//

#ifndef GUI_VIEWOBJECT_HPP
#define GUI_VIEWOBJECT_HPP

#include <printer/YamlPrinter.hpp>
#include <thread/Mutex.hpp>
#include <thread/Thread.hpp>

#include <design/macros.hpp>

using namespace printer;

#include <lvgl.hpp>

#include "designlab/fonts/FontAwesomeIcons.hpp"
#include "model/Model.hpp"

class ViewObject {
public:

protected:
  static void go_back(lv_event_t*){
    auto model = ModelInScope();
    Screen::find_screen("default").load(
      model.instance.slide_right);
  }
};

#endif // GUI_VIEWOBJECT_HPP
