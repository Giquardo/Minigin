#pragma once
#include "SoundManager.h"

namespace dae
{
	class NullSoundManager final : public SoundManager
	{
	public:
		NullSoundManager() = default;
		virtual ~NullSoundManager() override = default;
		NullSoundManager(const NullSoundManager & other) = delete;
		NullSoundManager(NullSoundManager && other) = delete;
		NullSoundManager& operator=(const NullSoundManager & other) = delete;
		NullSoundManager& operator=(NullSoundManager && other) = delete;

		void QueueAudio(const std::string&) override {};

	private:

	};

}
