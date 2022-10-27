
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

namespace {

lv_fs_drv_t assetfs_drive{};

bool is_raspberry_pi
  = sys::System::is_processor_arm32() && sys::System::is_linux();

void initialize(const sys::Cli &cli) {
#if defined __link
  struct Settings {
    window::Size default_size;
    window::Size minimum_size;
    window::Window::Flags flags{window::Window::Flags::null};
    const char *dark_theme = "";
    const char *light_theme = "";
    const char *icon_path = "";
  };

  const auto settings = []() {
    if (sys::System::is_macosx()) {
      const auto default_size = window::Size(1600, 960);
      return Settings{
        .default_size = default_size,
        .minimum_size = default_size.get_half(),
        .flags
        = window::Window::Flags::highdpi | window::Window::Flags::resizeable,
        .dark_theme = "default-dark-medium",
        .light_theme = "default-light-medium",
        .icon_path = "a:icon-256x256.png"};
    }
    if (is_raspberry_pi) {
      const auto default_size = window::Size(800, 480);
      return Settings{
        .default_size = default_size,
        .minimum_size = default_size.get_half(),
        .flags = window::Window::Flags::null,
        .dark_theme = "default-dark-small",
        .light_theme = "default-light-small",
        .icon_path = "a:icon-128x128.png"};
    }
    {
      const auto default_size = window::Size(800, 480);
      return Settings{
        .default_size = default_size,
        .minimum_size = default_size.get_half(),
        .flags = window::Window::Flags::resizeable,
        .dark_theme = "default-dark-medium",
        .light_theme = "default-light-medium",
        .icon_path = "a:icon-128x128.png"};
    }
  }();

  static auto runtime = lvgl::Runtime(
    "gui",
    window::Point(),
    settings.default_size,
    window::Window::Flags::shown | settings.flags);

  if (is_raspberry_pi) {
    window::Window::show_cursor(false);
  }

  runtime.window().set_minimum_size(settings.minimum_size);

  // make the fonts available to `Font::find()`
  fonts_initialize();
  themes_initialize();

  // mount the assets FS which include the PNG icon
  // this file is distributed with the binary rather than as a separate file
  lvgl_api_mount_asset_filesystem(
    DESIGN_INCBIN_DATA(assetfs),
    &assetfs_drive,
    'a');
  // Icon is at a:icon256x256.png

  // load the PNG decoder
  lvgl_api_initialize_png_decoder();

  {
    auto model = ModelInScope();
    model.instance.runtime = &runtime;
    model.instance.icon_path = settings.icon_path;
    Printer::Object root_object(model.instance.printer, "gui");
    model.instance.printer.key("starting", cli.get_name());
    model.instance.light_theme = Theme::find(settings.light_theme);
    model.instance.dark_theme = Theme::find(settings.dark_theme);
  }
#else
  // on Stratify OS the system provides
  // the fonts, themes, display size, etc
  static lvgl::Runtime runtime;
  {
    auto model = ModelInScope();
    model.instance.icon_path = "S:/assets/icon.png";
    model.instance.image_scale = 0.5f;
    // grab the light and dark themes for the model
    model.instance.runtime = &runtime;
    model.instance.light_theme = Theme::find("default-light-small");
    model.instance.dark_theme = Theme::find("default-dark-small");
  }
#endif
}

void update_theme(EventId id) {
  auto model = ModelInScope();
  const auto is_dark = id == EventId::dark_theme_button_pressed;
  const auto &theme
    = is_dark ? model.instance.dark_theme : model.instance.light_theme;
  Display(model.instance.runtime->display()).set_theme(theme);
  model.instance.is_dark_theme = is_dark;
  model.instance.is_theme_updated = true;
  About::setup(model.instance.about_screen.get<Generic>().clean());
  Files::setup(model.instance.files_screen.get<Generic>().clean());
  Github::setup(model.instance.github_screen.get<Generic>().clean());
  Home::setup(model.instance.home_screen.get<Generic>().clean());
}
} // namespace

void Application::run(sys::Cli &cli) {

  initialize(cli);

  // model cannot be touched until all lvgl initialization is complete
  // it is initialized on first access
  auto *runtime = []() {
    auto model = ModelInScope();
    Display(model.instance.runtime->display())
      .set_theme(model.instance.dark_theme);

    About::setup(Generic(model.instance.about_screen));
    Files::setup(Generic(model.instance.files_screen));
    Github::setup(Generic(model.instance.github_screen));
    model.instance.home_screen = Screen(screen().object());
    return model.instance.runtime;
  }();

  auto back_button_subscription
    = Bus::Subscription(EventId::back_button_pressed, [](EventId id) {
        const auto transition = Screen::Transition{
          .animation = LoadAnimation::move_right,
          .period = Model::animation_period_milliseconds * 1_milliseconds};
        Screen::find_screen(Screen::default_name).load(transition);
      });

  auto dark_theme_subscription
    = Bus::Subscription(EventId::dark_theme_button_pressed, update_theme);
  auto light_theme_subscription
    = Bus::Subscription(EventId::light_theme_button_pressed, update_theme);

  Home::setup(Generic(screen().object()));

  /* I am not sure why the RPI needs a short duration deferral of drawing the
   * home screen. Without the delay, the screen starts up blank until the user pushes a
   * button (which cannot be seen)
   */
  if (is_raspberry_pi) {
    runtime->push(50_milliseconds, []() {
      Home::setup(Generic(screen().object()));
    });
  } else {
    Home::setup(Generic(screen().object()));
  }
  // start the runtime loop
  // use runtime.set_stopped() to exit
  runtime->loop();
}
