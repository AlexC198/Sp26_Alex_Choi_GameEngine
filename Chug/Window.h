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

		Window();

		void Create(Dimensions dimensions, const std::string & windowName);
		Dimensions GetSize() const;

		void SwapBuffers();
		void PollEvents();
	private:
		std::unique_ptr<WindowImplementation> mImplementation{ nullptr };
	};
}
