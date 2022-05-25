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

	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		~SceneManager();

		std::vector<std::shared_ptr<Scene>> m_Scenes;
	};
}
