//
// Created by Tyler Gilbert on 11/25/21.
//

#include <design.hpp>
#include <design/extras/FormList.hpp>

#include "Extras.hpp"
#include "Github.hpp"

void Github::setup(Generic generic) {

  static auto form_list_data = FormList::Data(Names::form_list);

  static auto issues_item = FormList::ItemData(Names::issues)
                              .set_symbol(icons::fa::exclamation_triangle_solid)
                              .set_value("loading...")
                              .set_type(FormList::ItemType::number);

  static auto releases_item = FormList::ItemData(Names::releases)
                                .set_symbol(icons::fa::info_circle_solid)
                                .set_value("loading...")
                                .set_type(FormList::ItemType::number);

  static auto pulls_item = FormList::ItemData(Names::pulls)
                             .set_symbol(icons::fa::code_solid)
                             .set_value("loading...")
                             .set_type(FormList::ItemType::number);

  static auto stars_item = FormList::ItemData(Names::stars)
                             .set_symbol(icons::fa::star_solid)
                             .set_value("loading...")
                             .set_type(FormList::ItemType::number);

  static auto forks_item = FormList::ItemData(Names::forks)
                             .set_symbol(icons::fa::code_branch_solid)
                             .set_value("loading...")
                             .set_type(FormList::ItemType::number);

  generic.fill()
    .add_event_callback(EventCode::entered, entered)
    .add(Column()
           .fill()
           .add_style("container")
           .add(ScreenHeader(ScreenHeader::Construct()
                               .set_name(Names::header_row)
                               .set_title("Github: StratifyOS")
                               .set_back_clicked_callback(go_back)))
           .add(FormList(form_list_data)
                  .fill_width()
                  .set_flex_grow()
                  .add_item(stars_item)
                  .add_item(forks_item)
                  .add_item(issues_item)
                  .add_item(releases_item)
                  .add_item(pulls_item)));
}

void Github::entered(lv_event_t *e) {
  Model::Scope model_scope;

  model().github_worker.start_work(model().runtime);
}
