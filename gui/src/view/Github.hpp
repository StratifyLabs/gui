
#ifndef GUI_GITHUB_HPP
#define GUI_GITHUB_HPP

#include <inet/Http.hpp>
#include <json/Json.hpp>

#include "Extras.hpp"
#include "ViewObject.hpp"

class Github : public ViewObject {
public:
  static void setup(Generic container);

private:
  friend class GithubWorker;
  struct Names {
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

  struct UpdateItem {
    const char *item_name;
    var::NumberString value;
  };

  static void entered(lv_event_t *);

  static void set_items_to_loading(void*);
  static void set_spinner_busy(bool* value);
  static void update_item(const UpdateItem* value);
};

#endif // GUI_GITHUB_HPP
