#include "MiniginPCH.h"
#include "PeterPepperComponent.h"

dae::PeterPepperComponent::PeterPepperComponent(std::shared_ptr<GameObject> gameObject)
	:BaseComponent(gameObject)
	, m_score{0}
	, m_lives{3}
	, m_playerState{ PlayerState::Idle }

{
}

void dae::PeterPepperComponent::Update(float)
{
}

int dae::PeterPepperComponent::GetLives() const
{
	return m_lives;
}

void dae::PeterPepperComponent::LoseLive()
{
	if (m_lives > 0)
	{
		--m_lives;
	}

}

void dae::PeterPepperComponent::Die()
{
	Notify(m_pGameObject.lock(), Event::PlayerDied);

}

int dae::PeterPepperComponent::GetScore() const
{
	return m_score;
}

void dae::PeterPepperComponent::GivePoints(int points)
{
	m_score += points;
}

void dae::PeterPepperComponent::SetState(PlayerState state)
{
	m_playerState = state;
}
