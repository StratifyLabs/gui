//
// Created by Tyler Gilbert on 12/30/21.
//

#ifndef GUI_EXTRAS_HPP
#define GUI_EXTRAS_HPP

#include <design/macros.hpp>

#include <lvgl/ObjectAccess.hpp>

#include "model/Model.hpp"


class ActionCard : public lvgl::ObjectAccess<ActionCard>, public ModelAccess {
public:

  struct Construct {
    API_PUBLIC_MEMBER_AZ(description,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(icon,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(name,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(title,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(style,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(clicked_callback,Construct,lvgl::Event::Callback, nullptr);
  };

  ActionCard(const Construct & options);
  ActionCard(lv_obj_t * object){ m_object = object; }
private:
  struct Names {
    DESIGN_DECLARE_NAME(row);
    DESIGN_DECLARE_NAME(icon_container);
    DESIGN_DECLARE_NAME(content_container);
    DESIGN_DECLARE_NAME(description_paragraph);
  };
};

class ScreenHeader : public lvgl::ObjectAccess<ScreenHeader>, public ModelAccess {
public:

  struct Construct {
    API_PUBLIC_MEMBER_AZ(name,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(title,Construct,const char*, "");
    API_PUBLIC_MEMBER_AZ(back_clicked_callback,Construct,lvgl::Event::Callback, nullptr);
  };

  ScreenHeader(const Construct & options);
  ScreenHeader(lv_obj_t * object){ m_object = object; }

  ScreenHeader & set_busy(bool value = true);
private:
  struct Names {
    DESIGN_DECLARE_NAME(row);
    DESIGN_DECLARE_NAME(title_heading);
    DESIGN_DECLARE_NAME(back_button);
    DESIGN_DECLARE_NAME(spinner);
  };

};

class AttributionRow : public lvgl::ObjectAccess<AttributionRow> {
public:
  AttributionRow(
    const char *name,
    const char *description,
    const char *external_link = nullptr);
  AttributionRow(lv_obj_t *object) { m_object = object; }


private:
  struct Names {
    DESIGN_DECLARE_NAME(external_link_button);
    DESIGN_DECLARE_NAME(link_row);
    DESIGN_DECLARE_NAME(dots_label);
  };
};
#endif // GUI_EXTRAS_HPP
