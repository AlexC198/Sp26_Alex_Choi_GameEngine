#include "pch.h"

#include "ChugApplication.h"
#include "Window.h"

#include "glad/glad.h"

#include "stbi.h"

#include "Picture.h"
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
			-0.5f, -0.5f, 0.0f, 0.0f,	//bottom left
			-0.5f,  0.5f, 0.0f, 1.0f, 	//upper left
			 0.5f,  0.5f, 1.0f, 1.0f,  //upper right
			 0.5f, -0.5f, 1.0f, 0.0f  //lower right
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

		//Shaders//
		const char* vertexSource = R"(
			#version 330 core

			layout (location = 0) in vec2 coords;
			layout (location = 1) in vec2 tcoords;			

			out vec2 texCoords;
			
			void main()
			{
			 texCoords = tcoords;
			 gl_Position = vec4(coords.x,coords.y, 0, 1);
			}
		)";

		unsigned int vertexShader{ 0 };
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		int sourceSize{ sizeof(vertexSource) };
		glShaderSource(vertexShader, 1, &vertexSource, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			CHUG_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl);
		}

		const char* fragSource = R"(
			#version 330 core

			in vec2 texCoords;
			out vec4 FragColor;
			
			uniform sampler2D picture;

			void main()
			{
				FragColor = texture(picture, texCoords);
			};
		)";

		unsigned int fragShader{ 0 };
		fragShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragShader, 1, &fragSource, NULL);
		glCompileShader(fragShader);

		glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
			CHUG_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl);
		}


		unsigned int shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragShader);
		glLinkProgram(shaderProgram);

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			CHUG_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragShader);
		
		Picture pic{ "../Chug/Assets/Images/Character.png" };

		while (true)
		{
			glClearColor(0.5f, 0.5f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Update();

			glUseProgram(shaderProgram);
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