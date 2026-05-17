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

		virtual void SetKeyCallback(std::function<void(const KeyEvent&)> newCallback) override;
		virtual void SetWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback) override;

	private:
		GLFWwindow* mWindowPtr{ nullptr };

		struct Callbacks {
			std::function<void(const KeyEvent&)> KeyCallback;
			std::function<void(const WindowCloseEvent&)> WindowCloseCallback;
		} mCallbacks;
	};
}