#pragma once
#include <string>

class FBullCowGame {
public:
	//FBullCowGame ();
	//~FBullCowGame ();

	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;
	
	//bool IsIsogram(std::string word);
};
/*
FBullCowGame ::FBullCowGame () {
}

FBullCowGame ::~FBullCowGame () {
}
*/