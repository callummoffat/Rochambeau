// Rochambeau.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

string getPlayerName()
{
	string result;
	cout << Constants::NameEntryPrompt;
	cin >> result;
	return result;
}


bool continuePrompt()
{
	cout << Constants::NewLine;
	// create a char object for input
	char input;
	
	// display a prompt, and show an error if invalid data is provided.
	while (cout << Constants::ContinuePrompt && !(cin >> input))
	{
		cin.clear(); // clear the bad input bit
		cin.ignore(numeric_limits<streamsize>::max(), Constants::NewLine); //discard input
		cout << Constants::InvalidChoiceError; // display an error
	}

	switch (input)
	{
	case 'y':
	case 'Y':
		return true;
	case 'n':
	case 'N':
		return false;
	default:
		cout << Constants::InvalidChoiceError;
		return continuePrompt();


	}

	
}


int main()
{
	

	// output heading
	cout << Constants::WelcomeText
		 << Constants::Heading;

	// get the name of the player
	string name = getPlayerName();

	// create a new Game object
	Game* game = new Game();

	// enter an infinite loop where the game is repeatedly played
	// and a play again prompt is displayed afterwards.
	// The loop exits after the player opts not to continue playing.
	while (true)
	{
		// play the game
		game->play(name);

		// display "play again" prompt
		if (!continuePrompt())
			break;
	}
	
	// output a new line
	cout << Constants::NewLine;
	// displays press any key prompt
	system("pause");

	// deletes the reference to the Game object - it is no longer necessary
	delete game;

	
    return 0;
}

