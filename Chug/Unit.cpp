#include"pch.h"

#include"Unit.h"

namespace Chug
{
	Unit::Unit(const std::string& fileName) : mPicture{ fileName }
	{
	}
	Unit::Unit(const std::string& fileName, int xPos, int yPos) : mPicture{ fileName }, mXpos{ xPos }, mYpos{ yPos }
	{
	}
	void Unit::SetCoordinates(int newXPos, int newYPos)
	{
		mXpos = newXPos;
		mYpos = newYPos;
	}
	int Unit::GetXCoordinate() const
	{
		return mXpos;
	}
	int Unit::GetYCoordinate() const
	{
		return mYpos;
	}
	void Unit::IncrementXPosition(int amount)
	{
		mXpos += amount;
	}
	void Unit::IncrementYPosition(int amount)
	{
		mYpos += amount;
	}
	void Unit::SetSpeed(int newSpeed)
	{
		mSpeed = newSpeed;
	}
	int Unit::GetSpeed() const
	{
		return mSpeed;
	}
	Dimensions Unit::GetDimensions() const
	{
		return mPicture.GetDimensions();
	}
	bool Unit::IsVisible() const
	{
		return mIsVisible;
	}
	void Unit::MakeVisible()
	{
		mIsVisible = true;
	}
	void Unit::MakeInvisible()
	{
		mIsVisible = false;
	}

	bool CHUG_API Collide(const Unit& one, const Unit& another)
	{
		int xLeftOne = one.mXpos;
		int xRightOne = one.mXpos + one.mPicture.GetDimensions().width;
		int xLeftAnother = another.mXpos;
		int xRightAnother = another.mXpos + another.mPicture.GetDimensions().width;

		bool xOverlap = (xLeftOne <= xLeftAnother && xLeftAnother <= xRightOne) || 
			(xLeftOne <= xRightAnother && xRightAnother <= xRightOne);

		int yBottomOne = one.mYpos;
		int yTopOne = one.mYpos + one.mPicture.GetDimensions().height;
		int yBottomAnother = another.mYpos;
		int yTopAnother = another.mYpos + another.mPicture.GetDimensions().height;

		bool yOverlap = (yBottomOne <= yBottomAnother && yBottomAnother <= yTopOne) ||
			(yBottomOne <= yTopAnother && yTopAnother <= yTopOne);

		return xOverlap && yOverlap;
	}
}