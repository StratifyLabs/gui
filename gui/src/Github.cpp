//
// Created by Tyler Gilbert on 11/25/21.
//

#include <thread.hpp>

#include "Github.hpp"
void Github::setup(Container container) {

  Printer::Object about_object(printer(), "Github");
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
               .add(Label().set_text_static("Github").set_flex_grow())));
}
