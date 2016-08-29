#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	computerScore = 0;
	playerScore = 0;
}


Game::~Game()
{
}

void Game::play(string playerName)
{
	// reset player scores to zero
	playerScore = 0;
	computerScore = 0;

	while (playerScore < 2 && computerScore < 2)
	{
		Move* playersChoice = new Move((MoveTypes)getPlayerChoice());
		Move* computerChoice = new Move((MoveTypes)getComputerChoice());

		if (playersChoice == computerChoice)
		{
			cout << "\nThe match was a draw!";
		}
		else 
		{
			if (playersChoice > computerChoice)
			{
				cout << "\nCongrats, " << playerName << "! You won this round!";
				playerScore++;
			}
			else
			{
				cout << "\nToo bad, " << playerName << ". You lost this round...";
				computerScore++;
			}
		}
	}

	if (playerScore > computerScore)
	{
		cout << "\nCongratulations, " << playerName << "! You won this best out of three match!\n";
	}
	else
	{
		cout << "\nToo bad, " << playerName << ". You lost this best out of three match...\n";
	}
}





int Game::getPlayerChoice()
{
	int result;
	cout << "\nIn this game, you can choose between paper, scissors or rock."
	     << "\nPress 1 for paper, 2 for scissors or 3 for rock.\n";
	
	while (cout << "Enter your choice: " && !(cin >> result))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "Invalid choice - please try again.\n";
	}
	return result;

}


int Game::getComputerChoice()
{
	mt19937 eng;
	eng.seed(random_device()());
	uniform_int_distribution<mt19937::result_type> dist3(1, 3);
	return dist3(eng);
}
