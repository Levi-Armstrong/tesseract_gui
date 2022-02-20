#include <tesseract_gui/app/hzpch.h>
#include <tesseract_gui/app/scene/Entity.h>

namespace Hazel {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}
