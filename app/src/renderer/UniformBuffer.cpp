#include <tesseract_gui/app/hzpch.h>
#include <tesseract_gui/app/renderer/UniformBuffer.h>
#include <tesseract_gui/app/renderer/Renderer.h>

#include <tesseract_gui/app/platform/OpenGL/OpenGLUniformBuffer.h>

namespace Hazel {

	Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLUniformBuffer>(size, binding);
		}

		HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
