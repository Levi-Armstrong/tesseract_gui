#include <tesseract_gui/acm/imgui_add_allowed_collision_entry_dialog.h>
#include <imgui/imgui.h>
#include <imgui/cpp/imgui_stdlib.h>
namespace tesseract_gui
{
IMGuiAddAllowedCollisionEntryDialog::IMGuiAddAllowedCollisionEntryDialog()
{
  if (ImGui::BeginPopupModal("add_allowed_collision_entry_dialog", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
  {
    ImGui::InputText("Link Name 1", link_name1_.data(), ImGuiInputTextFlags_CharsNoBlank);
    ImGui::InputText("Link Name 2", link_name2_.data(), ImGuiInputTextFlags_CharsNoBlank);
    ImGui::InputText("Reason", reason_.data(), ImGuiInputTextFlags_CharsNoBlank);

    if (ImGui::Button("OK", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
    ImGui::SetItemDefaultFocus();
    ImGui::SameLine();
    if (ImGui::Button("Cancel", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
    ImGui::EndPopup();
  }
}

IMGuiAddAllowedCollisionEntryDialog::~IMGuiAddAllowedCollisionEntryDialog() = default;

std::string IMGuiAddAllowedCollisionEntryDialog::getLinkName1() const
{
  return link_name1_;
}

std::string IMGuiAddAllowedCollisionEntryDialog::getLinkName2() const
{
  return link_name2_;
}

std::string IMGuiAddAllowedCollisionEntryDialog::getReason() const
{
  return reason_;
}

bool IMGuiAddAllowedCollisionEntryDialog::show() const
{
  ImGui::OpenPopup("add_allowed_collision_entry_dialog");

  return false;
}

}
