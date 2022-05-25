#pragma once
#include "BaseComponent.h"
#include "Subject.h"

namespace dae
{
	class PeterPepperComponent final : public BaseComponent, public Subject
	{
	public:
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

		void Die();
	};
}