// Rochambeau.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

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
	default:
		return false;


	}
}

int main()
{
	

	cout << "Welcome to Rochambeau (version 2.0)!";
	string name = getPlayerName();

	Game* game = new Game();

	while (true)
	{
		game->play(name);

		if (!continuePrompt())
			break;
	}
	
	system("pause");
    return 0;
}

