//
// Created by Tyler Gilbert on 12/30/21.
//

#ifndef GUI_GITHUBWORKER_HPP
#define GUI_GITHUBWORKER_HPP

#include <json/Json.hpp>
#include <design/Worker.hpp>
#include <lvgl/Runtime.hpp>
#include <inet/Http.hpp>

class GithubWorker : public design::Worker {
public:

  GithubWorker() = default;
  GithubWorker(lvgl::Runtime * runtime) : design::Worker(runtime, work_function){}

  void start_work(lvgl::Runtime * runtime){
    *this = GithubWorker(runtime);
    start();
  }

private:
  static void work_function(Worker * worker){
    static_cast<GithubWorker*>(worker)->work_in_background();
  }

  json::JsonValue get_url(inet::HttpSecureClient & secure_client, const char * url);
  void update_item(const char * item_name, var::NumberString value);
  void update_count(inet::HttpSecureClient & secure_client, const char * url, const char * item_name);
  void work_in_background();
  void set_items_to_loading();
  static void set_spinner_busy_runtime_task(bool * value);

};

#endif // GUI_GITHUBWORKER_HPP
