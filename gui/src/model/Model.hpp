//
// Created by Tyler Gilbert on 12/23/21.
//

#ifndef GUI_MODEL_HPP
#define GUI_MODEL_HPP

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

  static constexpr u32 animation_period_milliseconds = 200;

  lvgl::Theme light_theme;
  lvgl::Theme dark_theme;

  Screen about_screen = Screen(Names::about_screen_name);
  Screen github_screen = Screen(Names::github_screen_name);
  Screen files_screen = Screen(Names::files_screen_name);

  // this can be used to create a thread to process
  // background tasks
  design::Worker check_update_worker;
  design::Worker github_worker;
  design::Worker files_worker;

  Runtime * runtime = nullptr;

  // We will use this to print debug messages on the Terminal
  printer::YamlPrinter printer;

  Screen::Transition slide_right = {
    .animation = Screen::LoadAnimation::move_right,
    .period = animation_period_milliseconds * 1_milliseconds};

  Font button_font = Font::find(48).get_font();

  Style container_style = Style()
                            .set_vertical_padding(50)
                            .set_horizontal_padding(50)
                            .set_height(100_percent)
                            .set_width(100_percent);

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
