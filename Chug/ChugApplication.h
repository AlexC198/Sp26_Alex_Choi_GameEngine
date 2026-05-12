#pragma once

#include "ChugUtility.h"

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
	};
}