//
// Created by Tyler Gilbert on 11/25/21.
//

#include <thread.hpp>

#include "About.hpp"

void About::setup(Container container) {

  static constexpr auto check_updates_spinner = "AboutSpinner";

  Printer::Object about_object(printer(), "About");
  printer().key(
    "size",
    var::GeneralString()
      .format("%d,%d", container.get_width(), container.get_height()));

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
               .add(Label().set_text_static("About").set_flex_grow()))
        .add(Row().set_flex_grow())
        .add(Container()
               .add_style(Column::get_style())
               .set_height(Container::size_from_content)
               .set_row_padding(20)
               .fill_width()
               .add(Label().set_text_static("gui"))
               .add(Label()
                      .set_text_static("version: 0.1")
                      .set_text_font(Font::find("sourcecode",50)))
               .add(Label()
                      .set_text_static("by: Stratify Labs, Inc")
                      .set_text_font(Font::find(32))))
        .add(Row().set_flex_grow()));
}