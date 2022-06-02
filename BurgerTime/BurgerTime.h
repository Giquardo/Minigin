#pragma once
#include "Minigin.h"
#include "pch.h"

namespace dae
{
	enum class Scenes
	{
		Main_Menu,
		Level_01,
		Level_02,
		Level_03,
	}; 

	class Scene;
	class BurgerTime final : public Minigin
	{
	public:
		void LoadGame() override;
		
		static void SetMode(GameMode newMode);

	private:
		void LoadMainMenu();
		void LoadLevel01();

		std::shared_ptr<Scene> m_ActiveScene{ nullptr };
		static GameMode m_CurrentMode;
	};

}