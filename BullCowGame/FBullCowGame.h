#pragma once
#include <string>
#include <vector>

using FString = std::string;
using int32 = int;

constexpr int32 MAX_TRIES{ 8 };
const FString HIDDEN_WORD{ "planet" };

// All values initialized to zero.
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

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	EGuessStatus CheckGuessValidity(FString) const;	// TODO Make a richer return value.

	void IncrementNumberTry();

	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	bool bGameIsWon;

	FString MyHiddenWord;

	//bool IsIsogram(FString word);

	// Returns the position of a letter, not previously matched, in the hidden word. Starting from a given position. -1 if not found.
	int LookForFreeMatch(char, size_t, std::vector<int>&);
};
/*
FBullCowGame ::FBullCowGame () {
}

FBullCowGame ::~FBullCowGame () {
}
*/