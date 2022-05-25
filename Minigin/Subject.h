#pragma once
#include <vector>
#include "Structs.h"

namespace dae
{
	class GameObject;
	class Observer;

	class Subject
	{
		public:
			void AddObserver(std::shared_ptr<Observer> observer);
			void RemoveObserver(std::shared_ptr<Observer> observer);

		protected:
			void Notify(const std::shared_ptr<GameObject> gameObject, Event event);

		private:
			std::vector<std::shared_ptr<Observer>> m_pObservers;
	};
}
