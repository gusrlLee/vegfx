#include "vegfx_engine.h"
#include "vegfx_log.h"
#include "vegfx_graphics.h"
#include "vegfx_game.h"

namespace vegfx {
	ref<Engine> Engine::sEngineInstance = nullptr;
	ref<Game> Engine::mGameInstance = nullptr;
	ref<Graphics> Engine::sGraphicsInstance = nullptr;

	void Engine::init(EngineCreateInfo info)
	{
		// Engine entire setting 
		sEngineInstance = make<Engine>(info);

		// Graphics of engine setting 
		GraphicsCreateInfo graphicsInfo;
		graphicsInfo.glfwExtensionList = info.glfwExtensionList;
		graphicsInfo.layerList = info.layerList;
		sGraphicsInstance = make<Graphics>(graphicsInfo);


	}

	ref<Engine>& Engine::get()
	{
		return sEngineInstance;
	}

	ref<Graphics>& Engine::graphics()
	{
		return sGraphicsInstance;
	}

	ref<Game>& Engine::game()
	{
		return mGameInstance;
	}

	Engine::Engine(EngineCreateInfo info)
	{
		mEngineInfo = info;

		VEGFX_INFO("Success to create engine!");
	}

	Engine::~Engine()
	{

	}
}