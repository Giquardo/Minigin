#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"

std::shared_ptr<dae::Scene> dae::SceneManager::CreateScene(const std::string& name)
{
	const auto& newScene = std::shared_ptr<Scene>(new Scene(name));
	m_Scenes.push_back(newScene);
	SetActiveScene(name);
	return newScene;
}

void dae::SceneManager::FixedUpdate(float deltaTime)
{
	const size_t size{ m_Scenes.size() };
	for (size_t i{}; i < size; i++)
	{
		if (i == m_ActiveScene)
			m_Scenes[i]->FixedUpdate(deltaTime);
	}

	/*for (auto& scene : m_Scenes)
	{
		scene->FixedUpdate(deltaTime);
	}*/
}

void dae::SceneManager::Update(float deltaTime)
{
	const size_t size{ m_Scenes.size() };
	for (size_t i{}; i < size; i++)
	{
		if (i == m_ActiveScene)
			m_Scenes[i]->Update(deltaTime);
	}
	/*for(auto& scene : m_Scenes)
	{
		scene->Update(deltaTime);
	}*/
}

void dae::SceneManager::LateUpdate(float deltaTime)
{
	const size_t size{ m_Scenes.size() };
	for (size_t i{}; i < size; i++)
	{
		if (i == m_ActiveScene)
			m_Scenes[i]->LateUpdate(deltaTime);
	}
	/*for (auto& scene : m_Scenes)
	{
		scene->LateUpdate(deltaTime);
	}*/
}

void dae::SceneManager::Render() const
{
	const size_t size{ m_Scenes.size() };
	for (size_t i{}; i < size; i++)
	{
		if (i == m_ActiveScene)
			m_Scenes[i]->Render();
	}
	/*for (const auto& scene : m_Scenes)
	{
		scene->Render();
	}*/
}

void dae::SceneManager::SetActiveScene(const std::string& name)
{
	for (size_t i{}; i < m_Scenes.size(); ++i)
	{
		if (m_Scenes[i]->GetName()._Equal(name))
		{
			m_ActiveScene = static_cast<int>(i);
			return;
		}
	}
}

dae::SceneManager::~SceneManager()
{
}


