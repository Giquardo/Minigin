#pragma once
#include "SceneManager.h"

namespace dae
{
	class GameObject;
	class Scene
	{
		friend std::shared_ptr<Scene> SceneManager::CreateScene(const std::string& name);
	public:
		void Add(const std::shared_ptr<GameObject>& object);

		void Update(float deltaTime);
		void FixedUpdate(float deltaTime); 
		void LateUpdate(float deltaTime);
		void Render() const;

		~Scene() = default;
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

		std::string GetName() const;


	private: 
		explicit Scene(const std::string& name);

		std::string m_Name;
		std::vector < std::shared_ptr<GameObject>> m_Objects{};

		static unsigned int m_IdCounter; 
	};

}
