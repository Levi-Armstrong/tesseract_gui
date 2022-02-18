#ifndef TESSERACT_GUI_IMGUI_IMGUI_MANAGER_H
#define TESSERACT_GUI_IMGUI_IMGUI_MANAGER_H

#include <tesseract_gui/imgui/imgui_widget.h>
#include <vector>

namespace tesseract_gui
{
class ImGuiManager
{
public:
  ImGuiManager();
  virtual ~ImGuiManager();
  virtual void update();
  void addWindow(ImGuiWidget::UPtr widget);

private:
  std::vector<ImGuiWidget::UPtr> widgets_;
  void showDockSpace(bool* p_open);
  void setstyle();
  void setFont();
};

}
#endif // TESSERACT_GUI_IMGUI_IMGUI_MANAGER_H
