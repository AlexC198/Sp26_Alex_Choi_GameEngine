#include "Chug.h"

#include<iostream>
class Game : public Chug::ChugApplication
{
	void Initialize() override
	{
		SetKeyCallback([this](const Chug::KeyEvent& event) {
			if (event.GetKeyCode() == Chug::Key::RIGHT && event.GetAction() == Chug::KeyAction::PRESS)
				unit.IncrementXPosition(10);
			else if (event.GetKeyCode() == Chug::Key::LEFT && event.GetAction() == Chug::KeyAction::PRESS)
				unit.IncrementXPosition(-10);
			});
	}

	virtual void Update() override
	{
		//CHUG_LOG("Running nicely!");
		if (Collide(unit, unit2))
			CHUG_LOG("Collision");

		Chug::Renderer::Get()->Draw(unit);
		Chug::Renderer::Get()->Draw(unit2);
	}

private:
	Chug::Unit unit{ "../Chug/Assets/Images/Character.png",100, 100 };
	Chug::Unit unit2{ "../Chug/Assets/Images/Character.png", 500, 100 };
};

START_CHUG_GAME(Game);