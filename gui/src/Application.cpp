
#include <lvgl/Theme.hpp>
#include <sys/System.hpp>

#include <design/macros.hpp>

#include "Application.hpp"

#include "view/About.hpp"
#include "view/Files.hpp"
#include "view/Github.hpp"
#include "view/Home.hpp"

#include "designlab/fonts/fonts.h"
#include "designlab/themes/themes.h"

#if defined __link
INCBIN(assetfs, "../gui/src/designlab/assets/assets.assetfs");
#endif

using namespace lvgl;
using namespace design;

void Application::run(sys::Cli &cli) {

  initialize(cli);

  // model cannot be touched until all lvgl initialization is complete
  // it is initialized on first access
  auto *runtime = []() {
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

  struct Settings {
    window::Size default_size;
    window::Size minimum_size;
    window::Window::Flags flags;
    const char *dark_theme;
    const char *light_theme;
    const char *icon_path;
  };

  const auto settings = []() {
    if (sys::System().is_macosx()) {
      const auto default_size = window::Size(1600, 800);
      return Settings{
        .default_size = default_size,
        .minimum_size = default_size.get_half(),
        .flags = window::Window::Flags::highdpi,
        .dark_theme = "default-dark-medium",
        .light_theme = "default-light-medium",
        .icon_path = "a:icon-256x256.png"};
    }
    {
      const auto default_size = window::Size(800, 480);
      return Settings{
        .default_size = default_size,
        .minimum_size = default_size.get_half(),
        .flags = window::Window::Flags::null,
        .dark_theme = "default-dark-medium",
        .light_theme = "default-light-medium",
        .icon_path = "a:icon-128x128.png"};
    }
  }();

  static lvgl::Runtime runtime(
    "gui",
    window::Point(),
    settings.default_size,
    window::Window::Flags::shown | settings.flags
      | window::Window::Flags::resizeable);

  if (sys::System().is_processor_arm32() && sys::System().is_linux()) {
    window::Window::show_cursor(false);
  }

  runtime.window().set_minimum_size(settings.minimum_size);

  // make the fonts available to `Font::find()`
  fonts_initialize();
  themes_initialize();

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

    model().icon_path = settings.icon_path;

    Printer::Object root_object(printer(), "gui");
    printer().key("starting", cli.get_name());
    model().light_theme = Theme::find(settings.light_theme);
    model().dark_theme = Theme::find(settings.dark_theme);
  }
#else
  // on Stratify OS the system provides
  // the fonts, themes, display size, etc
  static lvgl::Runtime runtime;
  {
    Model::Scope model_scope;

    model().icon_path = "S:/assets/icon.png";
    model().image_scale = 0.5f;

    // grab the light and dark themes for the model
    model().runtime = &runtime;
    model().light_theme = Theme::find("light");
    model().dark_theme = Theme::find("dark");
  }
#endif
}