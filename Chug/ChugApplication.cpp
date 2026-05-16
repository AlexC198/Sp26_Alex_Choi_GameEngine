#include "pch.h"

#include "ChugApplication.h"
#include "Window.h"

#include "glad/glad.h"

#include "stbi.h"

#include "Picture.h"
#include "Shader.h"
#include "Renderer.h"

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
		Window::Get()->Create({ 1000,800 }, "Fall Game");

		Renderer::Init();

		Initialize();
		
		Picture pic{ "../Chug/Assets/Images/Character.png" };

		int pos = 2;

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true)
		{
			Renderer::Get()->ScreenClear();

			Update();

			Renderer::Get()->Draw(pic, pos, 2);
			pos++;

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			Window::Get()->SwapBuffers();
			Window::Get()->PollEvents();
		}

		Shutdown();
	}


	ChugApplication::~ChugApplication()
	{
	}
}