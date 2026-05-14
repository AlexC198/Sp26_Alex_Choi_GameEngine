#pragma once

#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "../../WindowImplementation.h"
#include "../../ChugTypes.h"

namespace Chug
{
	class WindowGLFW : public WindowImplementation
	{
	public:
		virtual void Create(Dimensions dimensions, const std::string & windowName) override;
		virtual Dimensions GetSize() const override;

		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

	private:
		GLFWwindow* mWindowPtr{ nullptr };
	};
}