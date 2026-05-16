#pragma once

#include "ChugUtility.h"

constexpr int FRAMES_PER_SECOND { 60 };

namespace Chug
{
	class CHUG_API ChugApplication
	{
	public:
		virtual void Update();
		virtual void Initialize();
		virtual void Shutdown();

		void Run();

		virtual ~ChugApplication();

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
		std::chrono::steady_clock::time_point mNextFrameTime;

	};
}