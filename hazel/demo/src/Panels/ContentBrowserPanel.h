#pragma once

#include <filesystem>

#include <tesseract_gui/hazel/renderer/Texture.h>

namespace Hazel {

	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRender();
	private:
		std::filesystem::path m_CurrentDirectory;
		
		Ref<Texture2D> m_DirectoryIcon;
		Ref<Texture2D> m_FileIcon;
	};

}
