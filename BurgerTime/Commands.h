#pragma once
#include <iostream>
#include "PeterPepperComponent.h"
#include "HealthComponent.h"
#include "PointsComponent.h"
#include "GameObject.h"
#include "Command.h"
#include "ServiceLocator.h"
#include "ButtonComponent.h"
#include "BurgerTime.h"

namespace dae
{

	class FireCommand final : public Command
	{
	public:
		void Execute() override { Fire(); }
	private:
		void Fire() { std::cout << "Fire \n"; };
	};

	class DuckCommand final : public Command
	{
	public:
		void Execute() override { Duck(); }
	private:
		void Duck() { std::cout << "Duck \n"; };
	};

	class JumpCommand final : public Command
	{
	public:
		void Execute() override { Jump(); }

	private:
		void Jump() { std::cout << "Jump \n"; };
	};

	class FartCommand final : public Command
	{
	public:
		void Execute() override { Fart(); }

	private:
		void Fart() { std::cout << "Fart \n"; };
	};

	class DamageCommand final : public Command
	{
	public:
		DamageCommand(std::shared_ptr<GameObject> pGameObject) 
			:m_HealthObject{ pGameObject } 
		{
		};

		void Execute() override
		{
			auto healthComp = m_HealthObject->GetComponent<HealthComponent>();
			if (healthComp)
			{
				healthComp->DecreaseLives();
				std::cout << "Lost Life \n";
			}
		}

	private:
		std::shared_ptr<GameObject> m_HealthObject;
	};

	class IncreasePointsCommand final : public Command
	{
	public:
		IncreasePointsCommand(std::shared_ptr<GameObject> pGameObject)
			:m_PointsObject{ pGameObject } 
		{
		};

		void Execute() override 
		{ 
			auto pointsComp = m_PointsObject->GetComponent<PointsComponent>();
			pointsComp->AddPoints(50);

			std::cout << "+50 Points \n";
		}

	private:
		std::shared_ptr<GameObject> m_PointsObject;
	};

	class PlaySound : public Command
	{
	public:
		PlaySound(const std::string& path)
			:m_Path{path}
		{
		}
		void Execute() override
		{
			dae::ServiceLocator::GetSoundManager()->QueueAudio(m_Path);
		};
	private:
		const std::string m_Path;
	};

	class SelectNext final : public Command
	{
	public:
		SelectNext(std::shared_ptr<GameObject> pGameObject)
			:m_ButtonObject{ pGameObject }
		{
		};

		void Execute() override
		{
			auto buttonComp = m_ButtonObject->GetComponent<ButtonComponent>();
			buttonComp->SelectNext();
			std::cout << "Selected Next \n";
		}

	private:
		std::shared_ptr<GameObject> m_ButtonObject;
	};

	class SelectPrev final : public Command
	{
	public:
		SelectPrev(std::shared_ptr<GameObject> pGameObject)
			:m_ButtonObject{ pGameObject }
		{
		};

		void Execute() override
		{
			auto buttonComp = m_ButtonObject->GetComponent<ButtonComponent>();
			buttonComp->SelectPrev();
			std::cout << "Selected Prev \n";
		}

	private:
		std::shared_ptr<GameObject> m_ButtonObject;
	};

	class Confirm final : public Command
	{
	public:
		Confirm(std::shared_ptr<GameObject> pGameObject)
			:m_ButtonObject{ pGameObject }
		{
		};

		void Execute() override
		{
			dae::BurgerTime::SetMode(m_ButtonObject->GetComponent<ButtonComponent>()->GetSelected());
			std::cout << "confirmed \n";
			SceneManager::GetInstance().SetActiveScene("Demo");
			InputManager::GetInstance().InMenu(false);
		}

	private:
		std::shared_ptr<GameObject> m_ButtonObject;
	};

	class OpenMenu final : public Command
	{
	public:
		OpenMenu()
		{
		};

		void Execute() override
		{
			SceneManager::GetInstance().SetActiveScene("MainMenu");
			InputManager::GetInstance().InMenu(true);
		}

	private:
	};
}