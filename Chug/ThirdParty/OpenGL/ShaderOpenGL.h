#pragma once


#include"../../ShaderImplementation.h"

namespace Chug
{
	class ShaderOpenGL : public ShaderImplementation
	{
	public:
		ShaderOpenGL();
		ShaderOpenGL(const std::string& vertexFileName, const std::string& fragmentFileName);

		virtual void LoadShader(const std::string& vertexFileName, const std::string& fragmentFileName) override;
		virtual void SupplyIntUniform(const std::string& uniformName, const std::vector<int>& vals) override;
		virtual void Bind() override;

		~ShaderOpenGL();

	private:
		unsigned int mShader{ 0 };

		std::string ReadFile(const std::string& fileName);
	};
}