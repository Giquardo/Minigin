#pragma once
#pragma comment(lib,"XInput.lib")
#pragma comment(lib,"Xinput9_1_0.lib")
#include <Windows.h>
#include <Xinput.h>

#include <map>
#include <memory>
#include "Command.h"
#include "Singleton.h"
#include "XboxController.h"

namespace dae
{
	enum class InputState
	{
		Pressed,
		Up,
		Down
	};

	class InputManager final : public Singleton<InputManager>
	{
		public:

			InputManager();
			~InputManager();

			bool ProcessInput();
			void SetButtonCommand(int controllerIndex, XboxController::ControllerButton button, Command* command, InputState InputState);

		private:

			std::vector<XboxController*> m_pControllers;

			std::map<std::pair<int, XboxController::ControllerButton>, std::pair<std::unique_ptr<Command>, InputState>> m_Commands;
	};

}
