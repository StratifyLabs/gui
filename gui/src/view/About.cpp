//
// Created by Tyler Gilbert on 11/25/21.
//

#include <design.hpp>
#include <thread.hpp>

#include "About.hpp"

void About::setup(Generic container) {

  static constexpr auto check_updates_spinner = "AboutSpinner";

  Printer::Object about_object(printer(), "About");
  printer().key(
    "size",
    var::GeneralString()
      .format("%d,%d", container.get_width(), container.get_height()));

  container.set_text_font(model().button_font)
    .add_event_callback(EventCode::entered, nullptr)
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
                             .add_label(icons::fa::chevron_left_solid)
                             .add_event_callback(EventCode::clicked, go_back)))
               .add(Label().set_text_as_static("About").set_flex_grow()))
        .add(Row().set_flex_grow())
        .add(Container()
               .add_style(Column::get_style())
               .set_height(Container::size_from_content)
               .set_row_padding(20)
               .fill_width()
               .add(Label().set_text_as_static("gui"))
               .add(Label()
                      .set_text_as_static("version: 0.1")
                      .set_text_font(Font::find("sourcecode", 50)))
               .add(Label()
                      .set_text_as_static("by: Stratify Labs, Inc")
                      .set_text_font(Font::find(32))))
        .add(Row().set_flex_grow()));
}
