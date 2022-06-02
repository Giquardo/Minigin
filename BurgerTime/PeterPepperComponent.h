#pragma once
#include "BaseComponent.h"
#include "Subject.h"
#include "Structs.h"

namespace dae
{
	class PeterPepperComponent final : public BaseComponent, public Subject
	{
	public:
		class RenderComponent;
		class TransformComponent;

		enum class PlayerState
		{
			Idle,
			MovingRight,
			MovingLeft,
			ClimbingUp,
			ClimbingDown,
			ThrowingSaltRight,
			ThrowingSaltLeft,
			Died
		};

		PeterPepperComponent(std::shared_ptr<GameObject> gameObject);
		virtual ~PeterPepperComponent() = default;

		PeterPepperComponent(const PeterPepperComponent&) = delete;
		PeterPepperComponent(PeterPepperComponent&&) = delete;
		PeterPepperComponent& operator= (const PeterPepperComponent&) = delete;
		PeterPepperComponent& operator= (const PeterPepperComponent&&) = delete;

		virtual void Update(float deltaTime) override;
		virtual void FixedUpdate(float) override {};
		virtual void LateUpdate(float) override {};
		virtual void Render() const override {};

		int GetLives()const;
		void LoseLive();
		void Die();

		int GetScore()const;
		void GivePoints(int points);

		void SetState(PlayerState state);

	private:

		int m_score;
		int m_lives;
		PlayerState m_playerState;

		std::shared_ptr<TransformComponent> m_pTransformComponent{};
		std::shared_ptr<RenderComponent> m_pRenderComponent{};


	};
}