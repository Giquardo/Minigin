#include "ButtonComponent.h"
#include "GameObject.h"

dae::ButtonComponent::ButtonComponent(std::shared_ptr<GameObject> gameObject)
	: BaseComponent{ gameObject }
	, m_currentSelected{GameMode::Solo}
{
}

void dae::ButtonComponent::Update(float)
{
	
}

void dae::ButtonComponent::FixedUpdate(float)
{
}

void dae::ButtonComponent::LateUpdate(float)
{
}

void dae::ButtonComponent::Render() const
{
}

void dae::ButtonComponent::SelectNext()
{
	switch (m_currentSelected)
	{
	case GameMode::Solo:
		m_currentSelected = GameMode::CoOp;
		m_pGameObject.lock().get()->GetComponent<TransformComponent>()->IncreaseY(100);
		break;
	case GameMode::CoOp:
		m_currentSelected = GameMode::Versus;
		m_pGameObject.lock().get()->GetComponent<TransformComponent>()->IncreaseY(100);
		break;
	case GameMode::Versus:
		m_currentSelected = GameMode::Solo;
		m_pGameObject.lock().get()->GetComponent<TransformComponent>()->DecreaseY(200);
		break;
	default:
		break;
	}
}

void dae::ButtonComponent::SelectPrev()
{
	switch (m_currentSelected)
	{
	case GameMode::Solo:
		m_currentSelected = GameMode::Versus;
		m_pGameObject.lock().get()->GetComponent<TransformComponent>()->IncreaseY(200);
		break;
	case GameMode::CoOp:
		m_currentSelected = GameMode::Solo;
		m_pGameObject.lock().get()->GetComponent<TransformComponent>()->DecreaseY(100);
		break;
	case GameMode::Versus:
		m_currentSelected = GameMode::CoOp;
		m_pGameObject.lock().get()->GetComponent<TransformComponent>()->DecreaseY(100);
		break;
	default:
		break;
	}
}

GameMode dae::ButtonComponent::GetSelected()
{
	return m_currentSelected;
}
