#include <design.hpp>
#include <lvgl_api.h>

#include <design/macros.hpp>

#include "Application.hpp"

#include "view/About.hpp"
#include "view/Files.hpp"
#include "view/Github.hpp"
#include "view/Home.hpp"

#include "designlab/themes/themes.h"
#include "designlab/fonts/fonts.h"

INCBIN(assetfs,  "../gui/src/designlab/assets/assets.assetfs");

void Application::run(sys::Cli &cli) {

  lvgl::Runtime runtime(
    "gui",
    window::Point(),
    window::Size(320 * 4, 320 * 4),
    window::Window::Flags::shown | window::Window::Flags::highdpi
      | window::Window::Flags::resizeable);

  runtime.window().set_minimum_size(window::Size(480, 360));

  // make the fonts available to `Font::find()`
  fonts_initialize();

  // mount the assets FS which include the PNG icon
  // this file is distributed with the binary rather than as a separate file
  static lv_fs_drv_t drive;
  lvgl_api_mount_asset_filesystem(DESIGN_INCBIN_DATA(assetfs), &drive, 'a');
  // Icon is at a:icon256x256.png

  // load the PNG decoder
  lvgl_api_initialize_png_decoder();

  // model cannot be touched until all lvgl initialization is complete
  // it is initialized on first access
  {
    Model::Scope model_scope;
    model().runtime = &runtime;

    Printer::Object root_object(printer(), "gui");
    printer().key("starting", cli.get_name());
    // This is where we create our top level navigation system
    // This can be based on windows, tiles, screens, tabs or whatever you deem
    // to be appropriate
    model().light_theme
      = Theme(lvgl_small_light_theme_initialize(runtime.display(), nullptr));
    model().dark_theme
      = Theme(lvgl_small_dark_theme_initialize(runtime.display(), nullptr));

    Display(runtime.display()).set_theme(model().dark_theme);

    About::setup(Generic(model().about_screen));
    Files::setup(Generic(model().files_screen));
    Github::setup(Generic(model().github_screen));
    model().home_screen = Screen(screen().object());
  }

  Home::setup(Generic(screen().object()));

  // start the runtime loop
  // use runtime.set_stopped() to exit
  runtime.loop();
}
