#pragma once
#include <SDL_rect.h>
#include "BaseComponent.h"

namespace dae
{
	class TransformComponent;
	class Texture2D;
	class TextureComponent final : public BaseComponent
	{
		public:
			explicit TextureComponent(std::shared_ptr<GameObject> gameObject);

			virtual ~TextureComponent() = default;
			TextureComponent(const TextureComponent& other) = delete;
			TextureComponent(TextureComponent&& other) = delete;
			TextureComponent& operator=(const TextureComponent& other) = delete;
			TextureComponent& operator=(TextureComponent&& other) = delete;


			virtual void Update(float deltaTime) override;
			virtual void FixedUpdate(float deltaTime) override;
			virtual void LateUpdate(float deltaTime) override;
			virtual void Render() const override;

			void SetTexture(const std::string& filename);
			void SetScale(float xScale, float yScale);

		private:
			std::shared_ptr<Texture2D> m_Texture;
			SDL_Rect m_Source, m_Destination;
			glm::vec2 m_Scale;
			std::shared_ptr<TransformComponent> m_TransformComponent{};

	};
}