#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"

std::shared_ptr<dae::Scene> dae::SceneManager::CreateScene(const std::string& name)
{
	const auto& newScene = std::shared_ptr<Scene>(new Scene(name));
	
	m_Scenes.push_back(newScene);
	return newScene;
}

void dae::SceneManager::FixedUpdate(float deltaTime)
{
	for (auto& scene : m_Scenes)
	{
		scene->FixedUpdate(deltaTime);
	}
}

void dae::SceneManager::Update(float deltaTime)
{
	for(auto& scene : m_Scenes)
	{
		scene->Update(deltaTime);
	}
}

void dae::SceneManager::LateUpdate(float deltaTime)
{
	for (auto& scene : m_Scenes)
	{
		scene->LateUpdate(deltaTime);
	}
}

void dae::SceneManager::Render() const
{
	for (const auto& scene : m_Scenes)
	{
		scene->Render();
	}
}

dae::SceneManager::~SceneManager()
{
}
