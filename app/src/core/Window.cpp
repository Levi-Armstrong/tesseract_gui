#include <tesseract_gui/app/hzpch.h>
#include <tesseract_gui/app/core/Window.h>

#ifdef HZ_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

#ifdef HZ_PLATFORM_LINUX
  #include <tesseract_gui/app/platform/Windows/WindowsWindow.h>
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
