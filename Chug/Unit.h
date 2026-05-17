#pragma once

#include"ChugUtility.h"
#include "ChugTypes.h"

#include "Picture.h"

namespace Chug
{
	class CHUG_API Unit
	{
	public:
		Unit(const std::string& fileName);
		Unit(const std::string& fileName, int xPos, int yPos);

		void SetCoordinates(int newXPos, int newYPos);
		int GetXCoordinate() const;
		int GetYCoordinate() const;

		void IncrementXPosition(int amount);
		void IncrementYPosition(int amount);

		void SetSpeed(int newSpeed);
		int GetSpeed() const;

		Dimensions GetDimensions() const;

		bool IsVisible() const;
		void MakeVisible();
		void MakeInvisible();

	private:
		Picture mPicture;
		int mXpos{ 0 };
		int mYpos{ 0 };
		int mSpeed{ 0 };
		bool mIsVisible{ true };

		friend class Renderer;
		friend bool CHUG_API Collide(const Unit& one, const Unit& another);
	};
	bool CHUG_API Collide(const Unit& one, const Unit& another);

}