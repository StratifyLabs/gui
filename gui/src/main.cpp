// COPYING: Copyright 2017-2021 Tyler Gilbert and Stratify Labs. All rights
// reserved

#include <chrono/ClockTimer.hpp>
#include <lvgl/Runtime.hpp>
#include <printer/JsonPrinter.hpp>
#include <printer/Printer.hpp>
#include <sys/Cli.hpp>
#include <var/StackString.hpp>

#include <lvgl.hpp>

int main(int argc, char *argv[]) {

  sys::Cli cli(argc, argv);


  lvgl::Runtime runtime(
    "gui",
    window::Point(),
    window::Size(320 * 4, 240 * 4),
    window::Window::Flags::shown | window::Window::Flags::resizeable
      | window::Window::Flags::highdpi);

  screen().add(
    Column()
      .fill()
      .set_row_padding(20)
      .set_horizontal_padding(20)
      .add(Label().set_text_static("Hello"))
      .add(Button("Button").add_label("Hello Button").set_width(100_percent))
      .add(TextArea("textarea").set_height(30_percent).fill_width().add_to_group(runtime.keyboard_group())));

  runtime.loop();

  return 0;
}
