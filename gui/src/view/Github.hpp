
#ifndef GUI_GITHUB_HPP
#define GUI_GITHUB_HPP

#include <design/Worker.hpp>
#include <inet/Http.hpp>
#include <json/Json.hpp>

#include "Extras.hpp"
#include "ViewObject.hpp"

class Github : public ViewObject, public lvgl::ObjectAccess<Github> {
public:
  static void setup(Generic container) {
    container.add(Github(Data::create(Names::github_object)))
      .add_event_callback(EventCode::entered, entered);
  }

  // Workers are used to run tasks in the background and then update the
  // graphics in the main thread
  class UpdateWorker : public design::WorkerAccess<UpdateWorker> {
  public:
    UpdateWorker() = default;
    UpdateWorker(lvgl::Runtime *runtime)
      : design::WorkerAccess<UpdateWorker>(runtime) {}

  private:
    // Use private members to communicate between the worker
    // and the lvgl runtime task
    bool m_is_spinner_busy = false;
    var::KeyString m_item_name;
    var::NumberString m_item_value;

    // This will run in a background thread when the worker is started
    void work() override;

    // used to download info from Github
    json::JsonValue
    get_url(inet::HttpSecureClient &secure_client, const char *url);
    void update_count(
      inet::HttpSecureClient &secure_client,
      const char *url,
      const char *item_name);

    // These are used to update the runtime
    void set_spinner_busy(bool value);
    void update_item(var::StringView name, var::StringView value);
    void set_items_to_loading();
  };

  struct Data : public lvgl::UserDataAccess<Data> {
  public:
    Data(const char *name) : lvgl::UserDataAccess<Data>(name) {}

    UpdateWorker worker;
  };

  LVGL_OBJECT_ACCESS_CONSTRUCT_FROM_OBJECT(Github);

private:
  friend class UpdateWorker;
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

  static constexpr auto item_name_list = {
    Names::issues,
    Names::releases,
    Names::pulls,
    Names::stars,
    Names::forks};

  Github(Data &data);
  static void entered(lv_event_t *);
};

#endif // GUI_GITHUB_HPP
