#include "MiniginPCH.h"
#include "Subject.h"
#include "GameObject.h"
#include "Observer.h"

void dae::Subject::AddObserver(std::shared_ptr<Observer> observer)
{
	m_pObservers.push_back(observer);
}

void dae::Subject::RemoveObserver(std::shared_ptr<Observer> observer)
{
	m_pObservers.erase(std::find(m_pObservers.begin(), m_pObservers.end(), observer));
}

void dae::Subject::Notify(const std::shared_ptr<GameObject> gameObject,  Event event)
{
	for (auto observer : m_pObservers)
	{
		observer->Notify(gameObject, event);
	}
}
