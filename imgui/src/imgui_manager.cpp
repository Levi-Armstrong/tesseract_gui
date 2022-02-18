#include <tesseract_gui/imgui/imgui_manager.h>
#include <imgui/imgui.h>
#include <imgui/imgui_themes.h>

namespace tesseract_gui
{
ImGuiManager::ImGuiManager()
{
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
//  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

  setstyle();
  setFont();
}

ImGuiManager::~ImGuiManager()
{
  ImGui::DestroyContext();
}

void ImGuiManager::update()
{
  ImGui::NewFrame();
  ImGuiIO& io = ImGui::GetIO();

  bool show = true;
  showDockSpace(&show);

  for (auto& widget : widgets_)
    widget->update();

  //uncomment to show demowindow
  //ImGui::ShowDemoWindow();
  ImGui::Render();
}

void ImGuiManager::showDockSpace(bool* p_open)
{
  static bool opt_fullscreen_persistant = true;
  bool opt_fullscreen = opt_fullscreen_persistant;
  static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

  ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
  if (opt_fullscreen)
  {
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
  }

  if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
    window_flags |= ImGuiWindowFlags_NoBackground;

  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
  ImGui::Begin("###DockSpace", p_open, window_flags);
  ImGui::PopStyleVar();

  if (opt_fullscreen)
    ImGui::PopStyleVar(2);

  // DockSpace
  ImGuiIO& io = ImGui::GetIO();
  if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
  {
    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
  }

  ImGui::End();
}

void ImGuiManager::setstyle()
{
  ImGui::ApplyCorporateGreyTheme(true);
}

void ImGuiManager::setFont()
{
  // Load Fonts
  // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
  // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
  // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
  // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
  // - Read 'docs/FONTS.md' for more instructions and details.
  // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  io.Fonts->AddFontDefault();
  io.Fonts->AddFontFromFileTTF((std::string(IMGUI_SHARE_DIR) + "/fonts/Cousine-Regular.ttf").c_str(), 15.0f);
  io.Fonts->AddFontFromFileTTF((std::string(IMGUI_SHARE_DIR) + "/fonts/DroidSans.ttf").c_str(), 16.0f);
  io.Fonts->AddFontFromFileTTF((std::string(IMGUI_SHARE_DIR) + "/fonts/ProggyTiny.ttf").c_str(), 10.0f);
  io.FontDefault = io.Fonts->AddFontFromFileTTF((std::string(IMGUI_SHARE_DIR) + "/fonts/Roboto-Medium.ttf").c_str(), 16.0f);;
}

void ImGuiManager::addWindow(ImGuiWidget::UPtr widget)
{
  widgets_.push_back(std::move(widget));
}

}
