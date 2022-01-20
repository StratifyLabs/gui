//
// Created by Tyler Gilbert on 12/23/21.
//

#ifndef GUI_MODEL_HPP
#define GUI_MODEL_HPP

#include <lvgl/Theme.hpp>
#include <lvgl/Runtime.hpp>
#include <lvgl/Screen.hpp>
#include <printer.hpp>
#include <design/Worker.hpp>

struct Model {
  struct Names {
    static constexpr auto about_screen_name = "About";
    static constexpr auto github_screen_name = "Github";
    static constexpr auto files_screen_name = "Files";
  };

  class Scope : public design::ModelScope {
  public:
    Scope() : design::ModelScope(Model::instance().model_scope_options) {}
  };

  API_SINGLETON(Model);

  static constexpr u32 animation_period_milliseconds = 80;

  lvgl::Theme light_theme;
  lvgl::Theme dark_theme;

  bool is_dark_theme = true;
  bool is_theme_updated = false;

  lvgl::Screen about_screen = lvgl::Screen(Names::about_screen_name);
  lvgl::Screen github_screen = lvgl::Screen(Names::github_screen_name);
  lvgl::Screen files_screen = lvgl::Screen(Names::files_screen_name);
  lvgl::Screen home_screen = lvgl::Screen((lv_obj_t*)nullptr);

  // this can be used to create a thread to process
  // background tasks
  lvgl::Runtime * runtime = nullptr;

  // We will use this to print debug messages on the Terminal
  printer::YamlPrinter printer;

  lvgl::Screen::Transition slide_right = {
    .animation = lvgl::Screen::LoadAnimation::move_right,
    .period = animation_period_milliseconds * 1_milliseconds};

  lvgl::Screen::Transition slide_left = {
    .animation = lvgl::Screen::LoadAnimation::move_left,
    .period = animation_period_milliseconds * 1_milliseconds};

  lvgl::Font button_font = lvgl::Font::find(48).get_font();

private:
  friend Scope;
  friend class ModelAccess;
  design::ModelScope::Construct model_scope_options;
};

class ModelAccess : public api::ExecutionContext{
public:

  static Model &model() {
    // make sure the caller has locked the model
    Model &result = Model::instance();
    API_ASSERT(result.model_scope_options.is_available());
    return Model::instance();
  }

  static Printer & printer(){
    return model().printer;
  }

};

#endif // GUI_MODEL_HPP
