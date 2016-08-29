#pragma once
#include <string>

using namespace std;


class Constants
{
public:
	static const string WelcomeText;
	static const string Heading;
	static const string NameEntryPrompt;
	static const string ChoiceEntryPrompt;
	static const string ContinuePrompt;
	static const string InvalidChoiceError;
	static const string DrawMessage;
	static const string ChoiceIntroMessage;
	static string getRoundWinText(string playerName);
	static string getRoundLoseText(string playerName);
	static string getGameWinText(string playerName);
	static string getGameLoseText(string playerName);
private:
	Constants();
	static const string WinPrefix;
	static const string LosePrefix;
	static const string RoundWinSuffix;
	static const string RoundLoseSuffix;
	static const string GameWinSuffix;
	static const string GameLoseSuffix;
};

