#include "pch.h"

#include "Window.h"
#include "ThirdParty/GLFW/WindowGLFW.h"

namespace Chug
{
	Window::Window()
	{
#ifdef CHUG_GLFW
		mImplementation = std::unique_ptr<WindowImplementation> { new WindowGLFW };
#else
		#only_GLFW_is_supported
#endif
	}
	void Window::Create(Dimensions dimensions, const std::string& windowName)
	{
		mImplementation->Create(dimensions, windowName);
	}

	Dimensions Window::GetSize() const
	{
		return mImplementation->GetSize();
	}

	void Window::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	void Window::PollEvents()
	{
		mImplementation->PollEvents();
	}
}

