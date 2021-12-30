#include <design/extras/FormList.hpp>
#include <fs.hpp>
#include <inet.hpp>
#include <json.hpp>
#include <var.hpp>

#include "GithubWorker.hpp"
#include "view/Github.hpp"

void GithubWorker::work_in_background() {
  {
    bool value = true;
    push_task_to_runtime<bool>(&value, set_spinner_busy_runtime_task);
    wait_runtime_task();
  }

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

  {
    bool value = false;
    push_task_to_runtime<bool>(&value, set_spinner_busy_runtime_task);
    wait_runtime_task();
  }
}

json::JsonValue
GithubWorker::get_url(inet::HttpSecureClient &secure_client, const char *url) {
  DataFile response;
  secure_client.get(url, HttpSecureClient::Get().set_response(&response));
  if (is_success()) {
    return JsonDocument().load(response.seek(0));
  }
  return JsonValue();
}

void GithubWorker::update_count(
  HttpSecureClient &secure_client,
  const char *url,
  const char *item_name) {

  const auto result = get_url(secure_client, url);

  if (is_success()) {
    const u32 count = result.to_array().count();
    update_item(item_name, NumberString(count));
  }
}

void GithubWorker::update_item(const char *item_name, var::NumberString value) {
  struct Context {
    const char *item_name;
    var::NumberString value;
  };

  auto issue_context = Context{item_name, value};

  // this is run in a thread, runtime->push() will
  // execute a callback in the main thread as part
  // of the regular loop event updates
  // the graphics CANNOT be accessed outside the main thread
  push_task_to_runtime<Context>(&issue_context, [](Context *context) {
    Model::Scope model_scope;
    auto &model = ModelAccess::model();
    model.github_screen.find<design::FormList>(Github::Names::form_list)
      .update_item_value(context->item_name, context->value);
  });

  wait_runtime_task();
}

void GithubWorker::set_items_to_loading() {
  bool value = true;
  push_task_to_runtime<bool>(&value, [](bool *value) {
    Model::Scope model_scope;
    auto &model = ModelAccess::model();
    auto form_list
      = model.github_screen.find<design::FormList>(Github::Names::form_list);
    for (const auto name : Github::item_name_list) {
      form_list.update_item_value(name, "loading...");
    }
  });

  wait_runtime_task();
}

void GithubWorker::set_spinner_busy_runtime_task(bool *value) {
  Model::Scope model_scope;
  auto &model = ModelAccess::model();
  model.github_screen.find<ScreenHeader>(Github::Names::header_row)
    .set_busy(*value);
}
