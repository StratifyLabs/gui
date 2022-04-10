//
// Created by Tyler Gilbert on 11/25/21.
//

#include <design.hpp>
#include <thread.hpp>

#include "About.hpp"
#include "Files.hpp"
#include "Github.hpp"
#include "Home.hpp"

#include "Extras.hpp"

About::About(const char *name) {
  construct_object(name);
  fill();
  add_style("container");

  set_text_font(model().button_font)
    .add_event_callback(EventCode::entered, nullptr)
    .add(
      Column()
        .fill()
        .add_style("container")
        .add(ScreenHeader(ScreenHeader::Construct()
                            .set_back_clicked_callback(go_back)
                            .set_title("About")))
        .add(HorizontalLine())
        .add(Row()
               .fill_width()
               .add(Button(Names::dark_button)
                      .add_label(
                        var::KeyString(icons::fa::moon_solid).append(" Dark"))
                      .add_style("btn_dark")
                      .add_event_callback(EventCode::clicked, update_theme))
               .add(Button(Names::light_button)
                      .add_label(
                        var::KeyString(icons::fa::sun_solid).append(" Light"))
                      .add_style("btn_warning")
                      .add_event_callback(EventCode::clicked, update_theme)))
        .add(AttributionRow("Version", VERSION))
        .add(AttributionRow(
          "Publisher",
          "Stratify Labs, Inc",
          "https:://stratifylabs.dev"))
        .add(AttributionRow(
          "Theme",
          "Design Lab",
          "https://github.com/StratifyLabs/DesignLab"))
        .add(AttributionRow("Icons", "FontAwesome", "https://fontawesome.com/"))
        .add(AttributionRow("Graphics", "LVGL", "https://lvgl.io"))
        .add(AttributionRow("Window", "SDL", "https://www.libsdl.org/"))
        .add(AttributionRow(
          "TLS",
          "mbedtls",
          "https://github.com/ARMmbed/mbedtls"))
        .add(AttributionRow(
          "JSON",
          "jansson",
          "https://github.com/akheron/jansson"))
        .add(AttributionRow(
          "Framework",
          "Stratify Labs API",
          "https://github.com/StratifyLabs/API")));
}

void About::update_theme(lv_event_t *e) {
  Model::Scope model_scope;
  const auto is_dark = Event(e).target().name() == Names::dark_button;
  const auto &theme = is_dark ? model().dark_theme : model().light_theme;
  Display(model().runtime->display()).set_theme(theme);
  model().is_dark_theme = is_dark;
  model().is_theme_updated = true;

  About::setup(Generic(model().about_screen.get<Generic>().clean()));
  Files::setup(Generic(model().files_screen.get<Generic>().clean()));
  Github::setup(Generic(model().github_screen.get<Generic>().clean()));
  Home::setup(Generic(model().home_screen.get<Generic>().clean()));
}