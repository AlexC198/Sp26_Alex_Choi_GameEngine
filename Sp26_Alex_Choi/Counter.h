#pragma once

#include "Chug.h"

class KillCounter
{
public:
	KillCounter();

	void UpdateNumber(int kills);
	void Draw();

private:
	std::vector<Chug::Unit> mDigits[3];  

	void ShowNumber(int value);
};