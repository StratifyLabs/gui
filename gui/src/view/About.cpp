//
// Created by Tyler Gilbert on 11/25/21.
//

#include <design/Grid.hpp>
#include <design/HorizontalLine.hpp>

#include "About.hpp"
#include "Extras.hpp"

using namespace var;
using namespace design;

namespace {
struct Names {
  DESIGN_DECLARE_NAME(dark_button);
  DESIGN_DECLARE_NAME(light_button);
};

} // namespace

About::About(const char *name) {
  construct_object(name);
  fill();
  add_style("container");
  set_text_font(ModelInScope().instance.button_font);
  add(
    Column()
      .fill()
      .add_style("container")
      .add(ScreenHeader(ScreenHeader::Construct().set_title("About")))
      .add(HorizontalLine())
      .add(Row()
             .fill_width()
             .add(Button(Names::dark_button)
                    .add_label(KeyString(icons::fa::moon_solid).append(" Dark"))
                    .add_style("btn_dark")
                    .add_event_callback(
                      EventCode::clicked,
                      [](lv_event_t *) {
                        Bus::send(EventId::dark_theme_button_pressed);
                      }))
             .add(Button(Names::light_button)
                    .add_label(KeyString(icons::fa::sun_solid).append(" Light"))
                    .add_style("btn_warning")
                    .add_event_callback(
                      EventCode::clicked,
                      [](lv_event_t *) {
                        Bus::send(EventId::light_theme_button_pressed);
                      })))
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
      .add(
        AttributionRow("TLS", "mbedtls", "https://github.com/ARMmbed/mbedtls"))
      .add(
        AttributionRow("JSON", "jansson", "https://github.com/akheron/jansson"))
      .add(AttributionRow(
        "Framework",
        "Stratify Labs API",
        "https://github.com/StratifyLabs/API")));
}
