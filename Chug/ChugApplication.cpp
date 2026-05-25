#include "pch.h"

#include "ChugApplication.h"
#include "Window.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stbi.h"

#include "Picture.h"
#include "Shader.h"
#include "Renderer.h"
#include "KeyCodes.h"
#include "Unit.h"
namespace Chug
{
	ChugApplication::ChugApplication()
	{
		Window::Init();
		Window::Get()->Create({ 2000,1600 }, "Fall Game");

		SetWindowCloseCallback([this](const WindowCloseEvent& event) {DefaultWindowCloseCallback(event); });

		Renderer::Init();
	}
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
		Initialize();
	
		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (mShouldContinue)
		{
			Renderer::Get()->ScreenClear();

			Update();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			Window::Get()->SwapBuffers();
			Window::Get()->PollEvents();
		}

		Shutdown();
	}

	void ChugApplication::SetKeyCallback(std::function<void(const KeyEvent&)> newCallback)
	{
		Window::Get()->SetKeyCallback(newCallback);
	}

	void ChugApplication::SetWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback)
	{
		Window::Get()->SetWindowCloseCallback(newCallback);
	}

	ChugApplication::~ChugApplication()
	{
	}

	void ChugApplication::DefaultWindowCloseCallback(const WindowCloseEvent&)
	{
		mShouldContinue = false;
	}
}