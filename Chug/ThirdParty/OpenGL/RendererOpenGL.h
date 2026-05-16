#pragma once

#include "RendererImplementation.h"

namespace Chug
{
	class RendererOpenGL : public RendererImplementation
	{
	public:
		RendererOpenGL();

		virtual void Draw(Picture& pic, int xCoord, int yCoord, Shader& shader) override;
		virtual void ScreenClear() override;

	private:

	};
}