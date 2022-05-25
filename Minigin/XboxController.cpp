#include "MiniginPCH.h"
#include "XboxController.h"
#pragma comment(lib,"XInput.lib")
#pragma comment(lib,"Xinput9_1_0.lib")
#include <Windows.h>
#include <Xinput.h>
class dae::XboxController::XboxControllerImpl
{
public:
	XboxControllerImpl(unsigned int controllerIndex);

	void Update();

	bool IsDownThisFrame(int button) const;
	bool IsUpThisFrame(int button) const;
	bool IsPressed(int button) const;

private:
	XINPUT_STATE m_CurrentState{};
	XINPUT_STATE m_PreviusState{};

	WORD m_ButtonPressedThisFrame;
	WORD m_ButtonReleasedThisFrame;

	int m_ControlerIndex{ 0 };
};

dae::XboxController::XboxController(int controllerIndex)
{
	pImpl = new XboxControllerImpl(controllerIndex);
}

dae::XboxController::~XboxController()
{
	delete pImpl;
}

void dae::XboxController::Update()
{
	pImpl->Update();
}

bool dae::XboxController::IsPressed(ControllerButton button) const
{
	return pImpl->IsPressed(static_cast<int>(button));
}

bool dae::XboxController::IsUp(ControllerButton button) const
{
	return pImpl->IsUpThisFrame(static_cast<int>(button));
}

bool dae::XboxController::IsDown(ControllerButton button) const
{
	return pImpl->IsDownThisFrame(static_cast<int>(button));
}

dae::XboxController::XboxControllerImpl::XboxControllerImpl(unsigned int controllerIndex)
{
	ZeroMemory(&m_PreviusState, sizeof(XINPUT_STATE));
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	m_ControlerIndex = controllerIndex;
}

void dae::XboxController::XboxControllerImpl::Update()
{
	CopyMemory(&m_PreviusState, &m_CurrentState, sizeof(XINPUT_STATE));
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(m_ControlerIndex, &m_CurrentState);

	auto buttonChanges = m_CurrentState.Gamepad.wButtons ^ m_PreviusState.Gamepad.wButtons;
	m_ButtonPressedThisFrame = buttonChanges & m_CurrentState.Gamepad.wButtons;
	m_ButtonReleasedThisFrame = buttonChanges & (~m_CurrentState.Gamepad.wButtons);
}

bool dae::XboxController::XboxControllerImpl::IsDownThisFrame(int button) const
{
	return m_ButtonPressedThisFrame & button;
}

bool dae::XboxController::XboxControllerImpl::IsUpThisFrame(int button) const
{
	return m_ButtonReleasedThisFrame & button;
}

bool dae::XboxController::XboxControllerImpl::IsPressed(int button) const
{
	return m_CurrentState.Gamepad.wButtons & button;
}