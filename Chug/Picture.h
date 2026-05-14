#pragma once

#include "pch.h"
#include "ChugUtility.h"
#include "ChugTypes.h"
#include "PictureImplementation.h"
namespace Chug 
{
	class CHUG_API Picture
	{
	public:
		Picture();
		Picture(const std::string& fileName);
		void LoadImage(const std::string& fileName);
		Dimensions GetDimensions() const;


	private:
		std::unique_ptr<PictureImplementation> mImplementation;
		void Bind();

	};
}