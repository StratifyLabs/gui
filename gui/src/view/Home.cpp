//
// Created by Tyler Gilbert on 12/23/21.
//

#include <design/Grid.hpp>

#include "designlab/fonts/FontAwesomeIcons.hpp"

#include "Extras.hpp"
#include "Home.hpp"

using namespace design;

namespace {
struct Names {
  DESIGN_DECLARE_NAME(container);
  DESIGN_DECLARE_NAME(column);
};
void action_card_clicked(lv_event_t *e) {
  const auto name = Event(e).target().name();
  auto model = ModelInScope();
  Screen::find_screen(name).load(model.instance.slide_left);
}
}

Home::Home(const char *name) {
  construct_object(name);
  fill();
  // The current screen is the "default" screen
  // it is automatically created by lvgl
  auto model = ModelInScope();
  clear_flag(Flags::scrollable)
    .add(Container(Names::container)
           .fill()
           .add(NakedContainer(Names::column)
                  .fill()
                  .set_flex_flow(FlexFlow::row_wrap)
                  .set_flex_align(SetFlexAlign())
                  .clear_flag(Flags::scrollable)));
  static const auto width = 45_percent;
  static const auto height = 45_percent;
  auto content = find<Column>(Names::column);
  content.add(NakedContainer().set_width(width).set_height(height).add(
    Image()
      .set_source(model.instance.icon_path)
      .center()
      .set_zoom(model.instance.image_scale)));
  content.add(
    ActionCard(ActionCard::Construct()
                 .set_name(Model::Names::github_screen_name)
                 .set_clicked_callback(action_card_clicked)
                 .set_icon(icons::fa::github_brands)
                 .set_style("bg_primary text_primary")
                 .set_description("See the details of Stratify OS on Github.")
                 .set_title("Stratify OS"))
      .set_width(width)
      .set_height(height));
  content.add(
    ActionCard(ActionCard::Construct()
                 .set_name(Model::Names::files_screen_name)
                 .set_clicked_callback(action_card_clicked)
                 .set_icon(icons::fa::folder_solid)
                 .set_style("bg_secondary text_secondary")
                 .set_description("Select a file on the local filesystem.")
                 .set_title("Filesystem"))
      .set_width(width)
      .set_height(height));
  content.add(
    ActionCard(ActionCard::Construct()
                 .set_name(Model::Names::about_screen_name)
                 .set_clicked_callback(action_card_clicked)
                 .set_style("bg_info text_info")
                 .set_icon(icons::fa::info_circle_solid)
                 .set_description("See what makes this application possible.")
                 .set_title("About"))
      .set_width(width)
      .set_height(height));
}
