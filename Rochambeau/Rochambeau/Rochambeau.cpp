// Rochambeau.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

const string GameVersion = "v2.1.0";

string getPlayerName()
{
	string result;
	cout << Constants::NameEntryPrompt;
	cin >> result;
	return result;
}

bool continuePrompt()
{
	char input;
	

	while (cout << Constants::ContinuePrompt && !(cin >> input))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << Constants::InvalidChoiceError;
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
	

	cout << Constants::WelcomeText
		 << Constants::Heading;
	string name = getPlayerName();

	Game* game = new Game();

	while (true)
	{
		game->play(name);

		if (!continuePrompt())
			break;
	}
	
	cout << "\n";
	system("pause");
	delete game;
    return 0;
}

