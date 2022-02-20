#include <tesseract_gui/hazel/hzpch.h>
#include <tesseract_gui/hazel/renderer/GraphicsContext.h>
#include <tesseract_gui/hazel/renderer/Renderer.h>

#include <tesseract_gui/hazel/platform/OpenGL/OpenGLContext.h>

namespace Hazel {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
