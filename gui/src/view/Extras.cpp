//
// Created by Tyler Gilbert on 12/30/21.
//

#include <design.hpp>
#include <lvgl.hpp>

#include <sys/System.hpp>

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
                      .add_flag(Flags::hidden)
                      .set_width(20)
                      .set_height(20));

  setup([](ScreenHeader screen_header) {
    screen_header.update_layout();
    const auto heading_size
      = screen_header.find<Button>(Names::back_button).get_height();
    screen_header.find<Spinner>(Names::spinner).set_width(heading_size).set_height(heading_size);
  });
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

AttributionRow::AttributionRow(
  const char *name,
  const char *description,
  const char *external_link) {
  construct_object(name);
  add_style(Row::get_style())
    .add_style("row")
    .fill_width()
    .add(Heading3(name).set_width(size_from_content))
    .add(Label(Names::dots_label)
           .set_text((var::String(". ") * 200).cstring())
           .set_alignment(Alignment::bottom_left)
           .set_long_mode(Label::LongMode::clip)
           .set_flex_grow())
    .add(Row(Names::link_row)
           .set_height(size_from_content)
           .set_width(size_from_content)
           .add(Heading3(description).set_width(size_from_content)));

  if (external_link != nullptr) {
    find<Row>(Names::link_row)
      .add(Button(external_link)
             .add_style("btn_light btn_sm")
             .add_label(icons::fa::external_link_alt_solid)
             .add_event_callback(EventCode::clicked, [](lv_event_t *e) {
               const auto url = Event(e).target().name();
               sys::System::launch_browser(url);
             }));
  }

  setup([](AttributionRow attribution_row) {
    const auto text_height = attribution_row.update_layout().get_height();
    auto current_height
      = attribution_row.find<Label>(Names::dots_label).get_height();
    attribution_row.find<Label>(Names::dots_label)
      .set_top_padding(text_height - current_height - 10)
      .set_height(text_height);
  });
}
