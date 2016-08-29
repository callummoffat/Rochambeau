#pragma once
#include "Move.h"
#include <random>
#include <string>
#include <iostream>

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void play(string playerName);
private:
	int computerScore;
	int playerScore;
	int getPlayerChoice();
	int getComputerChoice();
};

