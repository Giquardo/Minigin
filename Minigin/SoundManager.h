#pragma once
namespace dae 
{
	class SoundManager 
	{
	public:
		SoundManager();
		virtual ~SoundManager();
		SoundManager(const SoundManager& other) = default;
		SoundManager(SoundManager && other) = default;
		SoundManager& operator=(const SoundManager & other) = default;
		SoundManager& operator=(SoundManager && other) = default;

		virtual void QueueAudio(const std::string& path);

	private:
		class SoundManagerImpl;
		SoundManagerImpl* pImpl;
	};

}

