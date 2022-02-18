#ifndef TESSERACT_GUI_IMGUI_IMGUI_MANAGER_GLFW_H
#define TESSERACT_GUI_IMGUI_IMGUI_MANAGER_GLFW_H

#include <tesseract_gui/imgui/imgui_manager.h>
#include <memory>

class GLFWwindow;

namespace tesseract_gui
{

class GLFWImGuiManager : public ImGuiManager
  {
  public:
    GLFWImGuiManager();
    ~GLFWImGuiManager() override;
    void update() override;
    bool shouldClose();
  private:
    GLFWwindow* window_;
  };
}

#endif // TESSERACT_GUI_IMGUI_IMGUI_MANAGER_GLFW_H
