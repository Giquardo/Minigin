#pragma once
#include "BaseComponent.h"
#include "Subject.h"

namespace dae
{
	class PointsComponent final : public BaseComponent, public Subject
	{
	public:
		PointsComponent(std::shared_ptr<GameObject> gameObject);
		virtual ~PointsComponent() = default;

		PointsComponent(const PointsComponent& other) = delete;
		PointsComponent(PointsComponent&& other) = delete;
		PointsComponent& operator=(const PointsComponent& other) = delete;
		PointsComponent& operator=(PointsComponent&& other) = delete;

		virtual void Update(float deltaTime) override;
		virtual void FixedUpdate(float) override {};
		virtual void LateUpdate(float) override {};
		virtual void Render() const override {};

		int GetPoints() const;
		void AddPoints(int amount);
		void RemovePoints(int amount);

	private:
		int m_Points{};
	};
}