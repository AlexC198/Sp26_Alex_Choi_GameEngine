#include "Game.h"

void Game::Initialize()
{
	SetKeyCallback([this](const Chug::KeyEvent& event)
	{
		bool keyPress = (event.GetAction() == Chug::KeyAction::PRESS || event.GetAction() == Chug::KeyAction::REPEAT);
		if (event.GetKeyCode() == Chug::Key::W) mMoveUp = keyPress;
		if (event.GetKeyCode() == Chug::Key::S) mMoveDown = keyPress;
		if (event.GetKeyCode() == Chug::Key::A) mMoveLeft = keyPress;
		if (event.GetKeyCode() == Chug::Key::D) mMoveRight = keyPress;
	});
}

void Game::Update()
{
	Chug::Renderer::Get()->Draw(mBackground);

	if (mGameOver)
	{
		for (int i = 0; i < mEnemies.size(); i++)
		{
			if(!mEnemies[i]->IsDead())
				mEnemies[i]->Draw();
		}
		for (int i = 0; i < mBullets.size(); i++)
		{
			if (!mBullets[i]->CheckIfHit() && !mBullets[i]->IsOffScreen()) 
				mBullets[i]->Draw();
		}
		for (int i = 0; i < mEnemyBullets.size(); i++)
		{
			if (!mEnemyBullets[i]->CheckIfHit() && !mEnemyBullets[i]->IsOffScreen()) 
				mEnemyBullets[i]->Draw();
		}
		mKillCounter.UpdateNumber(mKillCount);

		mKillCounter.Draw();
		return;
	}

	HandlePlayerInput();
	mPlayer.Update();

	mSpawnTimer++;
	if (mSpawnTimer >= SPAWN_RATE && mEnemies.size() < MAX_ENEMIES)
	{
		SpawnEnemy();
		mSpawnTimer = 0;
	}

	mBulletTimer++;
	if (mBulletTimer >= 60)
	{
		FireBullet();
		mBulletTimer = 0;
	}

	for (int i = 0; i < mEnemies.size(); i++)
	{
		mEnemies[i]->Update(mPlayer);

		if (mEnemies[i]->ShouldFire())
		{
			float dx = (float)(mPlayer.GetX() - mEnemies[i]->GetX());
			float dy = (float)(mPlayer.GetY() - mEnemies[i]->GetY());
			float length = std::sqrt(dx * dx + dy * dy);

			if (length > 0.0f)
			{
				mEnemyBullets.push_back(std::make_unique<Bullet>("Assets/bullet.png", mEnemies[i]->GetX(), mEnemies[i]->GetY(), dx / length, dy / length));
			}
		}
	}

	for (int i = 0; i < mBullets.size(); i++)
	{
		mBullets[i]->Update();
	}
	for (int i = 0; i < mEnemyBullets.size(); i++)
	{
		mEnemyBullets[i]->Update();
	}

	CheckCollisions();
	CleanUp();

	if (mPlayer.IsDead())
	{
		mGameOver = true;
		CHUG_LOG("Game Over! Score: " << mKillCount);
	}

	
	mPlayer.Draw();
	for (int i = 0; i < mEnemies.size(); i++)
	{
		mEnemies[i]->Draw();
	}
	for (int i = 0; i < mBullets.size(); i++)
	{
		mBullets[i]->Draw();
	}
	for (int i = 0; i < mEnemyBullets.size(); i++)
	{
		mEnemyBullets[i]->Draw();
	}

	mKillCounter.UpdateNumber(mKillCount);
	mKillCounter.Draw();
}

void Game::HandlePlayerInput()
{
	if (mMoveUp)    
		mPlayer.MoveUp();
	if (mMoveDown)  
		mPlayer.MoveDown();
	if (mMoveLeft)  
		mPlayer.MoveLeft();
	if (mMoveRight) 
		mPlayer.MoveRight();
}

void Game::SpawnEnemy()
{
	int edge = rand() % 4;
	int x = 0;
	int y = 0;

	if (edge == 0) 
	{ 
		x = rand() % WINDOW_W; y = 0; 
	} 
	else if (edge == 1) 
	{ 
		x = rand() % WINDOW_W; y = WINDOW_H; 
	}  
	else if (edge == 2) 
	{ 
		x = 0; y = rand() % WINDOW_H; 
	}  
	else if (edge == 3) 
	{ 
		x = WINDOW_W; y = rand() % WINDOW_H; 
	}  

	mEnemies.push_back(std::make_unique<Enemy>("Assets/enemy.png", x, y));
}

void Game::FireBullet()
{
	Enemy* nearest = FindNearestEnemy();
	if (!nearest) 
		return;

	float dx = (float)(nearest->GetX() - mPlayer.GetX());
	float dy = (float)(nearest->GetY() - mPlayer.GetY());
	float length = std::sqrt(dx * dx + dy * dy);

	if (length == 0.0f) 
		return;

	mShotCounter++;
	std::string bulletImage;
	if (mShotCounter % 5 == 0) {
		bulletImage = "Assets/bigbullet.png";
	}
	else {
		bulletImage = "Assets/bullet.png";
	}
	mBullets.push_back(std::make_unique<Bullet>(bulletImage,mPlayer.GetX(),mPlayer.GetY(),dx/length,dy/length));
}

void Game::CheckCollisions()
{
	for (int i = 0; i < mBullets.size(); i++)
	{
		if (mBullets[i]->CheckIfHit()) continue;
		for (int j = 0; j < mEnemies.size(); j++)
		{
			if (mEnemies[j]->IsDead()) continue;
			if (Chug::Collide(mBullets[i]->GetUnit(), mEnemies[j]->GetUnit()))
			{
				mEnemies[j]->Kill();
				mBullets[i]->MarkHit();
				mKillCount++;
				break;
			}
		}
	}

	for (int i = 0; i < mEnemyBullets.size(); i++)
	{
		if (mEnemyBullets[i]->CheckIfHit()) continue;
		if (Chug::Collide(mEnemyBullets[i]->GetUnit(), mPlayer.GetUnit()))
		{
			mPlayer.TakeDamage(ENEMY_DAMAGE);
			mEnemyBullets[i]->MarkHit();
		}
	}

	for (int i = 0; i < mEnemies.size(); i++)
	{
		if (mEnemies[i]->IsDead()) continue;
		if (Chug::Collide(mEnemies[i]->GetUnit(), mPlayer.GetUnit()))
			mPlayer.TakeDamage(ENEMY_DAMAGE);
	}
}
void Game::CleanUp()
{
	for (int i = mEnemies.size() - 1; i >= 0; i--)
	{
		if (mEnemies[i]->IsDead())
		{
			mEnemies[i] = std::move(mEnemies.back());
			mEnemies.pop_back();
		}
	}
	for (int i = mBullets.size() - 1; i >= 0; i--)
	{
		if (mBullets[i]->CheckIfHit() || mBullets[i]->IsOffScreen())
		{
			mBullets[i] = std::move(mBullets.back());
			mBullets.pop_back();
		}
	}
	for (int i = mEnemyBullets.size() - 1; i >= 0; i--)
	{
		if (mEnemyBullets[i]->CheckIfHit() || mEnemyBullets[i]->IsOffScreen())
		{
			mEnemyBullets[i] = std::move(mEnemyBullets.back());
			mEnemyBullets.pop_back();
		}
	}
}
Enemy* Game::FindNearestEnemy()
{
	Enemy* nearest = nullptr;
	float  nearestDist = FLT_MAX;

	for (int i = 0; i < mEnemies.size(); i++)
	{
		if (mEnemies[i]->IsDead())
			continue;
		float dx = (float)(mEnemies[i]->GetX()-mPlayer.GetX());
		float dy = (float)(mEnemies[i]->GetY()-mPlayer.GetY());
		float dist =std::sqrt(dx * dx + dy * dy);
		if (dist < nearestDist)
		{
			nearestDist = dist;
			nearest = mEnemies[i].get();
		}
	}

	return nearest;
}

START_CHUG_GAME(Game);