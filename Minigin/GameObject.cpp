#include "Renderer.h"
#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "BaseComponent.h"

void dae::GameObject::Update(float deltaTime)
{
	for (auto pComponent : m_pComponents)
	{
		pComponent->Update(deltaTime);
	}

	for (auto pChildren : m_pChildren)
	{
		pChildren->Update(deltaTime);
	}
}

void dae::GameObject::FixedUpdate(float deltaTime)
{
	for (auto pComponent : m_pComponents)
	{
		pComponent->FixedUpdate(deltaTime);
	}
	for (auto pChildren : m_pChildren)
	{
		pChildren->FixedUpdate(deltaTime);
	}
}

void dae::GameObject::LateUpdate(float deltaTime)
{
	for (auto pComponent : m_pComponents)
	{
		pComponent->LateUpdate(deltaTime);
	}
	for (auto pChildren : m_pChildren)
	{
		pChildren->LateUpdate(deltaTime);
	}
}

void dae::GameObject::Render() const
{
	for (auto pComponent : m_pComponents)
	{
		pComponent->Render();
	}
	for (auto pChildren : m_pChildren)
	{
		pChildren->Render();
	}
}

void dae::GameObject::AddComponent(std::shared_ptr<BaseComponent> component)
{
	m_pComponents.push_back(component);
}

void dae::GameObject::RemoveComponent(std::shared_ptr<BaseComponent> component)
{
	m_pComponents.erase(std::find(m_pComponents.begin(), m_pComponents.end(), component));
}

void dae::GameObject::SetParent(std::shared_ptr<GameObject> parent)
{
	if (m_pParent.lock().get() != nullptr)
	{
		for (size_t i = 0; i < m_pChildren.size(); ++i)
		{
			m_pParent.lock()->m_pChildren.erase(m_pParent.lock()->m_pChildren.begin(), m_pParent.lock()->m_pChildren.end());
		}
	}
	m_pParent = parent;

}

std::shared_ptr<dae::GameObject> dae::GameObject::GetParent() const
{
	return m_pParent.lock();
}

size_t dae::GameObject::GetChildCount() const
{
	return m_pChildren.size();
}

std::shared_ptr<dae::GameObject> dae::GameObject::GetChildAt(size_t idx) const
{
	if (idx < m_pChildren.size())
	{
		return m_pChildren[idx];
	}
	return nullptr;
}

void dae::GameObject::RemoveChild(size_t idx)
{
	if (GetChildAt(idx) != nullptr)
	{
	m_pChildren[idx]->SetParent(nullptr);
	m_pChildren.erase(std::find(m_pChildren.begin(), m_pChildren.end(), GetChildAt(idx)));
	}
}

void dae::GameObject::AddChild(std::shared_ptr<GameObject> child)
{
	child.get()->SetParent(m_pParent.lock());
	m_pChildren.push_back(child);
}
