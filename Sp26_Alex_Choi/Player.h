#pragma once

#include "Chug.h"

constexpr int PLAYER_SPEED = 8;
constexpr int PLAYER_HEALTH = 100;
constexpr int WINDOW_W = 2000;
constexpr int WINDOW_H = 1600;

class Player
{
public:
	Player(const std::string& playerImage, int startingX, int startingY);

	void Update();
	void Draw();
	

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();


	void TakeDamage(int amount);

	int  GetHp() const;
	int  GetX() const;
	int  GetY() const;
	bool IsDead() const;

	const Chug::Unit& GetUnit() const;

private:
	Chug::Unit mUnit;
	int mHp{ PLAYER_HEALTH };

	void WindowBounds();
};