#pragma once
#include <map>
#include "TransformComponent.h"

namespace dae
{
	class Texture2D;
	class BaseComponent;

	class GameObject final
	{
	public:
		GameObject() = default;
		virtual ~GameObject() = default;
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void Update(float deltaTime);
		void FixedUpdate(float deltaTime);
		void LateUpdate(float deltaTime);

		void Render() const;

		//components

		void AddComponent(std::shared_ptr<BaseComponent> component);
		void RemoveComponent(std::shared_ptr<BaseComponent> component);

		template<typename T>
		std::shared_ptr<T> GetComponent() const
		{
			for (auto component : m_pComponents)
			{
				std::shared_ptr<T> castedComp = std::dynamic_pointer_cast<T>(component);

				if (castedComp != nullptr)
				{
					return castedComp;
				}
			}
			return nullptr;
		}

		//parent

		void SetParent(std::shared_ptr<GameObject> parent);
		std::shared_ptr<GameObject> GetParent() const;

		//children

		size_t GetChildCount() const;
		std::shared_ptr<GameObject> GetChildAt(size_t idx) const;
		void RemoveChild(size_t idx);
		void AddChild(std::shared_ptr<GameObject> child);

	private:
		std::weak_ptr<GameObject> m_pParent;
		std::vector<std::shared_ptr<GameObject>> m_pChildren;
		std::vector<std::shared_ptr<BaseComponent>> m_pComponents;

	};

}
