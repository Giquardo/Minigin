#pragma once
#include "Singleton.h"

namespace dae
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		std::shared_ptr<Scene> CreateScene(const std::string& name);

		void FixedUpdate(float deltaTime);
		void Update(float deltaTime);
		void LateUpdate(float deltaTime);
		void Render() const;
		void SetActiveScene(const std::string& name);

	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		~SceneManager();

		int m_ActiveScene{};
		std::vector<std::shared_ptr<Scene>> m_Scenes;
	};
}
