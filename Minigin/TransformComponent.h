#pragma once
#include "BaseComponent.h"

namespace dae
{
	class TransformComponent final : public BaseComponent
	{
	public:
		explicit TransformComponent(std::shared_ptr<GameObject> gameObject);
		virtual ~TransformComponent() = default;

		TransformComponent(const TransformComponent& other) = delete;
		TransformComponent(TransformComponent&& other) = delete;
		TransformComponent& operator=(const TransformComponent& other) = delete;
		TransformComponent& operator=(TransformComponent&& other) = delete;

		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(float x, float y, float z = 0.0f);
		void IncreaseY(float value);
		void DecreaseY(float value);

		virtual void Update(float) override {};
		virtual void FixedUpdate(float) override {};
		virtual void LateUpdate(float) override {};
		virtual void Render() const override{};

	private:
		glm::vec3 m_Position;
	};
}
