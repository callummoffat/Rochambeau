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

// This method plays a round of Paper/Scissors/Rock.
void Game::play(string playerName)
{
	// reset player scores to zero
	playerScore = 0;
	computerScore = 0;

	// This loop repeats until either player has won two out of three matches.
	// The score is increased if the player or the computer wins, but
	// NOT if the match is a draw.
	while (playerScore < Constants::MaxScore && computerScore < Constants::MaxScore)
	{
		Move* playersChoice = new Move(getPlayerChoice());
		Move* computerChoice = new Move(getComputerChoice());

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

		delete playersChoice;
		delete computerChoice;

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




// Gets the player's choice of paper, scissors or rock (1, 2 or 3)
MoveTypes Game::getPlayerChoice()
{
	int result;
	cout << Constants::ChoiceIntroMessage;

	// This loop checks for invalid input, and prevents it from being used.
	while (cout << Constants::ChoiceEntryPrompt && !(cin >> result))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), Constants::NewLine); //discard input
		cout << Constants::InvalidChoiceError;
	}

	// Checks for an invalid value
	if (result < Constants::MinValue || result > Constants::MaxValue)
	{
		cout << Constants::InvalidChoiceError;
		return getPlayerChoice();
	}

	switch (result)
	{
	case 1:
		return MoveTypes::Paper;
	case 2:
		return MoveTypes::Scissors;
	case 3:
		return MoveTypes::Rock;
	default:
		return MoveTypes::None;
	}

}


MoveTypes Game::getComputerChoice()
{
	// generate random number from 1 to 3.
	mt19937 eng;
	eng.seed(random_device()());
	uniform_int_distribution<mt19937::result_type> dist3(Constants::MinValue, Constants::MaxValue);
	int result = dist3(eng);

	// get the result.
	switch (result)
	{
	case 1:
		return MoveTypes::Paper;
	case 2:
		return MoveTypes::Scissors;
	case 3:
		return MoveTypes::Rock;
	default:
		return MoveTypes::None;
	
			
	}
	

}
