//
// Created by Tyler Gilbert on 11/25/21.
//

#include <thread.hpp>

#include "Files.hpp"
void Files::setup(Container container) {
  Printer::Object about_object(printer(), "Files");
  printer().key(
    "size",
    var::GeneralString()
      .format("%d,%d", container.get_width(), container.get_height()));

  static auto file_system_window_data
    = FileSystemWindow::Data()
        .set_path("/")
        .set_select_file(false)
        .set_select_folder(false)
        .set_base_path(FileSystemWindow::root_drive_path())
        .set_animation_time(0_seconds);

  container.set_text_font(model().button_font)
    .add_event_callback(
      EventCode::entered,
      [](lv_event_t *) {
        // check for updates
        if (model().check_update_worker.mutex.try_lock()) {
          model().check_update_worker.thread
            = Thread(nullptr, [](void *) -> void * { return nullptr; }).move();
        }
      })
    .add(FileSystemWindow(file_system_window_data, 8_percent)
           .set_text_font(Font::find(32))
           .fill())
    .add_event_callback(EventCode::notified, [](lv_event_t *e) { go_back(e); });
}
