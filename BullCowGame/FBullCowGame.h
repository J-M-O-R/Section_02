#pragma once
#include <string>

using FString = std::string;
using int32 = int;

constexpr int32 MAX_TRIES{ 8 };

class FBullCowGame {
public:
	FBullCowGame ();
	//~FBullCowGame ();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void IncrementNumberTry();

	void Reset();
	bool CheckGuessValidity(FString);	// TODO Make a richer return value.
	// Provide a method for counting bulls & cows, and increasing try #

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;

	//bool IsIsogram(FString word);
};
/*
FBullCowGame ::FBullCowGame () {
}

FBullCowGame ::~FBullCowGame () {
}
*/