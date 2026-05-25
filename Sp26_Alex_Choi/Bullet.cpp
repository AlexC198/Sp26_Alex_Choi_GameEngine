#include "Bullet.h"


Bullet::Bullet(const std::string& Projectile, int startingX, int startingY, float directionX, float directionY)
	: mBulletUnit{ Projectile, startingX, startingY }
{
	mDirectionX = directionX;
	mDirectionY = directionY;
}

void Bullet::Update()
{
	if (mHit)
	{
		return;
	}
	mBulletUnit.IncrementXPosition((int)(mDirectionX * 15));
	mBulletUnit.IncrementYPosition((int)(mDirectionY * 15));
}

void Bullet::Draw()
{
	if (!mHit)
	{
		Chug::Renderer::Get()->Draw(mBulletUnit);
	}
}

bool Bullet::IsOffScreen() const
{
	return mBulletUnit.GetXCoordinate() < 0 || mBulletUnit.GetXCoordinate() > WINDOW_W || 
		mBulletUnit.GetYCoordinate() < 0 || mBulletUnit.GetYCoordinate() > WINDOW_H;
}

bool Bullet::CheckIfHit()  const 
{ 
	return mHit; 
}
void Bullet::MarkHit() 
{ 
	mHit = true; 
}

const Chug::Unit& Bullet::GetUnit() const 
{ 
	return mBulletUnit; 
}