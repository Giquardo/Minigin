#pragma once
#include "Structs.h"
struct SDL_Window;
namespace dae
{
	class TextureComponent;
	class Minigin
	{
	public:
		void Initialize();
		virtual void LoadGame() const = 0;
		void Cleanup();
		void Run();


	private:
		static const int m_msPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		SDL_Window* m_Window{};
		Size m_WindowSize{1280, 960};
	};
}