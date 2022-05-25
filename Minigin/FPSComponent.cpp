#include "Font.h"
#include "Renderer.h"
#include "MiniginPCH.h"
#include "FPSComponent.h"
#include "TextComponent.h"
#include "GameObject.h"

dae::FPSComponent::FPSComponent(const std::string& text, const std::shared_ptr<Font>& font, std::shared_ptr<GameObject> gameObject)
	:BaseComponent{ gameObject }
{
	if (gameObject)
	{
		m_TextComponent = gameObject->GetComponent<TextComponent>();

		if (m_TextComponent == nullptr)
		{
			m_TextComponent = std::make_shared<TextComponent>(text, font, gameObject);
			gameObject->AddComponent(m_TextComponent);
		}
	}
}

void dae::FPSComponent::Update(float deltaTime)
{
	m_FPS = static_cast<int>(1.f / deltaTime);
	m_TextUpdateTimer += deltaTime;

	if (m_TextUpdateTimer >= 0.5f)
	{
		m_TextComponent->SetText(std::to_string(m_FPS) + " FPS");
		m_TextUpdateTimer = 0.f;
	}
}

void dae::FPSComponent::FixedUpdate(float )
{
}

void dae::FPSComponent::LateUpdate(float )
{
}

void dae::FPSComponent::Render() const
{
}

int dae::FPSComponent::GetFPS() const
{
	return m_FPS;
}

