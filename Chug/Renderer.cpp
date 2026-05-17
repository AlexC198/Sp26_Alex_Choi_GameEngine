#include "pch.h"

#include"Renderer.h"
#include "ThirdParty/OpenGL/RendererOpenGL.h"
#include "Window.h"
namespace Chug 
{
	void Renderer::Init()
	{
		if (!mInstance)
			mInstance = std::unique_ptr<Renderer>{ new Renderer };
	}

	std::unique_ptr<Renderer>& Renderer::Get() 
	{
		return mInstance;
	}

	void Renderer::Draw(Picture& pic, int xCoord, int yCoord)
	{
		mDefaultShaders.SupplyIntUniform("screenRes", { Window::Get()->GetSize().width, Window::Get()->GetSize().height});
		mImplementation->Draw(pic, xCoord, yCoord, mDefaultShaders);
	}

	void Renderer::Draw(Picture& pic, int xCoord, int yCoord, Shader& shader)
	{
		mImplementation->Draw(pic, xCoord, yCoord, shader);
	}

	void Renderer::Draw(Unit& unit)
	{
		mDefaultShaders.SupplyIntUniform("screenRes", { Window::Get()->GetSize().width, Window::Get()->GetSize().height });
		mImplementation->Draw(unit.mPicture, unit.mXpos, unit.mYpos, mDefaultShaders);
	}

	void Renderer::Draw(Unit& unit, Shader& shader)
	{
		mImplementation->Draw(unit.mPicture, unit.mXpos, unit.mYpos, shader);
	}

	void Renderer::ScreenClear()
	{
		mImplementation->ScreenClear();
	}

	Renderer::Renderer()
	{
#ifdef CHUG_OPENGL
		mImplementation = std::unique_ptr<RendererImplementation>{ new RendererOpenGL };
		mDefaultShaders.LoadShader("../Chug/Assets/Shaders/defaultVertexShader.glsl", "../Chug/Assets/Shaders/defaultFragmentShader.glsl");
#else
		#only_OpenGL_is_supported_for_Renderer
#endif
	}
}