#pragma once

#include "ChugUtility.h"

namespace Chug
{
	struct CHUG_API Dimensions
	{
		int width{ 0 };
		int height{ 0 };

		Dimensions();
		Dimensions(int newWidth, int newHeight) : width(newWidth), height(newHeight) {};
	};
}