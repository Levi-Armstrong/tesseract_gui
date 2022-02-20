#include <tesseract_gui/app/hzpch.h>
#include <tesseract_gui/app/renderer/RenderCommand.h>

namespace Hazel {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}
