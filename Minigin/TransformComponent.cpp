#include "MiniginPCH.h"
#include "TransformComponent.h"

dae::TransformComponent::TransformComponent(std::shared_ptr<GameObject> gameObject)
	:BaseComponent{ gameObject }
{
	
}

void dae::TransformComponent::SetPosition(const float x, const float y, const float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

void dae::TransformComponent::IncreaseY(float value)
{
	m_Position.y += value;
}

void dae::TransformComponent::DecreaseY(float value)
{
	m_Position.y -= value;
}
