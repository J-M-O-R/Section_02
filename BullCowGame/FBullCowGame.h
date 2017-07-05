#pragma once
#include <string>

class FBullCowGame {
public:
	//FBullCowGame ();
	//~FBullCowGame ();

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void IncrementNumberTry();

	void Reset();
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry{ 1 };
	int MyMaxTries{ 5 };
	
	//bool IsIsogram(std::string word);
};
/*
FBullCowGame ::FBullCowGame () {
}

FBullCowGame ::~FBullCowGame () {
}
*/