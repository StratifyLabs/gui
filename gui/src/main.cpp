// COPYING: Copyright 2017-2021 Tyler Gilbert and Stratify Labs. All rights
// reserved

#include <sys/Cli.hpp>

#include "Application.hpp"

int main(int argc, char *argv[]) {
  sys::Cli cli(argc, argv);
  Application::run(cli, window::Size(320*4,240*4));

  return 0;
}
