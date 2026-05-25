#pragma once

#include "Chug.h"
#include "Player.h"

constexpr int ENEMY_DAMAGE = 10;
class Enemy
{
public:
	Enemy(const std::string& enemyPicture, int startingX, int startingY);

	void Update(const Player& player);


	void Draw();

	void Kill();

	bool IsDead() const;
	int  GetX()const;
	int  GetY()const;

	bool ShouldFire();

	const Chug::Unit& GetUnit() const;

private:
	Chug::Unit mUnit;
	bool mDead{ false };
	int mBulletRefreshRate{ 0 };

	void MoveTowardPlayer(const Player& player);
};