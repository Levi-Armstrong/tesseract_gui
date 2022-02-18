#include <tesseract_gui/imgui/imgui_manager_glfw.h>
#include <tesseract_gui/imgui/imgui_widget.h>
#include <imgui/imgui.h>

class ExampleWidget : public tesseract_gui::ImGuiWidget
{
public:
  ExampleWidget() = default;
  ~ExampleWidget() override  = default;

  void update() override
  {
    if (showing_)
    {
      if (ImGui::Begin("Settings", &showing_))
      { 
        ImGui::Text("This is an example window");
        ImGui::Text("Dock this window!");
        ImGui::Separator();
        ImGui::Text("You can create your own windows for any purpose");
        if (ImGui::Button("This is a button"))
          count_++;

        ImGui::Text("Count: %d", count_);

      }
      ImGui::End();
    }
  }
private:
  int count_{0};
};

int main()
{
  tesseract_gui::GLFWImGuiManager ui;
  ui.addWindow(std::make_unique<ExampleWidget>());
  while (!ui.shouldClose())
  {
    ui.update();
  }
  return 0;
}
