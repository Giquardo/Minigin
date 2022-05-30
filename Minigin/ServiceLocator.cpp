#include "MiniginPCH.h"
#include "ServiceLocator.h"
#include "SoundManager.h"

std::shared_ptr<dae::SoundManager> dae::ServiceLocator::m_SoundManagerInstance{ std::make_shared<NullSoundManager>() };

std::shared_ptr<dae::SoundManager> dae::ServiceLocator::GetSoundManager()
{
	return m_SoundManagerInstance;
}

void dae::ServiceLocator::RegisterSoundManager(std::shared_ptr<SoundManager> soundManager)
{
	if (!soundManager)
	{
		m_SoundManagerInstance = std::make_shared<NullSoundManager>();
	}
	else
	{
		m_SoundManagerInstance = soundManager;
	}
}

