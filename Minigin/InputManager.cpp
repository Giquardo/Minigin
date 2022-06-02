#include "MiniginPCH.h"
#include "InputManager.h"
#include <WinBase.h>

dae::InputManager::InputManager()
{
	m_pControllers.push_back(new XboxController(0));
	m_pControllers.push_back(new XboxController(1));
	m_IsMenu = true;
}

dae::InputManager::~InputManager()
{
	for (XboxController* pController : m_pControllers)
	{
		delete pController;
	}
}

bool dae::InputManager::ProcessInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) 
	{
		if (e.type == SDL_QUIT)
		{
			std::cout << "Closing Program\n";
			return false;
		}
	}

	if (!m_IsMenu)
	{
		for (size_t idx = 0; idx < m_pControllers.size(); ++idx)
		{
			m_pControllers[idx]->Update();

			for (auto CommandIterator = m_Commands.begin(); CommandIterator != m_Commands.end(); ++CommandIterator)
			{
				switch (CommandIterator->second.second)
				{
				case dae::InputState::Pressed:
					if (m_pControllers[idx]->IsPressed(CommandIterator->first.second))
					{
						CommandIterator->second.first.get()->Execute();
					}
					break;
				case dae::InputState::Up:
					if (m_pControllers[idx]->IsUp(CommandIterator->first.second))
					{
						CommandIterator->second.first.get()->Execute();
					}
					break;
				case dae::InputState::Down:
					if (m_pControllers[idx]->IsDown(CommandIterator->first.second))
					{
						CommandIterator->second.first.get()->Execute();
					}
					break;
				default:
					break;
				}

				if (m_pControllers[idx]->IsPressed(XboxController::ControllerButton::GamepadBack))
				{
					return false;
				}
			}
		}
	}
	else
	{
		for (size_t idx = 0; idx < m_pControllers.size(); ++idx)
		{
			m_pControllers[idx]->Update();

			for (auto CommandIterator = m_MenuCommands.begin(); CommandIterator != m_MenuCommands.end(); ++CommandIterator)
			{
				switch (CommandIterator->second.second)
				{
				case dae::InputState::Pressed:
					if (m_pControllers[idx]->IsPressed(CommandIterator->first.second))
					{
						CommandIterator->second.first.get()->Execute();
					}
					break;
				case dae::InputState::Up:
					if (m_pControllers[idx]->IsUp(CommandIterator->first.second))
					{
						CommandIterator->second.first.get()->Execute();
					}
					break;
				case dae::InputState::Down:
					if (m_pControllers[idx]->IsDown(CommandIterator->first.second))
					{
						CommandIterator->second.first.get()->Execute();
					}
					break;
				default:
					break;
				}

				if (m_pControllers[idx]->IsPressed(XboxController::ControllerButton::GamepadBack))
				{
					return false;
				}
			}
		}
	}
	return true;

}

void dae::InputManager::SetButtonCommand(int controllerIndex, XboxController::ControllerButton button, Command* command, InputState InputState)
{
	m_Commands[std::make_pair(controllerIndex, button)] = std::make_pair(std::unique_ptr<Command>(command), InputState);
}

void dae::InputManager::SetMenuButtonCommand(int controllerIndex, XboxController::ControllerButton button, Command* command, InputState InputState)
{
	m_MenuCommands[std::make_pair(controllerIndex, button)] = std::make_pair(std::unique_ptr<Command>(command), InputState);
}

void dae::InputManager::RemoveButtonCommand(int controllerIndex, XboxController::ControllerButton button)
{
	m_Commands.erase(std::make_pair(controllerIndex, button));
}

void dae::InputManager::RemoveMenuButtonCommand(int controllerIndex, XboxController::ControllerButton button)
{
	m_MenuCommands.erase(std::make_pair(controllerIndex, button));
}

void dae::InputManager::InMenu(bool inMenu)
{
	m_IsMenu = inMenu;
}
