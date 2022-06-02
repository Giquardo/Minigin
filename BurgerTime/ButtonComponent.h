#pragma once
#include "pch.h"
#include "BaseComponent.h"
#include "Structs.h"

namespace dae
{
	class GameObject;
	class ButtonComponent final : public BaseComponent
	{
	public:
		explicit ButtonComponent(std::shared_ptr<GameObject> gameObject);
		virtual ~ButtonComponent() = default;

		ButtonComponent(const ButtonComponent&) = delete;
		ButtonComponent(ButtonComponent&&) = delete;
		ButtonComponent& operator= (const ButtonComponent&) = delete;
		ButtonComponent& operator= (const ButtonComponent&&) = delete;

		virtual void Update(float deltaTime) override;
		virtual void FixedUpdate(float) override;
		virtual void LateUpdate(float) override;
		virtual void Render() const override;

		void SelectNext();
		void SelectPrev();

		GameMode GetSelected();

	private:
		GameMode m_currentSelected;
	};
}

