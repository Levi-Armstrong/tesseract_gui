#include <tesseract_gui/app/hzpch.h>
#include <tesseract_gui/app/renderer/VertexArray.h>
#include <tesseract_gui/app/renderer/Renderer.h>

#include <tesseract_gui/app/platform/OpenGL/OpenGLVertexArray.h>

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
