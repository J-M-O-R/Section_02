/*
The game logic (no view code or direct user interaction)
The game is a simple guess the word game based on Mastermind
*/

// To make syntax Unreal friendly
#pragma once
#include <string>
#include <vector>

using FString = std::string;
using int32 = int;

const FString HIDDEN_WORD{ "planet" };

struct FBullCowCount {
	int32 Bulls{ 0 };
	int32 Cows{ 0 };
};

enum class EGuessStatus {
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame ();
	//~FBullCowGame ();

	int32 GetCurrentTry() const;
	int32 GetMaxTries() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	EGuessStatus CheckGuessValidity(FString) const;
	void IncrementNumberTry();

	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	bool bGameIsWon;
	FString MyHiddenWord;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;

	// Returns the position of a letter, not previously matched, in the hidden word. Starting from a given position. -1 if not found.
	int LookForFreeMatch(char, size_t, std::vector<int>&);
};
/*
FBullCowGame ::FBullCowGame () {
}

FBullCowGame ::~FBullCowGame () {
}
*/