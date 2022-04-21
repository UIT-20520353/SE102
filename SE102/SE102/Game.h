#pragma once

#include "Define.h"
#include "Debug.h"
#include "Window.h"
#include "Renderer.h"

using namespace std;

constexpr TimeStep ENGINE_FPS = 120;
constexpr TimeStep ENGINE_FRAME_STEP = 1000 / ENGINE_FPS;
constexpr int      ENGINE_SCREEN_ZOOM = 3;

class Game
{
public:
	Game() = default;
	~Game();

	TimeStep GetLastFrameTime() const;
	TimeStep GetElapsedTime() const;


	void Create(int width, int height, std::wstring title, HINSTANCE hInstance, int nCmdShow);
	void Run();

	static Ref<Game> GetInstance();

private:
	Scope<Window> m_Window;

	bool     m_Running = true;
	TimeStep m_LastFrameTime = 0;
	TimeStep m_ElapsedTime = 0;

	static Ref<Game> s_Instance;
};

