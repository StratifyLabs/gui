//
// Created by Tyler Gilbert on 11/25/21.
//

#include <design.hpp>
#include <thread.hpp>

#include <design/extras/FileSystemWindow.hpp>

#include "Extras.hpp"

#include "Files.hpp"
void Files::setup(Generic generic) {
  static auto file_system_window_data
    = FileSystemWindow::Data()
        .set_base_path("/")
        .set_select_file(false)
        .set_select_folder(false)
        .set_base_path(FileSystemWindow::root_drive_path())
        .set_animation_time(0_seconds);

  generic.add_event_callback(EventCode::entered, nullptr)
    .add(Column()
           .fill()
           .add_style("container")
           .add(ScreenHeader(ScreenHeader::Construct()
                               .set_title("Filesystem")
                               .set_back_clicked_callback(go_back))
                  .set_busy(false))
           .add(FileSystemWindow(file_system_window_data)
                  .fill_width()
                  .set_flex_grow())
           .add_event_callback(EventCode::notified, [](lv_event_t *e) {
             go_back(e);
           }));
}
