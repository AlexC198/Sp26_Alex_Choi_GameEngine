#include "Counter.h"

static const std::string picture_of_number[10] =
{
	"Assets/zero.png",
	"Assets/one.png",
	"Assets/two.png",
	"Assets/three.png",
	"Assets/four.png",
	"Assets/five.png",
	"Assets/six.png",
	"Assets/seven.png",
	"Assets/eight.png",
	"Assets/nine.png"
};

KillCounter::KillCounter()
{
	for (int i = 0; i<10; i++)
	{
		mDigits[0].push_back(Chug::Unit(picture_of_number[i],50,1400));
		mDigits[1].push_back(Chug::Unit(picture_of_number[i], 50+ 80, 1400));
		mDigits[2].push_back(Chug::Unit(picture_of_number[i], 50+80*2,1400));
	}



	for (int spot = 0; spot<3;spot++)
	{
		for (int j = 0; j < 10; j++) 
		{
			mDigits[spot][j].MakeInvisible();
		}
	}
}

void KillCounter::UpdateNumber(int kills)
{
	ShowNumber(kills);
}

void KillCounter::Draw()
{
	for (int spot = 0; spot < 3; spot++) {
		for (int j = 0; j < 10;j++) 
		{
			if (mDigits[spot][j].IsVisible())
				Chug::Renderer::Get()->Draw(mDigits[spot][j]);
		}
	}
}

void KillCounter::ShowNumber(int num)
{
	num = std::min(num, 999);

	int Value[3] = { num/100, (num%100)/10, num%10 };

	for (int spot = 0; spot < 3; spot++) 
	{
		for (int j = 0; j < 10; j++) {
			if (j == Value[spot])
				mDigits[spot][j].MakeVisible();
			else
				mDigits[spot][j].MakeInvisible();
		}

	}
}