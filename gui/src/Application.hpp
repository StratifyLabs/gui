//
// Created by Tyler Gilbert on 11/25/21.
//

#ifndef GUI_APPLICATION_HPP
#define GUI_APPLICATION_HPP

#include <sys/Cli.hpp>
#include <lvgl.hpp>

#include "view/ViewObject.hpp"

class Application : public ModelAccess {
public:
  static void run(sys::Cli & cli);

private:
  static void initialize(const sys::Cli &cli);
};



#endif // GUI_APPLICATION_HPP
