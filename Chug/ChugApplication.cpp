#include "pch.h"

#include "ChugApplication.h"
#include "Window.h"

#include "glad/glad.h"

#include "stbi.h"

#include "Picture.h"
#include "Shader.h"

namespace Chug
{
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
		Window::Init();
		Window::Get()->Create({ 800,600 }, "Fall Game");

		Initialize();

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);

		float data[] = {
			 0.0f,  0.0f, 0.0f, 0.0f,	//bottom left
			 0.0f,  100.0f, 0.0f, 1.0f, 	//upper left
			 100.0f,  100.0f, 1.0f, 1.0f,  //upper right
			 100.0f, 0.0f, 1.0f, 0.0f  //lower right
		};

		unsigned int indices[] = {
			0,1,2,	//first triangle
			0,2,3	//second triangle
		};
		unsigned int VAO{ 0 };
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned int VBO{ 0 };
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		unsigned int EBO{ 0 };
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		
		Picture pic{ "../Chug/Assets/Images/Character.png" };
		Shader shader{ "../Chug/Assets/Shaders/defaultVertexShader.glsl", "../Chug/Assets/Shaders/defaultFragmentShader.glsl" };
		shader.SupplyIntUniform("screenRes", { 600, 400 });
		while (true)
		{
			glClearColor(0.5f, 0.5f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Update();

			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			Window::Get()->SwapBuffers();
			Window::Get()->PollEvents();
		}

		Shutdown();
	}


	ChugApplication::~ChugApplication()
	{
	}
}