#include <design.hpp>
#include <lvgl_api.h>

#include <design/macros.hpp>

#include "Application.hpp"

#include "view/About.hpp"
#include "view/Files.hpp"
#include "view/Github.hpp"
#include "view/Home.hpp"

#include "designlab/fonts/fonts.h"
#include "designlab/themes/themes.h"

INCBIN(assetfs, "../gui/src/designlab/assets/assets.assetfs");

void Application::run(sys::Cli &cli) {

  static constexpr size_t window_width = 800;
  static constexpr size_t window_height = 480;

  static constexpr auto multiplier =
#if __win32
    2
#else
    4
#endif
    ;

  lvgl::Runtime runtime(
    "gui",
    window::Point(),
    window::Size(window_width, window_height),
    window::Window::Flags::shown
#if !__win32
  //| window::Window::Flags::highdpi
#endif
       | window::Window::Flags::fullscreen
    );

  runtime.window().set_minimum_size(
    window::Size(window_width * multiplier / 4, window_height * multiplier / 4));

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

    model().icon_path = "a:icon-128x128.png";

    Printer::Object root_object(printer(), "gui");
    printer().key("starting", cli.get_name());
    // This is where we create our top level navigation system
    // This can be based on windows, tiles, screens, tabs or whatever you deem
    // to be appropriate
    model().light_theme
      = Theme(default_light_medium_theme_initialize(runtime.display(), nullptr));
    model().dark_theme
      = Theme(default_dark_small_theme_initialize(runtime.display(), nullptr));

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
