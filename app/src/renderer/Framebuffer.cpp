#include <tesseract_gui/app/hzpch.h>
#include <tesseract_gui/app/renderer/Framebuffer.h>

#include <tesseract_gui/app/renderer/Renderer.h>

#include <tesseract_gui/app/platform/OpenGL/OpenGLFramebuffer.h>

namespace Hazel {
	
	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLFramebuffer>(spec);
		}

		HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}

