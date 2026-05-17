#pragma once

#include "pch.h"
#include "ChugUtility.h"
#include "ChugEvents.h"

constexpr int FRAMES_PER_SECOND { 60 };

namespace Chug
{
	class CHUG_API ChugApplication
	{
	public:
		ChugApplication();

		virtual void Update();
		virtual void Initialize();
		virtual void Shutdown();

		void Run();

		void SetKeyCallback(std::function<void(const KeyEvent&)> newCallback);
		void SetWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback);


		virtual ~ChugApplication();

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
		std::chrono::steady_clock::time_point mNextFrameTime;

		bool mShouldContinue{ true };
		void DefaultWindowCloseCallback(const WindowCloseEvent&);
	};
}