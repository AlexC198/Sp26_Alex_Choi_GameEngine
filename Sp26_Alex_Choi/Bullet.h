#pragma once

#include "Chug.h"
#include "player.h"

class Bullet
{
public:
	Bullet();

	Bullet(const std::string& Projectile, int startingX, int startingY, float directionX, float directionY);

	void Update();
	void Draw();

	bool IsOffScreen() const;
	bool CheckIfHit() const;
	void MarkHit();

	const Chug::Unit& GetUnit() const;

private:
	Chug::Unit mBulletUnit;
	float mDirectionX;
	float mDirectionY;
	bool mHit{ false };
};