#include <tesseract_gui/hazel/hzpch.h>
#include <tesseract_gui/hazel/renderer/VertexArray.h>
#include <tesseract_gui/hazel/renderer/Renderer.h>

#include <tesseract_gui/hazel/platform/OpenGL/OpenGLVertexArray.h>

namespace Hazel {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
