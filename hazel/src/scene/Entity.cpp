#include <tesseract_gui/hazel/hzpch.h>
#include <tesseract_gui/hazel/scene/Entity.h>

namespace Hazel {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}
