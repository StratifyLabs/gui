
#ifndef GUI_GITHUB_HPP
#define GUI_GITHUB_HPP

#include <design/Worker.hpp>
#include <inet/Http.hpp>
#include <json/Json.hpp>

#include "Extras.hpp"
#include "ViewObject.hpp"

class Github : public lvgl::ObjectAccess<Github> {
public:
  static void setup(Generic container);
  LVGL_OBJECT_ACCESS_CONSTRUCT_FROM_OBJECT(Github);
private:
  explicit Github(const char * name);
};

#endif // GUI_GITHUB_HPP
