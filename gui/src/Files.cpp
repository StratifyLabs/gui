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

  static auto file_system_window_data = FileSystemWindow::Data().set_path("/");

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
    .add(
      Column()
        .add_style(model().container_style)
        .set_row_padding(20)
        .add(Row()
               .fill_width()
               .add(NakedContainer()
                      .set_width(NakedContainer::size_from_content)
                      .set_height(NakedContainer::size_from_content)
                      .set_padding(20)
                      .add(Button()
                             .set_alignment(Alignment::left_middle)
                             .add_label(Icons::chevron_left)
                             .add_event_callback(EventCode::clicked, go_back)))
               .add(Label().set_text_static("Files").set_flex_grow()))
        .add(FileSystemWindow(file_system_window_data)
               .set_text_font(Font::find(32))
               .set_width(100_percent)
               .set_height(80_percent)));
}
