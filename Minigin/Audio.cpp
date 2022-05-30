#include "MiniginPCH.h"
#include "Audio.h"
#include "SDL_mixer.h"

class dae::Audio::AudioImpl
{

public:
	AudioImpl(const std::string& path)
		:m_Path(path)
	{}

	~AudioImpl()
	{
		if (m_pChunk)
			Mix_FreeChunk(m_pChunk);
	}

	void Load()
	{
		m_pChunk = Mix_LoadWAV(m_Path.c_str());
		if (m_pChunk == nullptr)
		{
			std::cout << "Audio failed to load: " << m_Path << "\n";
		}
	}

	bool IsLoaded() const
	{
		if (m_pChunk == nullptr)
			return false;

		return true;
	}

	bool Play()
	{
		if (!IsLoaded())
		{
			return false;
		}

		int channel = Mix_PlayChannel(-1, m_pChunk, 0);
		return channel == -1 ? false : true;
	}

	void SetVolume(int volume)
	{
		if (IsLoaded())
		{
			Mix_Volume(-1, volume);
		}
	}

	int GetVolume() const
	{
		if (IsLoaded())
		{
			return Mix_VolumeChunk(m_pChunk, -1);
		}
		return 0;
	}
private:
	Mix_Chunk* m_pChunk{};
	std::string m_Path;

};

dae::Audio::Audio(const std::string& path)
{
	pImpl = new AudioImpl(path);
}

dae::Audio::~Audio()
{
	delete pImpl;
}

void dae::Audio::Load()
{
	pImpl->Load();
}

bool dae::Audio::Play()
{
	return pImpl->Play();
}

void dae::Audio::SetVolume(int volume)
{
	pImpl->SetVolume(volume);
}

int dae::Audio::GetVolume() const
{
	return pImpl->GetVolume();
}

bool dae::Audio::IsLoaded() const
{
	return pImpl->IsLoaded();
}
