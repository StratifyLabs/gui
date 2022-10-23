//
// Created by Tyler Gilbert on 11/25/21.
//

#include <design/Grid.hpp>
#include <design/extras/FormList.hpp>
#include <fs/DataFile.hpp>
#include <inet/Http.hpp>
#include <json/JsonDocument.hpp>
#include <var/StackString.hpp>

#include "Extras.hpp"
#include "Github.hpp"

using namespace inet;
using namespace fs;
using namespace var;
using namespace lvgl;
using namespace json;
using namespace design;

namespace {

struct Names {
  DESIGN_DECLARE_NAME(github_object);
  DESIGN_DECLARE_NAME(header_row);
  DESIGN_DECLARE_NAME(form_list);
  static constexpr auto issues = "Issues";
  static constexpr auto releases = "Releases";
  static constexpr auto pulls = "Pulls";
  static constexpr auto stars = "Stars";
  static constexpr auto forks = "Forks";
};

constexpr auto item_name_list
  = {Names::issues, Names::releases, Names::pulls, Names::stars, Names::forks};

json::JsonValue
get_url(inet::HttpSecureClient &secure_client, const char *url) {
  auto response = HttpSecureClient::MethodResponse(DataFile());
  secure_client.get(url, response);
  if (api::ExecutionContext::is_success()) {
    return JsonDocument().load(response.file.seek(0));
  }
  return {};
}

// Workers are used to run tasks in the background and then update the
// graphics in the main thread
class UpdateWorker : public WorkerAccess<UpdateWorker> {
public:
  UpdateWorker() = default;
  explicit UpdateWorker(Runtime *runtime, lv_obj_t *object)
    : WorkerAccess<UpdateWorker>(runtime, object) {}

private:
  // Use private members to communicate between the worker
  // and the lvgl runtime task
  bool m_is_spinner_busy = false;
  var::KeyString m_item_name;
  var::NumberString m_item_value;

  // This will run in a background thread when the worker is started
  auto work() -> void override {
    set_spinner_busy(true);
    set_items_to_loading();

    HttpSecureClient secure_client;
    secure_client.connect("api.github.com");

    const auto details
      = get_url(secure_client, "/repos/StratifyLabs/StratifyOS").to_object();

    if (api::ExecutionContext::is_success()) {
      update_item(
        "Forks",
        NumberString(details.at("forks_count").to_integer()));
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
    update_count(
      secure_client,
      "/repos/StratifyLabs/StratifyOS/pulls",
      "Pulls");
    set_spinner_busy(false);
  }

  // used to download info from Github
  auto update_count(
    inet::HttpSecureClient &secure_client,
    const char *url,
    const char *item_name) -> void {
    const auto result = get_url(secure_client, url);

    if (is_success()) {
      const u32 count = result.to_array().count();
      update_item(item_name, NumberString(count));
    }
  }

  // These are used to update the runtime
  auto set_spinner_busy(bool value) -> void {
    m_is_spinner_busy = value;
    push_task_to_runtime([this]() {
      auto github = Github(associated_object());
      github.find<ScreenHeader>(Names::header_row).set_busy(m_is_spinner_busy);
    }).wait_runtime_task();
  }

  auto update_item(var::StringView name, var::StringView value) -> void {
    m_item_name = name;
    m_item_value = value;
    push_task_to_runtime([this]() {
      auto github = Github(associated_object());
      github.find<FormList>(Names::form_list)
        .update_item_value(m_item_name, m_item_value);
    }).wait_runtime_task();
  }
  auto set_items_to_loading() -> void {
    push_task_to_runtime([this]() {
      auto github = Github(associated_object());
      auto form_list = github.find<FormList>(Names::form_list);
      for (const auto name : item_name_list) {
        form_list.update_item_value(name, "loading...");
      }
    }).wait_runtime_task();
  }
};

struct GithubData : public UserDataAccess<GithubData> {
public:
  explicit GithubData(const char *name) : UserDataAccess<GithubData>(name) {}
  UpdateWorker worker;
};

// this is sent to the screen
void entered(lv_event_t *e) {
  auto github = Event(e).target().find<Github>(Names::github_object);
  auto *data = github.user_data<GithubData>();
  data->worker
    = UpdateWorker(ModelInScope().instance.runtime, data->associated_object());
  data->worker.start();
}

} // namespace

void Github::setup(Generic container) {
  container.add(Github(GithubData::create(Names::github_object).cast_as_name()))
    .add_event_callback(EventCode::entered, entered);
}

Github::Github(const char *name) {
  construct_object(name);
  add_style("container");

  fill();
  add(Column()
        .fill()
        .add_style("container")
        .add(ScreenHeader(ScreenHeader::Construct()
                            .set_name(Names::header_row)
                            .set_title("Github: StratifyOS")))
        .add(FormList(FormList::Data::create(Names::form_list))
               .fill_width()
               .set_flex_grow()
               .add_item(FormList::ItemData::create(Names::stars)
                           .set_symbol(icons::fa::star_solid)
                           .set_value("loading...")
                           .set_type(FormList::ItemType::number))
               .add_item(FormList::ItemData::create(Names::forks)
                           .set_symbol(icons::fa::code_branch_solid)
                           .set_value("loading...")
                           .set_type(FormList::ItemType::number))
               .add_item(FormList::ItemData::create(Names::issues)
                           .set_symbol(icons::fa::exclamation_triangle_solid)
                           .set_value("loading...")
                           .set_type(FormList::ItemType::number))
               .add_item(FormList::ItemData::create(Names::releases)
                           .set_symbol(icons::fa::info_circle_solid)
                           .set_value("loading...")
                           .set_type(FormList::ItemType::number))
               .add_item(FormList::ItemData::create(Names::pulls)
                           .set_symbol(icons::fa::code_solid)
                           .set_value("loading...")
                           .set_type(FormList::ItemType::number))));
}
