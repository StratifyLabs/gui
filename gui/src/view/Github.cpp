//
// Created by Tyler Gilbert on 11/25/21.
//

#include <design/extras/FormList.hpp>
#include <fs.hpp>
#include <inet.hpp>
#include <json.hpp>
#include <var.hpp>

#include <design.hpp>
#include <design/extras/FormList.hpp>

#include "Extras.hpp"
#include "Github.hpp"

Github::Github(Data &data) {
  construct_object(data.cast_as_name());
  {
    Model::Scope ms;
    data.worker = std::move(UpdateWorker(model().runtime).set_associated_object(object()));
  }

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

  fill().add(Column()
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

// this is sent to the screen
void Github::entered(lv_event_t *e) {
  Model::Scope model_scope;
  auto github = Event(e).target().find<Github>(Names::github_object);
  auto *data = github.user_data<Data>();
  data->worker.start();
}

void Github::UpdateWorker::set_items_to_loading() {
  push_task_to_runtime<UpdateWorker>(this, [](UpdateWorker *worker) {
    auto github = Github(worker->associated_object());
    auto form_list = github.find<design::FormList>(Github::Names::form_list);
    for (const auto name : Github::item_name_list) {
      form_list.update_item_value(name, "loading...");
    }
  }).wait_runtime_task();
}

void Github::UpdateWorker::set_spinner_busy(bool value) {
  m_is_spinner_busy = value;
  push_task_to_runtime<UpdateWorker>(this, [](UpdateWorker *worker) {
    auto github = Github(worker->associated_object());
    github.find<ScreenHeader>(Github::Names::header_row)
      .set_busy(worker->m_is_spinner_busy);
  }).wait_runtime_task();
}

void Github::UpdateWorker::update_item(
  const var::StringView item_name,
  const var::StringView item_value) {
  m_item_name = item_name;
  m_item_value = item_value;
  push_task_to_runtime<UpdateWorker>(this, [](UpdateWorker *worker) {
    auto github = Github(worker->associated_object());
    github.find<design::FormList>(Github::Names::form_list)
      .update_item_value(worker->m_item_name, worker->m_item_value);
  }).wait_runtime_task();
}

void Github::UpdateWorker::work() {
  set_spinner_busy(true);
  set_items_to_loading();

  HttpSecureClient secure_client;
  secure_client.connect("api.github.com");

  const auto details
    = get_url(secure_client, "/repos/StratifyLabs/StratifyOS").to_object();

  if (api::ExecutionContext::is_success()) {
    update_item("Forks", NumberString(details.at("forks_count").to_integer()));
    update_item(
      "Stars",
      NumberString(details.at("stargazers_count").to_integer()));
  }

  update_count(
    secure_client,
    "/repos/StratifyLabs/StratifyOS/issues",
    "Issues");

  update_count(
    secure_client,
    "/repos/StratifyLabs/StratifyOS/releases",
    "Releases");

  update_count(secure_client, "/repos/StratifyLabs/StratifyOS/pulls", "Pulls");

  set_spinner_busy(false);
}

json::JsonValue Github::UpdateWorker::get_url(
  inet::HttpSecureClient &secure_client,
  const char *url) {
  DataFile response;
  secure_client.get(url, HttpSecureClient::Get().set_response(&response));
  if (is_success()) {
    return JsonDocument().load(response.seek(0));
  }
  return JsonValue();
}

void Github::UpdateWorker::update_count(
  HttpSecureClient &secure_client,
  const char *url,
  const char *item_name) {
  const auto result = get_url(secure_client, url);

  if (is_success()) {
    const u32 count = result.to_array().count();
    update_item(item_name, NumberString(count));
  }
}
