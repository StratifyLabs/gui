
#ifndef GUI_GITHUB_HPP
#define GUI_GITHUB_HPP

#include <inet/Http.hpp>
#include <json/Json.hpp>

#include "GuiObject.hpp"

class Github : public GuiObject {
public:
  static void setup(Container container);

private:
  static constexpr auto github_form_list_name = "GithubFormList";
  static constexpr auto busy_spinner_name = "GithubBusySpinner";

  static json::JsonValue get_url(inet::HttpSecureClient & secure_client, const char * url);
  static void update_item(const char * item_name, var::NumberString value);
  static void update_count(inet::HttpSecureClient & secure_client, const char * url, const char * item_name);

  static void * update_github_thread_function(void *);

};

#endif // GUI_GITHUB_HPP
