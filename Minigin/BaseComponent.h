#pragma once
namespace dae
{
	class GameObject;
	class BaseComponent
	{
		public:
			BaseComponent(std::shared_ptr<GameObject> gameObject);
			virtual ~BaseComponent();

			BaseComponent(const BaseComponent& other) = delete;
			BaseComponent(BaseComponent&& other) = delete;
			BaseComponent& operator=(const BaseComponent& other) = delete;
			BaseComponent& operator=(BaseComponent&& other) = delete;

			virtual void FixedUpdate(float deltaTime) = 0;
			virtual void Update(float) {};
			virtual void LateUpdate(float) {};
			virtual void Render() const {};

		protected:
			std::weak_ptr<GameObject> m_pGameObject;

	};
}

