//
// Created by Tyler Gilbert on 11/25/21.
//

#include <fs.hpp>
#include <inet.hpp>
#include <json.hpp>
#include <thread.hpp>
#include <var.hpp>

#include <design.hpp>
#include <design/extras/FormList.hpp>

#include "Extras.hpp"
#include "Github.hpp"

void Github::setup(Generic generic) {

  static auto form_list_data = FormList::Data(github_form_list_name);

  static auto issues_item = FormList::ItemData("Issues")
                              .set_value("loading...")
                              .set_type(FormList::ItemType::number);

  static auto releases_item = FormList::ItemData("Releases")
                                .set_value("loading...")
                                .set_type(FormList::ItemType::number);

  static auto pulls_item = FormList::ItemData("Pulls")
                             .set_value("loading...")
                             .set_type(FormList::ItemType::number);

  static auto stars_item = FormList::ItemData("Stars")
                             .set_value("loading...")
                             .set_type(FormList::ItemType::number);

  static auto forks_item = FormList::ItemData("Forks")
                             .set_value("loading...")
                             .set_type(FormList::ItemType::number);

  generic.fill()
    .add_event_callback(EventCode::entered, nullptr)
    .add(Column()
           .fill()
           .add_style("container")
           .add(ScreenHeader(ScreenHeader::Construct()
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

void *Github::update_github_thread_function(void *) {
  HttpSecureClient secure_client;
  secure_client.connect("api.github.com");

  model().runtime->push([](void *) {
    model()
      .github_screen.find<Spinner>(busy_spinner_name)
      .clear_flag(Flags::hidden);
  });

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

  auto *error = new api::Error(api::ExecutionContext::error());
  model().runtime->push(
    [](void *context) {
      auto *error = reinterpret_cast<api::Error *>(context);

      // show an error Modal

      delete error;
      return;
    },
    error);

  model().runtime->push([](void *) {
    model()
      .github_screen.find<Spinner>(busy_spinner_name)
      .add_flag(Flags::hidden);
  });

  return nullptr;
}

json::JsonValue
Github::get_url(inet::HttpSecureClient &secure_client, const char *url) {
  DataFile response;
  secure_client.get(url, HttpSecureClient::Get().set_response(&response));
  if (is_success()) {
    return JsonDocument().load(response.seek(0));
  }
  return JsonValue();
}

void Github::update_count(
  HttpSecureClient &secure_client,
  const char *url,
  const char *item_name) {

  const auto result = get_url(secure_client, url);

  if (is_success()) {
    const u32 count = result.to_array().count();
    update_item(item_name, NumberString(count));
  }
}

void Github::update_item(const char *item_name, var::NumberString value) {
  struct Context {
    const char *item_name;
    var::NumberString value;
  };

  auto *issue_context = new Context{item_name, value};

  // this is run in a thread, runtime->push() will
  // execute a callback in the main thread as part
  // of the regular loop event updates
  // the graphics CANNOT be accessed outside the main thread

  model().runtime->push(issue_context, [](void *c) {
    auto *context = reinterpret_cast<Context *>(c);
    model()
      .github_screen.find<FormList>(github_form_list_name)
      .update_item_value(context->item_name, context->value);
    delete context;
  });
}
