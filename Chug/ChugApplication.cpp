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
		Window win;
		win.Create({ 800,600 }, "Fall Game");

		Initialize();

		while (true)
		{
			Update();

			win.SwapBuffers();
			win.PollEvents();
		}

		Shutdown();
	}


	ChugApplication::~ChugApplication()
	{
	}
}