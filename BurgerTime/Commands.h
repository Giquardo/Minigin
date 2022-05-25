#pragma once
#include <iostream>
#include "PeterPepperComponent.h"
#include "HealthComponent.h"
#include "PointsComponent.h"
#include "GameObject.h"
#include "Command.h"

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
}