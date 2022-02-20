#include <tesseract_gui/hazel/hzpch.h>
#include <tesseract_gui/hazel/core/Window.h>

#ifdef HZ_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

#ifdef HZ_PLATFORM_LINUX
  #include <tesseract_gui/hazel/platform/Windows/WindowsWindow.h>
#endif

namespace Hazel
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef HZ_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
  #endif

  #ifdef HZ_PLATFORM_LINUX
    return CreateScope<WindowsWindow>(props);
  #endif

    HZ_CORE_ASSERT(false, "Unknown platform!");
    return nullptr;

	}

}
