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
    push_task_to_runtime<bool>(&value, Github::set_spinner_busy)
      .wait_runtime_task();
  }

  push_task_to_runtime(Github::set_items_to_loading).wait_runtime_task();

  HttpSecureClient secure_client;
  secure_client.connect("api.github.com");

  const auto details
    = get_url(secure_client, "/repos/StratifyLabs/StratifyOS").to_object();

  if (api::ExecutionContext::is_success()) {
    {
      const auto item = Github::UpdateItem{
        "Forks",
        NumberString(details.at("forks_count").to_integer())};
      push_task_to_runtime(&item, Github::update_item).wait_runtime_task();
    }

    {
      const auto item = Github::UpdateItem{
        "Stars",
        NumberString(details.at("stargazers_count").to_integer())};
      push_task_to_runtime(&item, Github::update_item).wait_runtime_task();
    }
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
    push_task_to_runtime<bool>(&value, Github::set_spinner_busy)
      .wait_runtime_task();
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
    const auto item = Github::UpdateItem{item_name, NumberString(count)};
    push_task_to_runtime<const Github::UpdateItem>(&item, Github::update_item)
      .wait_runtime_task();
  }
}
