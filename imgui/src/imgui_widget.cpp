#include <tesseract_gui/imgui/imgui_widget.h>

#include <imgui/imgui.h>

namespace tesseract_gui
{
void ImGuiWidget::show()
{
  showing_ = true;
}

void ImGuiWidget::hide()
{
  showing_ = false;
}

ImGuiDialog::ImGuiDialog(std::string name)
  : name_(std::move(name))
{
}

void ImGuiDialog::show()
{
 ImGui::OpenPopup(name_.c_str());
}
}
