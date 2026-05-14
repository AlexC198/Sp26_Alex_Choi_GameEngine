#pragma once

#include "ChugTypes.h"
namespace Chug
{
	class PictureImplementation
	{
	public:
		virtual void LoadImage(const std::string& fileName) = 0;
		virtual Dimensions GetDimensions() const = 0;
		virtual void Bind() = 0;

		virtual ~PictureImplementation() {};
	};
}