#include "MiniginPCH.h"
#include "HealthComponent.h"
#include "TextComponent.h"
#include "GameObject.h"
dae::HealthComponent::HealthComponent(std::shared_ptr<GameObject> gameObject, int maxLives)
	:BaseComponent{ gameObject }
	,m_MaxLives{ maxLives }
	,m_CurrentLives{ maxLives }
{
}

void dae::HealthComponent::Update(float)
{
}

void dae::HealthComponent::DecreaseLives()
{
	--m_CurrentLives;
	if (m_CurrentLives <= 0)
	{
		m_IsDead = true;
	}
	m_pGameObject.lock().get()->GetComponent<TextComponent>()->SetText("Lives: " + std::to_string(m_CurrentLives));
	Notify(m_pGameObject.lock(), Event::LivesChanged);
}

void dae::HealthComponent::IncreaseLives()
{
	if (m_CurrentLives < m_MaxLives)
	{
		++m_CurrentLives;
		Notify(m_pGameObject.lock(), Event::LivesChanged);
		m_pGameObject.lock().get()->GetComponent<TextComponent>()->SetText("Lives: " + std::to_string(m_CurrentLives));
	}
}

int dae::HealthComponent::GetLives() const
{
	return m_CurrentLives;
}

bool dae::HealthComponent::GetIsDead() const
{
	return m_IsDead;
}
