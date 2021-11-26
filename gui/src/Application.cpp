#include <lvgl_api.h>

#include "Application.hpp"

#include "fonts/fonts.h"

#include "About.hpp"
#include "Files.hpp"
#include "Github.hpp"

extern "C" const char data_assetfs[];

void Application::run(sys::Cli &cli, const window::Size &size) {

  lvgl::Runtime runtime(
    "gui",
    window::Point(),
    size,
    window::Window::Flags::shown | window::Window::Flags::highdpi);

  fonts_initialize();

  // mount the assets FS
  lv_fs_drv_t drive;
  lvgl_api_mount_asset_filesystem(data_assetfs, &drive, 'd');
  lvgl_api_initialize_png_decoder();
  // Icon is at d:icon.png

  model().runtime = &runtime;

  Printer::Object root_object(printer(), "gui");
  printer().key("starting", cli.get_name());

  // This is where we create our top level navigation system
  // This can be based on windows, tiles, screens, tabs or whatever you deem to
  // be appropriate

  static constexpr auto about_screen_name = "About";
  static constexpr auto github_screen_name = "Github";
  static constexpr auto files_screen_name = "Files";

  Screen about_screen(about_screen_name);
  Screen github_screen(github_screen_name);
  Screen files_screen(files_screen_name);

  About::setup(Container(about_screen));
  Files::setup(Container(files_screen));
  Github::setup(Container(github_screen));

  // The current screen is the "default" screen
  // it is automatically created by lvgl

  static const auto button_style = Style()
                                     .fill_width()
                                     .set_height(15_percent)
                                     .set_border_width(20)
                                     .set_text_font(model().button_font);

  static auto setup_button =
    [](Button button, const char *icon, const char *screen_name, Color color) {
      button.add_style(button_style)
        .set_horizontal_padding(20)
        .set_background_color(color)
        .set_border_color(color.darken(MixRatio::x20))
        .add(Row()
               .fill()
               .add(Label().set_text_static(icon).set_right_padding(20))
               .add(Label().set_text_static(screen_name).set_flex_grow())
               .add(Label().set_text_static(Icons::chevron_right)));
    };

  static auto slide_left = Screen::Transition(
    {.animation = Screen::LoadAnimation::move_left,
     .period = animation_period_milliseconds * 1_milliseconds});

  // build the GUI using the LvglAPI
  screen()
    .clear_flag(Flags::scrollable)
    .add(Column()
           .fill()
           .add_style(model().container_style)
           .clear_flag(Flags::scrollable)
           .justify_space_between()
           .set_row_padding(50)
           .add(Image().set_source("d:icon256x256.png"))
           .add(Button()
                  .add_event_callback(
                    EventCode::clicked,
                    [](lv_event_t *) {
                      Screen::find_screen(github_screen_name).load(slide_left);
                    })
                  .setup([](Button button) {
                    setup_button(
                      button,
                      Icons::code,
                      github_screen_name,
                      Color::indigo());
                  }))
           .add(Button()
                  .add_event_callback(
                    EventCode::clicked,
                    [](lv_event_t *) {
                      Screen::find_screen(files_screen_name).load(slide_left);
                    })
                  .setup([](Button button) {
                    setup_button(
                      button,
                      Icons::folder_open,
                      files_screen_name,
                      Color::grey());
                  }))
           .add(Button()
                  .add_event_callback(
                    EventCode::clicked,
                    [](lv_event_t *) {
                      Screen::find_screen(about_screen_name).load(slide_left);
                    })
                  .setup([](Button button) {
                    setup_button(
                      button,
                      Icons::info,
                      about_screen_name,
                      Color::blue());
                  })));

  // start the runtime loop
  // use runtime.set_stopped() to exit
  runtime.loop();
}
