#ifndef IMGUI_ADD_ALLOWED_COLLISION_ENTRY_DIALOG_H
#define IMGUI_ADD_ALLOWED_COLLISION_ENTRY_DIALOG_H

#include <string>
#include <tesseract_gui/imgui/imgui_widget.h>

namespace tesseract_gui
{
class IMGuiAddAllowedCollisionEntryDialog : public ImGuiDialog
{
public:
  explicit IMGuiAddAllowedCollisionEntryDialog();
  ~IMGuiAddAllowedCollisionEntryDialog() override;

  std::string getLinkName1() const;
  std::string getLinkName2() const;
  std::string getReason() const;

private:
  std::string link_name1_;
  std::string link_name2_;
  std::string reason_;
};
}
#endif // IMGUI_ADD_ALLOWED_COLLISION_ENTRY_DIALOG_H
