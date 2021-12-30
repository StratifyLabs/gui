//
// Created by Tyler Gilbert on 11/25/21.
//

#include <design.hpp>
#include <thread.hpp>

#include <design/extras/FileSystemWindow.hpp>
#include <design/extras/Form.hpp>

#include "Extras.hpp"

#include "Files.hpp"
void Files::setup(Generic generic) {

  printf("setup files\n");
  static auto file_system_window_data
    = FileSystemWindow::Data(Names::select_file)
        .set_base_path("/")
        .set_select_file(true)
        .set_select_folder(false)
        .set_absolute_path()
        .set_base_path(FileSystemWindow::root_drive_path())
        .set_animation_time(0_seconds);

  generic.add_event_callback(EventCode::entered, entered)
    .add(Column()
           .fill()
           .add_style("container")
           .add(ScreenHeader(ScreenHeader::Construct()
                               .set_title("Filesystem")
                               .set_back_clicked_callback(go_back))
                  .set_busy(false))
           .add(Form().fill_width().set_flex_grow().add(
             Form::SelectFile(file_system_window_data)
               .set_label_as_static("Your Favorite File")
               .set_hint_as_static("Select a file just for fun"))));
}

void Files::entered(lv_event_t *e) {
  printf("Entered Files\n");
}
