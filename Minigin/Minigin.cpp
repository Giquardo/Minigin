#include "MiniginPCH.h"
#include "Minigin.h"
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Scene.h"
#include <chrono>
#include "ServiceLocator.h"

//-------components---------
#include "TextureComponent.h"
#include "TextComponent.h"
#include "FPSComponent.h"

//--------------------------

using namespace std;

void PrintSDLVersion()
{
	SDL_version compiled{};
	SDL_version linked{};

	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);
	printf("We compiled against SDL version %d.%d.%d ...\n",
		compiled.major, compiled.minor, compiled.patch);
	printf("We are linking against SDL version %d.%d.%d.\n",
		linked.major, linked.minor, linked.patch);
}

void dae::Minigin::Initialize()
{
	PrintSDLVersion();
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		m_WindowSize.x,
		m_WindowSize.y,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);

	ServiceLocator::RegisterSoundManager(std::make_shared<SoundManager>());	
}

/**
 * Code constructing the scene world starts here
 */
void dae::Minigin::LoadGame() const
{
	//auto scene = SceneManager::GetInstance().CreateScene("Demo");

	////Background
	//auto backgroundObject = std::make_shared<GameObject>();
	//auto textureComp = std::make_shared<TextureComponent>(backgroundObject);
	//textureComp->SetScale(2.f, 2.f);
	//textureComp->SetTexture("background.jpg");
	//backgroundObject->AddComponent(textureComp);
	//scene->Add(backgroundObject);

	////Logo
	//auto logoObject = std::make_shared<GameObject>();
	//auto logoTextureComp = std::make_shared<TextureComponent>(logoObject);
	//logoTextureComp->SetScale(2.f, 2.f);
	//logoTextureComp->SetTexture("logo.png");
	//logoObject->AddComponent(logoTextureComp);
	//logoObject->GetComponent<TransformComponent>()->SetPosition(432, 360);
	//backgroundObject->AddChild(logoObject);
	////scene->Add(logoObject);

	////Text
	//auto textObject = std::make_shared<GameObject>();
	//auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//auto textComponent = std::make_shared<TextComponent>("Programming 4 Assignment", font, textObject, Color{ 255, 0, 0 });
	//textObject->AddComponent(textComponent);
	//textObject->GetComponent<TransformComponent>()->SetPosition(80, 20);
	//backgroundObject->AddChild(textObject);
	////scene->Add(textObject);


	////FPS Counter
	//auto FPSObject = std::make_shared<GameObject>();
	//font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	//const auto fpsComponent = std::make_shared<FPSComponent>("FpsCounter", font, FPSObject);
	//FPSObject->GetComponent<TextComponent>()->SetColor({ 255,255,0 });
	//FPSObject->AddComponent(fpsComponent);
	//FPSObject->GetComponent<TransformComponent>()->SetPosition(10, 5);
	//backgroundObject->AddChild(FPSObject);

	//scene->Add(backgroundObject);
	//
	//// add commands to controller
	//auto& input = InputManager::GetInstance();
	//input.SetButtonCommand(0, XboxController::ControllerButton::ButtonA, new JumpCommand(), InputState::Down);
	//input.SetButtonCommand(0, XboxController::ControllerButton::ButtonB, new FireCommand(), InputState::Pressed);
	//input.SetButtonCommand(0, XboxController::ControllerButton::ButtonX, new FartCommand(), InputState::Up);
	//input.SetButtonCommand(0, XboxController::ControllerButton::ButtonY, new DuckCommand(), InputState::Down);

	//// P1
	//font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 30);

	//auto playerObj1 = std::make_shared<GameObject>();
	//auto peter = std::make_shared<PeterPepperComponent>(playerObj1);
	//playerObj1->AddComponent(peter);
	//auto P1Text = std::make_shared<TextComponent>("P1", font, playerObj1, Color(0, 255, 0));
	//playerObj1->AddComponent(P1Text);
	//playerObj1->GetComponent<TransformComponent>()->SetPosition(100, 150);
	//scene->Add(playerObj1);

	//// Points P1
	//auto PointsObj = std::make_shared<GameObject>();
	//auto points = std::make_shared<PointsComponent>(PointsObj);
	//PointsObj->AddComponent(points);
	//auto pointsText = std::make_shared<TextComponent>(("Points: " + std::to_string(points->GetPoints())), font, PointsObj, Color(0, 255, 0));
	//PointsObj->AddComponent(pointsText);
	//PointsObj->GetComponent<TransformComponent>()->SetPosition(100, 200);
	//scene->Add(PointsObj);

	//// Lives P1
	//int maxLives{3};
	//auto HealthObj = std::make_shared<GameObject>();
	//auto healthComp = std::make_shared<HealthComponent>(HealthObj, maxLives);
	//HealthObj->AddComponent(healthComp);
	//auto livesText = std::make_shared<TextComponent>(("Lives: " + std::to_string(healthComp->GetLives())),font ,HealthObj, Color(0, 255, 0));
	//HealthObj->AddComponent(livesText);
	//HealthObj->GetComponent<TransformComponent>()->SetPosition(100, 250);
	//scene->Add(HealthObj);

	//// P2
	//auto playerObj2 = std::make_shared<GameObject>();
	//auto peter2 = std::make_shared<PeterPepperComponent>(playerObj2);
	//playerObj2->AddComponent(peter2);
	//auto P2Text = std::make_shared<TextComponent>("P2", font, playerObj2, Color(0, 255, 0));
	//playerObj2->AddComponent(P2Text);
	//playerObj2->GetComponent<TransformComponent>()->SetPosition(100, 400);
	//scene->Add(playerObj2);

	//// Points P2
	//auto PointsObj2 = std::make_shared<GameObject>();
	//auto points2 = std::make_shared<PointsComponent>(PointsObj2);
	//PointsObj2->AddComponent(points2);
	//auto pointsText2 = std::make_shared<TextComponent>(("Points: " + std::to_string(points2->GetPoints())), font, PointsObj2, Color(0, 255, 0));
	//PointsObj2->AddComponent(pointsText2);
	//PointsObj2->GetComponent<TransformComponent>()->SetPosition(100, 450);
	//scene->Add(PointsObj2);

	//// Lives P2
	//int maxLives2{ 3 };
	//auto HealthObj2 = std::make_shared<GameObject>();
	//auto healthComp2 = std::make_shared<HealthComponent>(HealthObj2, maxLives2);
	//HealthObj2->AddComponent(healthComp2);
	//auto livesText2 = std::make_shared<TextComponent>(("Lives: " + std::to_string(healthComp2->GetLives())), font, HealthObj2, Color(0, 255, 0));
	//HealthObj2->AddComponent(livesText2);
	//HealthObj2->GetComponent<TransformComponent>()->SetPosition(100, 500);
	//scene->Add(HealthObj2);

	//// commands input players
	//input.SetButtonCommand(0, XboxController::ControllerButton::Dpad_Up, new DamageCommand(HealthObj), InputState::Down);
	//input.SetButtonCommand(0, XboxController::ControllerButton::Dpad_Right, new DamageCommand(HealthObj2), InputState::Down);
	//input.SetButtonCommand(0, XboxController::ControllerButton::Dpad_Down, new IncreasePointsCommand(PointsObj), InputState::Down);
	//input.SetButtonCommand(0, XboxController::ControllerButton::Dpad_Left, new IncreasePointsCommand(PointsObj2), InputState::Down);

}

void dae::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	ServiceLocator::RegisterSoundManager(nullptr);
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void dae::Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();

		// todo: this update loop could use some work.
		bool doContinue = true;
		auto lastTime = std::chrono::high_resolution_clock::now();
		float lag{ 0.0f };
		float deltaTime{};

		while (doContinue)
		{
			const auto currentTime = std::chrono::high_resolution_clock::now();
			deltaTime= std::chrono::duration<float>(currentTime - lastTime).count() ;

			lastTime = currentTime;
			lag += deltaTime;

			while (lag >= m_msPerFrame)
			{
				sceneManager.FixedUpdate(m_msPerFrame);
				lag -= m_msPerFrame;
			}
			doContinue = input.ProcessInput();

			sceneManager.Update(deltaTime);
			sceneManager.LateUpdate(deltaTime);

			renderer.Render();

		}
	}

	Cleanup();
}
