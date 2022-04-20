#include <design.hpp>
#include <lvgl_api.h>
#include <sys/System.hpp>

#include <design/macros.hpp>

#include "Application.hpp"

#include "view/About.hpp"
#include "view/Files.hpp"
#include "view/Github.hpp"
#include "view/Home.hpp"

#include "designlab/fonts/fonts.h"
#include "designlab/themes/themes.h"

#if defined __macosx
#define USE_HIGHDPI 1
#else
#define USE_HIGHDPI 0
#endif

#if defined __link
INCBIN(assetfs, "../gui/src/designlab/assets/assets.assetfs");
#endif

void Application::run(sys::Cli &cli) {

  initialize(cli);

  // model cannot be touched until all lvgl initialization is complete
  // it is initialized on first access
  auto * runtime = [](){
    Model::Scope model_scope;
    Display(model().runtime->display()).set_theme(model().dark_theme);

    About::setup(Generic(model().about_screen));
    Files::setup(Generic(model().files_screen));
    Github::setup(Generic(model().github_screen));
    model().home_screen = Screen(screen().object());
    return model().runtime;
  }();

  Home::setup(Generic(screen().object()));

  // start the runtime loop
  // use runtime.set_stopped() to exit
  runtime->loop();
}

void Application::initialize(const sys::Cli &cli) {
#if defined __link
  static constexpr size_t scale = (USE_HIGHDPI + 1);
  static constexpr size_t window_width = 800;
  static constexpr size_t window_height = 480;

  const auto window_size = window::Size(window_width*scale, window_height*scale);

  static lvgl::Runtime runtime(
    "gui",
    window::Point(),
    window_size,
    window::Window::Flags::shown
#if USE_HIGHDPI
      | window::Window::Flags::highdpi
#endif
      | window::Window::Flags::resizeable);

  if (sys::System().is_processor_arm32() && sys::System().is_linux()) {
    window::Window::show_cursor(false);
  }

  runtime.window().set_minimum_size(
    window::Size(window_width, window_height));

  // make the fonts available to `Font::find()`
  fonts_initialize();

  // mount the assets FS which include the PNG icon
  // this file is distributed with the binary rather than as a separate file
  static lv_fs_drv_t drive;
  lvgl_api_mount_asset_filesystem(DESIGN_INCBIN_DATA(assetfs), &drive, 'a');
  // Icon is at a:icon256x256.png

  // load the PNG decoder
  lvgl_api_initialize_png_decoder();

  {
    Model::Scope model_scope;
    model().runtime = &runtime;

    model().icon_path = "a:icon-256x256.png";

    Printer::Object root_object(printer(), "gui");
    printer().key("starting", cli.get_name());
    // This is where we create our top level navigation system
    // This can be based on windows, tiles, screens, tabs or whatever you deem
    // to be appropriate

#if !USE_HIGHDPI
    model().light_theme
      = Theme(default_light_small_theme_initialize(runtime.display(), nullptr));
    model().dark_theme
      = Theme(default_dark_small_theme_initialize(runtime.display(), nullptr));
    model().image_scale = 0.5f;
#else
    model().light_theme = Theme(
      default_light_medium_theme_initialize(runtime.display(), nullptr));
    model().dark_theme
      = Theme(default_dark_medium_theme_initialize(runtime.display(), nullptr));

#endif


  }
#else
  // on Stratify OS the system provides
  // the fonts, themes, display size, etc
  static lvgl::Runtime runtime;
  {
    Model::Scope model_scope;

    model().icon_path = "/assets/icon-256x256.png";
    model().image_scale = 0.5f;

    // grab the light and dark themes for the model
    model().runtime = &runtime;
    model().light_theme = Theme::find("light");
    model().dark_theme = Theme::find("dark");
  }
#endif
}