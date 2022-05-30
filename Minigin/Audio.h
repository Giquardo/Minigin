#pragma once
namespace dae
{
	class Audio final
	{
		public:
			Audio(const std::string& path);
			~Audio();

			Audio(const Audio& other) = default;
			Audio(Audio&& other) = default;
			Audio& operator=(const Audio& other) = default;
			Audio& operator=(Audio&& other) = default;

			void Load();
			bool Play();
			void SetVolume(int volume);
			int GetVolume() const;
			bool IsLoaded() const;

		private:

			class AudioImpl;
			AudioImpl* pImpl;
	};
}
