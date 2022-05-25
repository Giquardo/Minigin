#pragma once
#include "Structs.h"
#include "BaseComponent.h"

namespace dae
{
	class TransformComponent;
	class Font;
	class Texture2D;
	class TextComponent final: public BaseComponent
	{
	public:
		explicit TextComponent(const std::string& text, const std::shared_ptr<Font>& font, std::shared_ptr<GameObject> gameObject
							 , const Color& color = { 255, 255, 255 });
		virtual ~TextComponent() = default;
		TextComponent(const TextComponent & other) = delete;
		TextComponent(TextComponent && other) = delete;
		TextComponent& operator=(const TextComponent & other) = delete;
		TextComponent& operator=(TextComponent && other) = delete;

		virtual void Update(float deltaTime) override;
		virtual void FixedUpdate(float deltaTime) override;
		virtual void LateUpdate(float deltaTime) override;
		virtual void Render() const override;

		void SetColor(const Color& color);
		void SetText(const std::string& text);

	private:
		Color m_Color{};
		bool m_NeedsUpdate{};
		std::string m_Text{};
		std::shared_ptr<Font> m_Font{};
		std::shared_ptr<Texture2D> m_Texture{};
		std::shared_ptr<TransformComponent> m_TransformComponent;

	};
}

