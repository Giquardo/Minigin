#include "MiniginPCH.h"
#include "TextComponent.h"
#include "Renderer.h"
#include <SDL_ttf.h>
#include "GameObject.h"
#include "Font.h"
#include "Texture2D.h"
#include "TransformComponent.h"

dae::TextComponent::TextComponent(const std::string& text, const std::shared_ptr<Font>& font, std::shared_ptr<GameObject> gameObject, const Color& color)
	: BaseComponent(gameObject)
	, m_NeedsUpdate(true)
	, m_Text(text)
	, m_Font(font)
	, m_Color(color)
	, m_Texture(nullptr)
{
	m_TransformComponent = gameObject->GetComponent<TransformComponent>();

	if (m_TransformComponent == nullptr)
	{
		m_TransformComponent = std::make_shared<TransformComponent>(gameObject);
		gameObject->AddComponent(m_TransformComponent);
	}
}

void dae::TextComponent::Update(float)
{
	if (m_NeedsUpdate)
	{
		const SDL_Color color = { m_Color.r ,m_Color.g ,m_Color.b };

		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_Texture = std::make_shared<Texture2D>(texture);
		m_NeedsUpdate = false;
	}
}

void dae::TextComponent::FixedUpdate(float)
{
}

void dae::TextComponent::LateUpdate(float)
{
}

void dae::TextComponent::Render() const
{

	const auto& pos = m_TransformComponent->GetPosition();
	Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
}

void dae::TextComponent::SetColor(const Color& color)
{
	m_Color = color;
}

void dae::TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}
