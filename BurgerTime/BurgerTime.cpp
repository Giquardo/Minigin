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
#include "ButtonComponent.h"
//--------------------------
GameMode dae::BurgerTime::m_CurrentMode{};

void dae::BurgerTime::LoadGame()
{
	LoadMainMenu();
	LoadLevel01();

	SceneManager::GetInstance().SetActiveScene("MainMenu");
	InputManager::GetInstance().InMenu(true);
}

void dae::BurgerTime::SetMode(GameMode newMode)
{
	m_CurrentMode = newMode;
}

void dae::BurgerTime::LoadMainMenu()
{
	m_ActiveScene = SceneManager::GetInstance().CreateScene("MainMenu");

	//Title
	auto mainMenuObject = std::make_shared<GameObject>();
	auto textureComp = std::make_shared<TextureComponent>(mainMenuObject);
	textureComp->SetScale(3.f, 3.f);
	textureComp->SetTexture("BurgerTimeTitle.png");
	mainMenuObject->AddComponent(textureComp);
	auto TransformComp = std::make_shared<TransformComponent>(mainMenuObject);
	mainMenuObject->AddComponent(TransformComp);
	mainMenuObject->GetComponent<TransformComponent>()->SetPosition(450, 20);
	m_ActiveScene->Add(mainMenuObject);

	//Button
	auto buttonObject = std::make_shared<GameObject>();
	auto buttonTextureComp = std::make_shared<TextureComponent>(buttonObject);
	buttonTextureComp->SetScale(3.f, 3.f);
	buttonTextureComp->SetTexture("Arrow.png");
	buttonObject->AddComponent(buttonTextureComp);
	auto buttonComp = std::make_shared<ButtonComponent>(buttonObject);
	buttonObject->AddComponent(buttonComp);
	auto buttonTransformComp = std::make_shared<TransformComponent>(buttonObject);
	buttonObject->AddComponent(buttonTransformComp);
	switch (buttonObject->GetComponent<ButtonComponent>()->GetSelected())
	{
	case GameMode::Solo:
		buttonObject->GetComponent<TransformComponent>()->SetPosition(550, 355);
		break;
	case GameMode::CoOp:
		buttonObject->GetComponent<TransformComponent>()->SetPosition(550, 455);
		break;
	case GameMode::Versus:
		buttonObject->GetComponent<TransformComponent>()->SetPosition(550, 555);
		break;
	default:
		break;
	}
	m_ActiveScene->Add(buttonObject);

	//SoloText
	auto soloModeObject = std::make_shared<GameObject>();
	auto font = ResourceManager::GetInstance().LoadFont("Retro_Bold.otf", 36);
	auto textComponent = std::make_shared<TextComponent>("SOLO", font, soloModeObject, Color{ 255, 255, 255 });
	soloModeObject->AddComponent(textComponent);
	auto TransformSoloComp = std::make_shared<TransformComponent>(soloModeObject);
	soloModeObject->AddComponent(TransformSoloComp);
	soloModeObject->GetComponent<TransformComponent>().get()->SetPosition(600, 350);
	m_ActiveScene->Add(soloModeObject);
	
	//CoOpText
	auto coOpModeObject = std::make_shared<GameObject>();
	textComponent = std::make_shared<TextComponent>("CO-OP", font, coOpModeObject, Color{ 255, 255, 255 });
	coOpModeObject->AddComponent(textComponent);
	auto TransformCoOPComp = std::make_shared<TransformComponent>(coOpModeObject);
	coOpModeObject->AddComponent(TransformCoOPComp);
	coOpModeObject->GetComponent<TransformComponent>().get()->SetPosition(600, 450);
	m_ActiveScene->Add(coOpModeObject);
	
	//VersusText
	auto versusModeObject = std::make_shared<GameObject>();
	textComponent = std::make_shared<TextComponent>("VERSUS", font, versusModeObject, Color{ 255, 255, 255 });
	versusModeObject->AddComponent(textComponent);
	TransformComp = std::make_shared<TransformComponent>(versusModeObject);
	versusModeObject->AddComponent(TransformComp);
	versusModeObject->GetComponent<TransformComponent>().get()->SetPosition(600, 550);
	m_ActiveScene->Add(versusModeObject);
	
	//input
	auto& input = InputManager::GetInstance();
	input.SetMenuButtonCommand(0, XboxController::ControllerButton::Dpad_Down, new SelectNext(buttonObject), InputState::Down);
	input.SetMenuButtonCommand(0, XboxController::ControllerButton::Dpad_Up, new SelectPrev(buttonObject), InputState::Down);
	input.SetMenuButtonCommand(0, XboxController::ControllerButton::ButtonB, new Confirm(buttonObject), InputState::Down);

}

void dae::BurgerTime::LoadLevel01()
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

	//FPS Counter
	auto FPSObject = std::make_shared<GameObject>();
	auto font = ResourceManager::GetInstance().LoadFont("Retro.otf", 20);
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
	font = ResourceManager::GetInstance().LoadFont("Retro.otf", 30);

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

	// commands input players
	input.SetButtonCommand(0, XboxController::ControllerButton::Dpad_Up, new DamageCommand(HealthObj), InputState::Down);
	input.SetButtonCommand(0, XboxController::ControllerButton::Dpad_Down, new IncreasePointsCommand(PointsObj), InputState::Down);

	input.SetButtonCommand(0, XboxController::ControllerButton::RightShoulder, new PlaySound("../Data/Sound/Game_Music.mp3"), InputState::Down);

	input.SetButtonCommand(0, XboxController::ControllerButton::GamepadStart, new OpenMenu(), InputState::Down);
}
