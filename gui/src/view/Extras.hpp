//
// Created by Tyler Gilbert on 12/30/21.
//

#ifndef GUI_EXTRAS_HPP
#define GUI_EXTRAS_HPP

#include <design/macros.hpp>

#include <lvgl/ObjectAccess.hpp>

#include "model/Model.hpp"


class ActionCard : public lvgl::ObjectAccess<ActionCard> {
public:
  struct Construct {
    API_PUBLIC_MEMBER_AZ(description,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(icon,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(name,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(title,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(style,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(clicked_callback,Construct,lvgl::Event::Callback, nullptr);
  };
  explicit ActionCard(const Construct & options);
  explicit ActionCard(lv_obj_t * object){ m_object = object; }
};

class ScreenHeader : public lvgl::ObjectAccess<ScreenHeader> {
public:
  struct Construct {
    API_PUBLIC_MEMBER_AZ(name,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(title,Construct,const char*, "");
  };
  explicit ScreenHeader(const Construct & options);
  explicit ScreenHeader(lv_obj_t * object){ m_object = object; }
  ScreenHeader & set_busy(bool value = true);
};

class AttributionRow : public lvgl::ObjectAccess<AttributionRow> {
public:
  AttributionRow(
    const char *name,
    const char *description,
    const char *external_link = nullptr);
  explicit AttributionRow(lv_obj_t *object) { m_object = object; }
};
#endif // GUI_EXTRAS_HPP
