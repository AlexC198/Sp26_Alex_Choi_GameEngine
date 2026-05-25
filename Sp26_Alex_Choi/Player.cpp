#include "Player.h"



Player::Player(const std::string& playerImage, int startingX, int startingY)
	: mUnit{ playerImage, startingX, startingY }
{
}

void Player::Update()
{
	WindowBounds();
}

void Player::Draw()
{
	Chug::Renderer::Get()->Draw(mUnit);
}

void Player::MoveUp() 
{ 
	mUnit.IncrementYPosition(PLAYER_SPEED); 
}
void Player::MoveDown() 
{ 
	mUnit.IncrementYPosition(-PLAYER_SPEED); 
}
void Player::MoveLeft() 
{ 
	mUnit.IncrementXPosition(-PLAYER_SPEED); 
}
void Player::MoveRight() 
{ 
	mUnit.IncrementXPosition(PLAYER_SPEED); 
}

void Player::TakeDamage(int amount) 
{ 
	mHp = std::max(0, mHp-amount); 
}

int  Player::GetHp() const 
{ 
	return mHp; 
}
int  Player::GetX() const 
{ 
	return mUnit.GetXCoordinate(); 
}
int  Player::GetY() const 
{ 
	return mUnit.GetYCoordinate(); 
}
bool Player::IsDead() const 
{ 
	return mHp <= 0; 
}

const Chug::Unit& Player::GetUnit() const 
{ 
	return mUnit; 
}

void Player::WindowBounds()
{
	int x = mUnit.GetXCoordinate();
	int y = mUnit.GetYCoordinate();

	int w = mUnit.GetDimensions().width;
	int h = mUnit.GetDimensions().height;

	if (x < 0)            
		mUnit.SetCoordinates(0, y);
	if (x + w > WINDOW_W) 
		mUnit.SetCoordinates(WINDOW_W - w, y);
	if (y < 0)            
		mUnit.SetCoordinates(x, 0);
	if (y + h > WINDOW_H) 
		mUnit.SetCoordinates(x, WINDOW_H - h);
}