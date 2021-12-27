//
// Created by Tyler Gilbert on 11/25/21.
//

#include <thread.hpp>
#include <design.hpp>

#include <design/extras/FileSystemWindow.hpp>

#include "Files.hpp"
void Files::setup(Generic container) {
  Printer::Object about_object(printer(), "Files");
  printer().key(
    "size",
    var::GeneralString()
      .format("%d,%d", container.get_width(), container.get_height()));

  static auto file_system_window_data
    = FileSystemWindow::Data()
        .set_base_path("/")
        .set_select_file(false)
        .set_select_folder(false)
        .set_base_path(FileSystemWindow::root_drive_path())
        .set_animation_time(0_seconds);

  container.set_text_font(model().button_font)
    .add_event_callback(
      EventCode::entered, nullptr)
    .add(FileSystemWindow(file_system_window_data)
           .set_text_font(Font::find(32))
           .fill())
    .add_event_callback(EventCode::notified, [](lv_event_t *e) { go_back(e); });
}
