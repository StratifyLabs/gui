//
// Created by Tyler Gilbert on 12/23/21.
//

#include <design.hpp>

#include "Home.hpp"

void Home::configure(Generic generic) {
  // The current screen is the "default" screen
  // it is automatically created by lvgl

  static const auto button_style
    = Style().fill_width().set_height(20_percent).set_border_width(20);

  static auto setup_button =
    [](Button button, const char *icon, const char *screen_name, Color color) {
      button.add_style(button_style)
        .set_horizontal_padding(20)
        .add_style(Row::get_style())
        .add_style(Row::get_style())
        .add(Label().set_text_as_static(icon).set_right_padding(20))
        .add(Label().set_text_as_static(screen_name).set_flex_grow())
        .add(Label().set_text_as_static(icons::fa::chevron_right_solid));
    };

  static auto slide_left = Screen::Transition(
    {.animation = Screen::LoadAnimation::move_left,
     .period = Model::animation_period_milliseconds * 1_milliseconds});

  // build the GUI using the LvglAPI
  generic.clear_flag(Flags::scrollable)
    .add(Column()
           .fill()
           .add_style("col")
           .clear_flag(Flags::scrollable)
           .justify_space_between()
           .set_row_padding(50)
           .add(Image().set_source("a:icon256x256.png"))
           .add(Button()
                  .add_style("btn_primary")
                  .add_event_callback(
                    EventCode::clicked,
                    [](lv_event_t *) {
                      Screen::find_screen(Model::Names::github_screen_name)
                        .load(slide_left);
                    })
                  .setup([](Button button) {
                    setup_button(
                      button,
                      icons::fa::code_solid,
                      Model::Names::github_screen_name,
                      Color::indigo());
                  }))
           .add(Button()
                  .add_style("btn_secondary")
                  .add_event_callback(
                    EventCode::clicked,
                    [](lv_event_t *) {
                      Screen::find_screen(Model::Names::files_screen_name)
                        .load(slide_left);
                    })
                  .setup([](Button button) {
                    setup_button(
                      button,
                      icons::fa::folder_open_solid,
                      Model::Names::files_screen_name,
                      Color::grey());
                  }))
           .add(Button()
                  .add_style("btn_info")
                  .add_event_callback(
                    EventCode::clicked,
                    [](lv_event_t *) {
                      Screen::find_screen(Model::Names::about_screen_name)
                        .load(slide_left);
                    })
                  .setup([](Button button) {
                    setup_button(
                      button,
                      icons::fa::info_circle_solid,
                      Model::Names::about_screen_name,
                      Color::blue());
                  })));
}
