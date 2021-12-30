//
// Created by Tyler Gilbert on 12/30/21.
//

#include <design.hpp>
#include <lvgl.hpp>

#include "Extras.hpp"
#include "designlab/fonts/FontAwesomeIcons.hpp"

ActionCard::ActionCard(const ActionCard::Construct &options) {
  construct_object(options.name);
  add_style("card");
  add(
    Row(Names::row)
      .fill()
      .add(Container(Names::icon_container).set_width(20_percent).fill_height())
      .add(Container(Names::content_container).set_flex_grow().fill_height()));

  auto icon_container = find<Container>(Names::icon_container);
  icon_container
    .add(
      Heading1(options.icon).set_text_alignment(TextAlignment::center).center())
    .add_style(options.style);

  auto content_container = find<Container>(Names::content_container);
  content_container.add_style(Column::get_style());
  content_container.add(Heading3(options.title))
    .add(HorizontalLine())
    .add(Paragraph(Names::description_paragraph, options.description)
           .set_flex_grow()
           .fill_width())
    .add(NakedContainer().set_flex_grow().fill_width())
    .add(
      Row()
        .fill_width()
        .set_height(Row::size_from_content)
        .add(
          Button(options.name)
            .add_label("More Info")
            .add_style("btn_success")
            .add_event_callback(EventCode::clicked, options.clicked_callback)));
}

ScreenHeader::ScreenHeader(const ScreenHeader::Construct &options) {
  construct_object(options.name);
  add_style(Row::get_style()).add_style("row");
  fill_width();
  set_height(ScreenHeader::size_from_content);
  add(Button(Names::back_button)
        .add_style("btn_primary btn_md")
        .add_label(icons::fa::chevron_left_solid)
        .add_event_callback(EventCode::clicked, options.back_clicked_callback));
  add(Heading2(options.title).set_flex_grow());
  add(Spinner(Spinner::Construct().set_name(Names::spinner))
        .set_width(75)
        .set_height(75));
}

ScreenHeader &ScreenHeader::set_busy(bool value) {
  auto spinner = find<Spinner>(Names::spinner);
  if (value) {
    spinner.clear_flag(Flags::hidden);
  } else {
    spinner.add_flag(Flags::hidden);
  }
  return *this;
}
