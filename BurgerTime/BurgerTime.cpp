#include "pch.h"
#include "BurgerTime.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Scene.h"
#include "Commands.h"

//-------components---------
#include "TextureComponent.h"
#include "TextComponent.h"
#include "FPSComponent.h"
#include "HealthComponent.h"
#include "PeterPepperComponent.h"
#include "PointsComponent.h"

//--------------------------


void dae::BurgerTime::LoadGame() const
{
	auto scene = SceneManager::GetInstance().CreateScene("Demo");

	//Background
	auto backgroundObject = std::make_shared<GameObject>();
	auto textureComp = std::make_shared<TextureComponent>(backgroundObject);
	textureComp->SetScale(2.f, 2.f);
	textureComp->SetTexture("background.jpg");
	backgroundObject->AddComponent(textureComp);
	scene->Add(backgroundObject);

	//Logo
	auto logoObject = std::make_shared<GameObject>();
	auto logoTextureComp = std::make_shared<TextureComponent>(logoObject);
	logoTextureComp->SetScale(2.f, 2.f);
	logoTextureComp->SetTexture("logo.png");
	logoObject->AddComponent(logoTextureComp);
	logoObject->GetComponent<TransformComponent>()->SetPosition(432, 360);
	backgroundObject->AddChild(logoObject);
	//scene->Add(logoObject);

	//Text
	auto textObject = std::make_shared<GameObject>();
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto textComponent = std::make_shared<TextComponent>("Programming 4 Assignment", font, textObject, Color{ 255, 0, 0 });
	textObject->AddComponent(textComponent);
	textObject->GetComponent<TransformComponent>()->SetPosition(80, 20);
	backgroundObject->AddChild(textObject);
	//scene->Add(textObject);


	//FPS Counter
	auto FPSObject = std::make_shared<GameObject>();
	font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	const auto fpsComponent = std::make_shared<FPSComponent>("FpsCounter", font, FPSObject);
	FPSObject->GetComponent<TextComponent>()->SetColor({ 255,255,0 });
	FPSObject->AddComponent(fpsComponent);
	FPSObject->GetComponent<TransformComponent>()->SetPosition(10, 5);
	backgroundObject->AddChild(FPSObject);

	scene->Add(backgroundObject);

	// add commands to controller
	auto& input = InputManager::GetInstance();
	input.SetButtonCommand(0, XboxController::ControllerButton::ButtonA, new JumpCommand(), InputState::Down);
	input.SetButtonCommand(0, XboxController::ControllerButton::ButtonB, new FireCommand(), InputState::Pressed);
	input.SetButtonCommand(0, XboxController::ControllerButton::ButtonX, new FartCommand(), InputState::Up);
	input.SetButtonCommand(0, XboxController::ControllerButton::ButtonY, new DuckCommand(), InputState::Down);

	// P1
	font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 30);

	auto playerObj1 = std::make_shared<GameObject>();
	auto peter = std::make_shared<PeterPepperComponent>(playerObj1);
	playerObj1->AddComponent(peter);
	auto P1Text = std::make_shared<TextComponent>("P1", font, playerObj1, Color(0, 255, 0));
	playerObj1->AddComponent(P1Text);
	playerObj1->GetComponent<TransformComponent>()->SetPosition(100, 150);
	scene->Add(playerObj1);

	// Points P1
	auto PointsObj = std::make_shared<GameObject>();
	auto points = std::make_shared<PointsComponent>(PointsObj);
	PointsObj->AddComponent(points);
	auto pointsText = std::make_shared<TextComponent>(("Points: " + std::to_string(points->GetPoints())), font, PointsObj, Color(0, 255, 0));
	PointsObj->AddComponent(pointsText);
	PointsObj->GetComponent<TransformComponent>()->SetPosition(100, 200);
	scene->Add(PointsObj);

	// Lives P1
	int maxLives{ 3 };
	auto HealthObj = std::make_shared<GameObject>();
	auto healthComp = std::make_shared<HealthComponent>(HealthObj, maxLives);
	HealthObj->AddComponent(healthComp);
	auto livesText = std::make_shared<TextComponent>(("Lives: " + std::to_string(healthComp->GetLives())), font, HealthObj, Color(0, 255, 0));
	HealthObj->AddComponent(livesText);
	HealthObj->GetComponent<TransformComponent>()->SetPosition(100, 250);
	scene->Add(HealthObj);

	// P2
	auto playerObj2 = std::make_shared<GameObject>();
	auto peter2 = std::make_shared<PeterPepperComponent>(playerObj2);
	playerObj2->AddComponent(peter2);
	auto P2Text = std::make_shared<TextComponent>("P2", font, playerObj2, Color(0, 255, 0));
	playerObj2->AddComponent(P2Text);
	playerObj2->GetComponent<TransformComponent>()->SetPosition(100, 400);
	scene->Add(playerObj2);

	// Points P2
	auto PointsObj2 = std::make_shared<GameObject>();
	auto points2 = std::make_shared<PointsComponent>(PointsObj2);
	PointsObj2->AddComponent(points2);
	auto pointsText2 = std::make_shared<TextComponent>(("Points: " + std::to_string(points2->GetPoints())), font, PointsObj2, Color(0, 255, 0));
	PointsObj2->AddComponent(pointsText2);
	PointsObj2->GetComponent<TransformComponent>()->SetPosition(100, 450);
	scene->Add(PointsObj2);

	// Lives P2
	int maxLives2{ 3 };
	auto HealthObj2 = std::make_shared<GameObject>();
	auto healthComp2 = std::make_shared<HealthComponent>(HealthObj2, maxLives2);
	HealthObj2->AddComponent(healthComp2);
	auto livesText2 = std::make_shared<TextComponent>(("Lives: " + std::to_string(healthComp2->GetLives())), font, HealthObj2, Color(0, 255, 0));
	HealthObj2->AddComponent(livesText2);
	HealthObj2->GetComponent<TransformComponent>()->SetPosition(100, 500);
	scene->Add(HealthObj2);

	// commands input players
	input.SetButtonCommand(0, XboxController::ControllerButton::Dpad_Up, new DamageCommand(HealthObj), InputState::Down);
	input.SetButtonCommand(0, XboxController::ControllerButton::Dpad_Right, new DamageCommand(HealthObj2), InputState::Down);
	input.SetButtonCommand(0, XboxController::ControllerButton::Dpad_Down, new IncreasePointsCommand(PointsObj), InputState::Down);
	input.SetButtonCommand(0, XboxController::ControllerButton::Dpad_Left, new IncreasePointsCommand(PointsObj2), InputState::Down);

}


