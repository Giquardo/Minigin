#include "MiniginPCH.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "Texture2D.h"
#include "GameObject.h"
#include "Renderer.h"
#include "TransformComponent.h"

dae::TextureComponent::TextureComponent(std::shared_ptr<GameObject> gameObject)
	: BaseComponent(gameObject)
	, m_Source()
	, m_Destination()
	, m_Texture()
	, m_Scale(1.f, 1.f)
{

	m_TransformComponent = gameObject->GetComponent<TransformComponent>();

	if (m_TransformComponent == nullptr)
	{
		m_TransformComponent = std::make_shared<TransformComponent>(gameObject);
		gameObject->AddComponent(m_TransformComponent);
	}

}

void dae::TextureComponent::SetTexture(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);

	SDL_QueryTexture(m_Texture->GetSDLTexture(), nullptr, nullptr, &m_Source.w, &m_Source.h);
	m_Destination.w = static_cast<int>(m_Source.w * m_Scale.x);
	m_Destination.h = static_cast<int>(m_Source.h * m_Scale.y);
}

void dae::TextureComponent::SetScale(float xScale, float yScale)
{
	m_Scale.x = xScale;
	m_Scale.y = yScale;
}


void dae::TextureComponent::Update(float)
{
}

void dae::TextureComponent::FixedUpdate(float)
{
}

void dae::TextureComponent::LateUpdate(float)
{
}

void dae::TextureComponent::Render() const
{
	if (m_Texture)
	{
		const auto& pos = m_TransformComponent->GetPosition();
		Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y, m_Source, m_Destination);
	}
}