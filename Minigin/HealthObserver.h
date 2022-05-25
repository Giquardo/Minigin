#pragma once
#include "Observer.h"

namespace dae
{

	class HealthObserver final : public Observer
	{
	public:
		void Notify(const std::shared_ptr<GameObject> gameObject, Event event) override;
	};

}

