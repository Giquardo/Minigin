#pragma once
#include <string>
#include "Structs.h"
#include "BaseComponent.h"

namespace dae
{
	class Font;
	class TextComponent;
	class GameObject;

	class FPSComponent final : public BaseComponent
	{
		public:

			explicit FPSComponent(const std::string& text, const std::shared_ptr<Font>& font, std::shared_ptr<GameObject> gameObject);
			virtual ~FPSComponent() = default;
			FPSComponent(const FPSComponent& other) = delete;
			FPSComponent(FPSComponent&& other) = delete;
			FPSComponent& operator=(const FPSComponent& other) = delete;
			FPSComponent& operator=(FPSComponent&& other) = delete;

			virtual void Update(float deltaTime) override;
			virtual void FixedUpdate(float) override;
			virtual void LateUpdate(float) override;
			virtual void Render() const override;

			int GetFPS() const;

		private:
			int m_FPS{ 0 };
			float m_TextUpdateTimer{};
			std::shared_ptr<TextComponent> m_TextComponent{};
	};
}


