#include "stdafx.h"
#include "Constants.h"

const string Constants::WelcomeText = "Welcome to Rochambeau v3.0.0!\n";
const string Constants::Heading = "=============================================\n";
const string Constants::NameEntryPrompt = "\nEnter your name: ";
const string Constants::ContinuePrompt = "Do you want to play again (y/n): ";
const string Constants::InvalidChoiceError = "Invalid choice - please try again.\n";
const string Constants::ChoiceIntroMessage = "\nIn this game, you can choose between paper, scissors or rock.\nPress 1 for paper, 2 for scissors or 3 for rock.\n";
const string Constants::ChoiceEntryPrompt = "Enter your choice: ";
const string Constants::DrawMessage = "\nThe match was a draw!";
const char Constants::NewLine = '\n';
const int Constants::MinValue = 1;
const int Constants::MaxValue = 3;
const int Constants::MaxScore = 2;
const string Constants::WinPrefix = "Congratulations, ";
const string Constants::LosePrefix = "Too bad, ";
const string Constants::RoundWinSuffix = "! You won this round!\n";
const string Constants::GameWinSuffix = "! You won this best out of three match!\n";
const string Constants::RoundLoseSuffix = ". You lost this round...\n";
const string Constants::GameLoseSuffix = ". You lost this best out of three match...\n";


string Constants::getRoundWinText(string playerName)
{
	return WinPrefix + playerName + RoundWinSuffix;
}

string Constants::getGameWinText(string playerName)
{
	return WinPrefix + playerName + GameWinSuffix;
}

string Constants::getRoundLoseText(string playerName)
{
	return LosePrefix + playerName + RoundLoseSuffix;
}

string Constants::getGameLoseText(string playerName)
{
	return LosePrefix + playerName + GameLoseSuffix;
}