#pragma once
#include "BaseComponent.h"
#include "Subject.h"

namespace dae
{
	class HealthComponent final : public BaseComponent, public Subject
	{
	public:
		HealthComponent(std::shared_ptr<GameObject> gameObject, int maxLives);
		virtual ~HealthComponent() = default;

		HealthComponent(const HealthComponent& other) = delete;
		HealthComponent(HealthComponent&& other) = delete;
		HealthComponent& operator=(const HealthComponent& other) = delete;
		HealthComponent& operator=(HealthComponent&& other) = delete;

		virtual void Update(float deltaTime) override;
		virtual void FixedUpdate(float) override {};
		virtual void LateUpdate(float) override {};
		virtual void Render() const override {};

		void DecreaseLives();
		void IncreaseLives();

		int GetLives() const;
		bool GetIsDead() const;

	private:
		int m_MaxLives{};
		int m_CurrentLives{};
		bool m_IsDead{ false };
	};
}
