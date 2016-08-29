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
			cout << Constants::DrawMessage;
		}
		else 
		{
			if (playersChoice > computerChoice)
			{
				cout << Constants::getRoundWinText(playerName);
				playerScore++;
			}
			else
			{
				cout << Constants::getRoundLoseText(playerName);
				computerScore++;
			}
		}
	}

	if (playerScore > computerScore)
	{
		cout << Constants::getGameWinText(playerName);
	}
	else
	{
		cout << Constants::getGameLoseText(playerName);
	}
}





int Game::getPlayerChoice()
{
	int result;
	cout << Constants::ChoiceIntroMessage;

	while (cout << Constants::ChoiceEntryPrompt && !(cin >> result))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << Constants::InvalidChoiceError;
	}

	if (result < 1 || result > 3)
	{
		cout << Constants::InvalidChoiceError;
		return getPlayerChoice();
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
