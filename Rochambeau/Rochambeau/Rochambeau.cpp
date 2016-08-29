// Rochambeau.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

const string GameVersion = "v2.1.0";

string getPlayerName()
{
	string result;
	cout << "\nEnter your name: ";
	cin >> result;
	return result;
}

bool continuePrompt()
{
	char input;
	

	while (cout << "Do you want to play again (y/n): " && !(cin >> input))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "Invalid choice - please try again.\n";
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
		cout << "Invalid choice - please try again.\n";
		return continuePrompt();


	}
}

int main()
{
	

	cout << "Welcome to Rochambeau " << GameVersion << "!\n"
		 << "==============================================\n";
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

