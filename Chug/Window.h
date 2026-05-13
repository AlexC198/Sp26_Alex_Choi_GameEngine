#pragma once

#include "pch.h"
#include"WindowImplementation.h"
#include "ChugUtility.h"
#include "ChugTypes.h"

namespace Chug
{
	class CHUG_API Window
	{
	public:

		static void Init();
		static std::unique_ptr<Window>& Get();
		void Create(Dimensions dimensions, const std::string & windowName);
		Dimensions GetSize() const;

		void SwapBuffers();
		void PollEvents();
	private:

		Window();
		inline static std::unique_ptr<Window> mInstance{ nullptr };

		std::unique_ptr<WindowImplementation> mImplementation{ nullptr };
	};
}
