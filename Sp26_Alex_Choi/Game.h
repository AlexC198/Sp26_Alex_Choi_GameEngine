#pragma once

#include "Chug.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Counter.h"

constexpr int SPAWN_RATE = 120;  
constexpr int MAX_ENEMIES = 10; 

class Game : public Chug::ChugApplication
{
public:
	void Initialize() override;
	void Update()     override;

private:
	// Game.h
	Player mPlayer{ "Assets/player.png", WINDOW_W/2, WINDOW_H/2 };
	Chug::Unit mBackground{ "Assets/background.png", 0, 0 };

	std::vector<std::unique_ptr<Enemy>> mEnemies;
	std::vector<std::unique_ptr<Bullet>> mBullets;

	KillCounter mKillCounter;   

	bool mMoveUp{ false };
	bool mMoveDown{ false };
	bool mMoveLeft{ false };
	bool mMoveRight{ false };

	bool mGameOver{ false };


	int  mSpawnTimer{ 0 };
	int  mBulletTimer{ 0 };
	int  mKillCount{ 0 };
	int mShotCounter{ 0 }; 
	void HandlePlayerInput();
	void SpawnEnemy();
	void FireBullet();
	void CheckCollisions();
	void CleanUp();
	Enemy* FindNearestEnemy();
	std::vector<std::unique_ptr<Bullet>> mEnemyBullets;

};