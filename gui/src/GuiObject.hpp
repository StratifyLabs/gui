//
// Created by Tyler Gilbert on 11/25/21.
//

#ifndef GUI_GUIOBJECT_HPP
#define GUI_GUIOBJECT_HPP

#include <printer/YamlPrinter.hpp>
#include <thread/Mutex.hpp>
#include <thread/Thread.hpp>

using namespace printer;

#include <lvgl.hpp>

#include "fonts/Icons.hpp"

class GuiObject {
public:
  static Printer &printer() { return model().printer; }

protected:
  struct Worker {
    thread::Thread thread;
    thread::Mutex mutex;
  };

  static constexpr u32 animation_period_milliseconds = 200;
  /*
   * The LvglAPI requires storing data in a singleton
   *
   * The `Model` class serves as a singleton for any
   * data. This allows us to access the data from
   * non-member functions that are used frequently
   * as callbacks (implemented as lambda functions)
   *
   *
   */
  class Model {
    API_SINGLETON(Model);

    // this can be used to create a thread to process
    // background tasks
    Worker check_update_worker;
    Worker github_worker
      ;
    Worker files_worker;

    Runtime * runtime = nullptr;

    // We will use this to print debug messages on the Terminal
    printer::YamlPrinter printer;

    Screen::Transition slide_right = {
      .animation = Screen::LoadAnimation::move_right,
      .period = animation_period_milliseconds * 1_milliseconds};

    Font button_font = Font::find(64).get_font();

    Style container_style = Style()
                              .set_vertical_padding(50)
                              .set_horizontal_padding(50)
                              .set_height(100_percent)
                              .set_width(100_percent);
  };

  static Model &model() { return Model::instance(); }

  static void go_back(lv_event_t*){
    Screen::find_screen("default").load(
      model().slide_right);
  }
};

#endif // GUI_GUIOBJECT_HPP
