#include <tesseract_gui/hazel/hzpch.h>
#include <tesseract_gui/hazel/renderer/RenderCommand.h>

namespace Hazel {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}
