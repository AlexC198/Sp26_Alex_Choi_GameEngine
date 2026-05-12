#pragma once

#define START_CHUG_GAME(className) \
int main()\
{\
	className game;\
	game.Run();\
	return 0;\
}