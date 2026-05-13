#include "pch.h"

#include "ChugApplication.h"
#include "Window.h"
namespace Chug
{
	void ChugApplication::Update()
	{
	}

	void ChugApplication::Initialize()
	{
	}

	void ChugApplication::Shutdown()
	{
	}

	void ChugApplication::Run()
	{
		Window::Init();
		Window::Get() -> Create({ 800,600 }, "Fall Game");

		Initialize();

		while (true)
		{
			Update();

			Window::Get()->SwapBuffers();
			Window::Get()->PollEvents();
		}

		Shutdown();
	}


	ChugApplication::~ChugApplication()
	{
	}
}