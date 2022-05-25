#include "MiniginPCH.h"
#include "BaseComponent.h"
#include "GameObject.h"

dae::BaseComponent::BaseComponent(std::shared_ptr<GameObject> gameObject)
	:m_pGameObject{ gameObject }
{
}

dae::BaseComponent::~BaseComponent()
{
}
