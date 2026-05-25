#include "Enemy.h"

Enemy::Enemy(const std::string& enemyPicture, int startingX, int startingY)
	: mUnit{ enemyPicture, startingX, startingY }
{
}

void Enemy::Update(const Player& player)
{
	if (mDead) 
		return;
	MoveTowardPlayer(player);
}

void Enemy::Draw()
{
	if (!mDead)
		Chug::Renderer::Get()->Draw(mUnit);
}

void Enemy::Kill() 
{ 
	mDead = true; 
}

bool Enemy::IsDead() const 
{ 
	return mDead; 
}
int Enemy::GetX() const 
{ 
	return mUnit.GetXCoordinate(); 
}
int Enemy::GetY() const 
{ 
	return mUnit.GetYCoordinate(); 
}

bool Enemy::ShouldFire()
{
	mBulletRefreshRate++;
	if (mBulletRefreshRate >= 60)
	{
		mBulletRefreshRate = 0;
		return true;
	}
	return false;
}

const Chug::Unit& Enemy::GetUnit() const 
{ 
	return mUnit; 
}

void Enemy::MoveTowardPlayer(const Player& player)
{
	float distx = (float)(player.GetX() - mUnit.GetXCoordinate());
	float disty = (float)(player.GetY() - mUnit.GetYCoordinate());
	float length = std::sqrt(distx * distx + disty * disty);


	if (length == 0.0f) 
		return;


	mUnit.IncrementXPosition((int)((distx / length) * 4));
	mUnit.IncrementYPosition((int)((disty / length) * 4));
}