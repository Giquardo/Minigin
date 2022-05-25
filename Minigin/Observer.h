#pragma once
#include "Structs.h"


namespace dae
{
	class GameObject;

	class Observer
	{
	public:
		Observer() = default;
		virtual ~Observer() = default;

		Observer(const Observer& other) = delete;
		Observer(Observer&& other) = delete;
		Observer& operator= (const Observer& other) = delete;
		Observer& operator= (const Observer&& other) = delete;

		virtual void Notify(const std::shared_ptr<GameObject> gameObject, Event event) = 0;
	};
}
