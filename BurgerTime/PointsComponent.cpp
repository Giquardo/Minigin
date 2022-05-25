#include "MiniginPCH.h"
#include "PointsComponent.h"
#include "TextComponent.h"
#include "GameObject.h"

dae::PointsComponent::PointsComponent(std::shared_ptr<GameObject> gameObject)
	:BaseComponent{ gameObject }
{
}

void dae::PointsComponent::Update(float)
{
}

int dae::PointsComponent::GetPoints() const
{
	return m_Points;
}

void dae::PointsComponent::AddPoints(int amount)
{
	m_Points += amount;
	m_pGameObject.lock().get()->GetComponent<TextComponent>()->SetText("Points: " + std::to_string(m_Points));
	Notify(m_pGameObject.lock(), Event::ScoreChanged);
}

void dae::PointsComponent::RemovePoints(int amount)
{
	m_Points -= amount;
	m_pGameObject.lock().get()->GetComponent<TextComponent>()->SetText("Points: " + std::to_string(m_Points));
	Notify(m_pGameObject.lock(), Event::ScoreChanged);
}
