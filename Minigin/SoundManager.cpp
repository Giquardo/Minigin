#include "MiniginPCH.h"
#include "SoundManager.h"
#include "SDL_mixer.h"
#include <thread>
#include <queue>
#include "Audio.h"
#include <mutex>

class dae::SoundManager::SoundManagerImpl
{
public:
	SoundManagerImpl()
	{
		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, MIX_CHANNELS);
		thread = std::thread([this] { this->LoopQueue(); });

	}

	~SoundManagerImpl()
	{
		m_Continue = false;
		thread.join();
		for (size_t i = 0; i < m_FinishedAudio.size(); i++)
		{
			delete m_FinishedAudio[i];
		}
		Mix_CloseAudio();
	}

	void QueueAudio(const std::string& path)
	{
		m_AudioQueue.emplace(new Audio(path));
	}

private:
	std::queue<Audio*> m_AudioQueue{};
	std::vector<Audio*> m_FinishedAudio{};
	std::mutex mutex;
	std::thread thread;
	bool m_Continue = true;

	void LoopQueue()
	{
		while (m_Continue)
		{
			if (m_AudioQueue.size() > 0)
			{
				mutex.lock();

				m_AudioQueue.front()->Load();
				m_AudioQueue.front()->Play();
				m_FinishedAudio.emplace_back(m_AudioQueue.front());
				m_AudioQueue.pop();

				mutex.unlock();

			}
		}

	}
};

dae::SoundManager::SoundManager()
{
	pImpl = new SoundManagerImpl;
}

dae::SoundManager::~SoundManager()
{
	delete pImpl;
}

void dae::SoundManager::QueueAudio(const std::string& path)
{
	pImpl->QueueAudio(path);
}
