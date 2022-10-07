//
// Created by Tyler Gilbert on 11/25/21.
//

#include <design.hpp>
#include <thread.hpp>

#include <design/extras/FileSystemCard.hpp>
#include <design/extras/Form.hpp>

#include "Extras.hpp"

#include "Files.hpp"

namespace {
struct Names {
  DESIGN_DECLARE_NAME(select_file);
};
} // namespace

void Files::setup(Generic generic) {
  generic.add(
    Column()
      .fill()
      .add_style("container")
      .add(ScreenHeader(ScreenHeader::Construct()
                          .set_title("Filesystem"))
             .set_busy(false))
      .add(Form().fill_width().set_flex_grow().add(
        Form::SelectFile(FileSystemCard::Data::create(Names::select_file)
                           .set_base_path("/")
                           .set_select_file(true)
                           .set_select_folder(false)
                           .set_absolute_path()
#if defined __link
                           .set_drop_symbol(icons::fa::parachute_box_solid)
#endif
                           .set_base_path(FileSystemCard::root_drive_path())
                           .set_animation_time(0_seconds))
          .set_label_as_static("Your Favorite File")
          .set_hint_as_static("Select a file just for fun"))));
}
