//
// Created by Tyler Gilbert on 12/23/21.
//

#include <design.hpp>

#include "designlab/fonts/FontAwesomeIcons.hpp"

#include "Extras.hpp"
#include "Home.hpp"

void Home::setup(Generic generic) {
  // The current screen is the "default" screen
  // it is automatically created by lvgl

  Model::Scope ms;

  static const auto button_style
    = Style().fill_width().set_height(20_percent).set_border_width(20);

  static auto setup_button =
    [](Button button, const char *icon, const char *screen_name, Color color) {
      button.add_style(button_style)
        .set_horizontal_padding(20)
        .add_style(Row::get_style())
        .add_style(Row::get_style())
        .add(Label().set_text_as_static(icon).set_right_padding(20))
        .add(Label().set_text_as_static(screen_name).set_flex_grow())
        .add(Label().set_text_as_static(icons::fa::chevron_right_solid));
    };

  static auto slide_left = Screen::Transition(
    {.animation = Screen::LoadAnimation::move_left,
     .period = Model::animation_period_milliseconds * 1_milliseconds});

  // build the GUI using the LvglAPI
  generic.clear_flag(Flags::scrollable)
    .add(
      Container(Names::container)
        .fill()
        .add(Column(Names::column)
               .fill()
               .add_style("col")
               .clear_flag(Flags::scrollable)
               .justify_space_between()
               .add(Image().set_source(model().icon_path))));

  auto column = generic.find<Column>(Names::column);

  column.add(
    ActionCard(ActionCard::Construct()
                 .set_name(Model::Names::github_screen_name)
                 .set_clicked_callback(action_card_clicked)
                 .set_icon(icons::fa::github_brands)
                 .set_style("bg_primary text_primary")
                 .set_description("See the details of Stratify OS on Github.")
                 .set_title("Stratify OS"))
      .set_width(95_percent)
      .set_height(25_percent));

  column.add(
    ActionCard(ActionCard::Construct()
                 .set_name(Model::Names::files_screen_name)
                 .set_clicked_callback(action_card_clicked)
                 .set_icon(icons::fa::folder_open_solid)
                 .set_style("bg_secondary text_secondary")
                 .set_description("Select a file on the local filesystem.")
                 .set_title("Filesystem"))
      .set_width(95_percent)
      .set_height(25_percent));

  column.add(
    ActionCard(ActionCard::Construct()
                 .set_name(Model::Names::about_screen_name)
                 .set_clicked_callback(action_card_clicked)
                 .set_style("bg_info text_info")
                 .set_icon(icons::fa::info_circle_solid)
                 .set_description("See what makes this application possible.")
                 .set_title("About"))
      .set_width(95_percent)
      .set_height(25_percent));
}

void Home::action_card_clicked(lv_event_t *e) {
  const auto name = Event(e).target().name();
  Model::Scope model_scope;
  Screen::find_screen(name).load(model().slide_left);
}
