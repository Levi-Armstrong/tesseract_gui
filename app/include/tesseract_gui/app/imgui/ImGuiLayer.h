#pragma once

#include <tesseract_gui/app/core/Layer.h>
#include <tesseract_gui/app/events/ApplicationEvent.h>
#include <tesseract_gui/app/events/KeyEvent.h>
#include <tesseract_gui/app/events/MouseEvent.h>

namespace Hazel {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
		
		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
	};

}
