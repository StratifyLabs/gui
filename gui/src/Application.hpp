//
// Created by Tyler Gilbert on 11/25/21.
//

#ifndef GUI_APPLICATION_HPP
#define GUI_APPLICATION_HPP

#include <sys/Cli.hpp>
#include <lvgl.hpp>
#include <window/Types.hpp>

#include "GuiObject.hpp"

class Application : public GuiObject {
public:
  static void run(sys::Cli & cli);



};



#endif // GUI_APPLICATION_HPP
