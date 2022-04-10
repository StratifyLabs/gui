//
// Created by Tyler Gilbert on 12/23/21.
//

#include <design.hpp>

#include "designlab/fonts/FontAwesomeIcons.hpp"

#include "Extras.hpp"
#include "Home.hpp"

Home::Home(const char *name) {
  construct_object(name);
  fill();
  // The current screen is the "default" screen
  // it is automatically created by lvgl

  Model::Scope ms;

  static const auto button_style
    = Style().fill_width().set_height(20_percent).set_border_width(20);

  static const auto width = 45_percent;
  static const auto height = 45_percent;

  static auto slide_left = Screen::Transition(
    {.animation = Screen::LoadAnimation::move_left,
     .period = Model::animation_period_milliseconds * 1_milliseconds});

  clear_flag(Flags::scrollable)
    .add(Container(Names::container)
           .fill()
           .add(NakedContainer(Names::column)
                  .fill()
                  .set_flex_flow(FlexFlow::row_wrap)
                  .set_flex_align(SetFlexAlign())
                  .clear_flag(Flags::scrollable)));

  auto content = find<Column>(Names::column);

  content.add(NakedContainer().set_width(width).set_height(height).add(
    Image()
      .set_source(model().icon_path)
      .center()
      .set_zoom(model().image_scale)));

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
                 .set_icon(icons::fa::folder_open_solid)
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

void Home::action_card_clicked(lv_event_t *e) {
  const auto name = Event(e).target().name();
  Model::Scope model_scope;
  Screen::find_screen(name).load(model().slide_left);
}
