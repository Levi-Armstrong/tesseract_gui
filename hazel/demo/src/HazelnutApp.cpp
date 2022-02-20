#include <tesseract_gui/hazel/Hazel.h>
#include <tesseract_gui/hazel/core/EntryPoint.h>

#include "EditorLayer.h"

namespace Hazel {

	class Hazelnut : public Application
	{
	public:
		Hazelnut(ApplicationCommandLineArgs args)
			: Application("Hazelnut", args)
		{
			PushLayer(new EditorLayer());
		}

		~Hazelnut()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new Hazelnut(args);
	}

}
