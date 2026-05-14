#include "pch.h"
#include "ShaderOpenGL.h"
#include "glad/glad.h"
#include "ChugUtility.h"

namespace Chug
{
	ShaderOpenGL::ShaderOpenGL()
	{
	}

	ShaderOpenGL::ShaderOpenGL(const std::string& vertexFileName, const std::string& fragmentFileName)
	{
		unsigned int vertexShader{ 0 };
		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		std::string vertexSourceCode{ ReadFile(vertexFileName) };
		const char* ptr = vertexSourceCode.c_str();

		glShaderSource(vertexShader, 1, &ptr, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			CHUG_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl);
		}

		unsigned int fragShader{ 0 };
		fragShader = glCreateShader(GL_FRAGMENT_SHADER);

		std::string fragmentSourceCode{ ReadFile(fragmentFileName) };
		ptr = fragmentSourceCode.c_str();

		glShaderSource(fragShader, 1, &ptr, NULL);
		glCompileShader(fragShader);

		glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
			CHUG_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl);
		}

		mShader = glCreateProgram();
		glAttachShader(mShader, vertexShader);
		glAttachShader(mShader, fragShader);
		glLinkProgram(mShader);

		glGetProgramiv(mShader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(mShader, 512, NULL, infoLog);
			CHUG_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragShader);
	}

	void ShaderOpenGL::LoadShader(const std::string& vertexFileName, const std::string& fragmentFileName)
	{
		unsigned int vertexShader{ 0 };
		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		std::string vertexSourceCode{ ReadFile(vertexFileName) };
		const char* ptr = vertexSourceCode.c_str();

		glShaderSource(vertexShader, 1, &ptr, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			CHUG_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl);
		}

		unsigned int fragShader{ 0 };
		fragShader = glCreateShader(GL_FRAGMENT_SHADER);

		std::string fragmentSourceCode{ ReadFile(fragmentFileName) };
		ptr = fragmentSourceCode.c_str();

		glShaderSource(fragShader, 1, &ptr, NULL);
		glCompileShader(fragShader);

		glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
			CHUG_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl);
		}

		mShader = glCreateProgram();
		glAttachShader(mShader, vertexShader);
		glAttachShader(mShader, fragShader);
		glLinkProgram(mShader);

		glGetProgramiv(mShader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(mShader, 512, NULL, infoLog);
			CHUG_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragShader);
	}

	void ShaderOpenGL::SupplyIntUniform(const std::string& uniformName, const std::vector<int>& vals)
	{
		glUseProgram(mShader);
		int location{ glGetUniformLocation(mShader, uniformName.c_str()) };

		switch (vals.size())
		{
		case 1:
			glUniform1i(location, vals[0]);
			break;
		case 2:
			glUniform2i(location, vals[0], vals[1]);
			break;
		case 3:
			glUniform3i(location, vals[0], vals[1], vals[2]);
			break;
		case 4:
			glUniform4i(location, vals[0], vals[1], vals[2], vals[3]);
			break;
		default:
			CHUG_ERROR("Uniform " << uniformName << "received too many values!");
		}
	}

	void ShaderOpenGL::Bind()
	{
		glUseProgram(mShader);
	}

	ShaderOpenGL::~ShaderOpenGL()
	{
		glDeleteProgram(mShader);
	}

	std::string ShaderOpenGL::ReadFile(const std::string& fileName)
	{
		std::string result;

		std::ifstream input{ fileName };

		std::string line;

		while (std::getline(input, line))
		{
			result += line + "\n";
		}

		return result;
	}
}