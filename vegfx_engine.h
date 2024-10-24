#pragma once 
#include "vegfx_pch.h"
#include "vegfx_structs.h"

namespace vegfx {

	class Graphics;
	class Game;

	class Engine {
	public:
		static void init(EngineCreateInfo info);
		static ref<Engine>& get();

		static ref<Graphics>& graphics();
		static ref<Game>& game();

		Engine(EngineCreateInfo info);
		~Engine();

	private:
		static ref<Engine> sEngineInstance;
		static ref<Graphics> sGraphicsInstance;
		static ref<Game> mGameInstance;

		EngineCreateInfo mEngineInfo;

	};
}