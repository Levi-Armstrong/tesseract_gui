#ifndef IMGUI_ADD_ALLOWED_COLLISION_ENTRY_DIALOG_H
#define IMGUI_ADD_ALLOWED_COLLISION_ENTRY_DIALOG_H

#include <string>
namespace tesseract_gui
{
class IMGuiAddAllowedCollisionEntryDialog
{
public:
  explicit IMGuiAddAllowedCollisionEntryDialog();
  ~IMGuiAddAllowedCollisionEntryDialog();

  std::string getLinkName1() const;
  std::string getLinkName2() const;
  std::string getReason() const;

  bool show() const;

private:
  std::string link_name1_;
  std::string link_name2_;
  std::string reason_;

};
}
#endif // IMGUI_ADD_ALLOWED_COLLISION_ENTRY_DIALOG_H
