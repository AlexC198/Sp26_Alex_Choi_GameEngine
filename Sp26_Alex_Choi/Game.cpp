#include "Chug.h"

#include<iostream>
class Game : public Chug::ChugApplication
{
	virtual void Update() override
	{
		CHUG_LOG("Running nicely!");
	}
};

START_CHUG_GAME(Game);