// COPYING: Copyright 2017-2021 Tyler Gilbert and Stratify Labs. All rights
// reserved


//This must be included to handle
//SDL's main changing scheme
#include <SDL_main.h>

#include <sys/Cli.hpp>

#include "Application.hpp"
#include "ThemeGenerator.hpp"

int main(int argc, char *argv[]) {
  sys::Cli cli(argc, argv);


  if( !cli.get_option("theme").is_empty() ){
    (ThemeGenerator(cli));
    exit(api::ExecutionContext::is_error() ? 1 : 0);
  }

  Application::run(cli, window::Size(320*4,240*4));

  return 0;
}
