#include "MiniginPCH.h"
#include "PeterPepperComponent.h"

dae::PeterPepperComponent::PeterPepperComponent(std::shared_ptr<GameObject> gameObject)
	:BaseComponent(gameObject)

{
}

void dae::PeterPepperComponent::Update(float)
{
}

void dae::PeterPepperComponent::Die()
{
	Notify(m_pGameObject.lock(), Event::PlayerDied);

}
