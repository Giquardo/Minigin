#pragma once
#include "NullSoundManager.h"

namespace dae 
{
	class SoundManager;
	class ServiceLocator final
	{
	public:

		ServiceLocator() = default;
		~ServiceLocator() = default;
		ServiceLocator(const ServiceLocator& other) = default;
		ServiceLocator(ServiceLocator&& other) = default;
		ServiceLocator& operator=(const ServiceLocator& other) = default;
		ServiceLocator& operator=(ServiceLocator&& other) = default;

		static std::shared_ptr<SoundManager> GetSoundManager();
		static void RegisterSoundManager(std::shared_ptr<SoundManager> soundManager);

	private:
		static std::shared_ptr<SoundManager> m_SoundManagerInstance;
	};
}

