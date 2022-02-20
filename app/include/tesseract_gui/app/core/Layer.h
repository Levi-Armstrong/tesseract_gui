#pragma once

#include <tesseract_gui/app/core/Base.h>
#include <tesseract_gui/app/core/Timestep.h>
#include <tesseract_gui/app/events/Event.h>

namespace Hazel {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}
