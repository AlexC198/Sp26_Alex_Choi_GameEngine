#include"pch.h"

#include "WindowGLFW.h"
#include "../../ChugUtility.h"

namespace Chug
{
	void WindowGLFW::Create(Dimensions dimensions, const std::string & windowName)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWwindow* window = glfwCreateWindow(
			dimensions.width, dimensions.height, windowName.c_str(), NULL, NULL);

		if (mWindowPtr == nullptr)
		{
			CHUG_ERROR("Failed to create GLFW window");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(mWindowPtr);
	}

	Dimensions WindowGLFW::GetSize() const
	{
		int height{ 0 }, width{ 0 };
		
		glfwGetWindowSize(mWindowPtr, &width, &height);

		return { width,height };
	}

	void WindowGLFW::SwapBuffers()
	{
		glfwSwapBuffers(mWindowPtr);
	}

	void WindowGLFW::PollEvents()
	{
		glfwPollEvents();
	}
}
