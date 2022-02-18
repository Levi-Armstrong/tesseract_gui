#ifndef TESSERACT_GUI_IMGUI_IMGUI_WIDGET_H
#define TESSERACT_GUI_IMGUI_IMGUI_WIDGET_H
#include <string>
#include <memory>

namespace tesseract_gui
{
class ImGuiWidget
{
public:

  using Ptr = std::shared_ptr<ImGuiWidget>;
  using ConstPtr = std::shared_ptr<const ImGuiWidget>;
  using UPtr = std::unique_ptr<ImGuiWidget>;
  using ConstUPtr = std::unique_ptr<const ImGuiWidget>;

  ImGuiWidget() = default;
  virtual ~ImGuiWidget() = default;
  virtual void update() = 0;
  void show();
  void hide();
protected:
    bool showing_{true};
};

class ImGuiDialog
{
public:

  using Ptr = std::shared_ptr<ImGuiDialog>;
  using ConstPtr = std::shared_ptr<const ImGuiDialog>;
  using UPtr = std::unique_ptr<ImGuiDialog>;
  using ConstUPtr = std::unique_ptr<const ImGuiDialog>;

  ImGuiDialog(std::string name);
  virtual ~ImGuiDialog() = default;
  void show();
protected:
    std::string name_;
};

}
#endif // TESSERACT_GUI_IMGUI_IMGUI_WIDGET_H
