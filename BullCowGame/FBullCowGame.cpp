#pragma once

#include "FBullCowGame.h"
#include <map>

// To make syntax Unreal friendly
#define TMap std::map

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ { 3, 4 }, { 4, 7 }, { 5, 10 }, { 6, 16 }, { 7, 20 } };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}


int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::IncrementNumberTry() {
	MyCurrentTry++;
}

void FBullCowGame::Reset() {
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	if (int(Guess.length()) > GetHiddenWordLength()) {	// Check for length
		return EGuessStatus::Wrong_Length;
	} else if (!IsLowercase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	} else if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	} else {
		return EGuessStatus::OK;
	}
}

// Receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	FBullCowCount BullCowCount;
	// Vector that marks the positions matched in MyHiddenWord, by saving the position in Guess which made the match.
	std::vector<int> MatchedInHidden(MyHiddenWord.length(), -1);
	int PositionFound{ -1 };
	size_t GuessLength{ Guess.length() };

	// loop through all letters in the guess, and compare them against the hidden word
	for (size_t i{ 0 }; i < GuessLength; i++) {

		// Bulls prevail over cows, so let's just check for the Bull first.
		if (Guess[i] == MyHiddenWord[i]) {
			BullCowCount.Bulls++;
			// If this position in MyHiddenWord was already matched previously we have to look for
			// another left free occurrance of the character before discounting the Cows.
			if (MatchedInHidden[i] >= 0) {
				PositionFound = LookForFreeMatch(Guess[i], i + 1, MatchedInHidden);
				if (PositionFound >= 0) {
					// Yes, there is another free occurrence
					MatchedInHidden[PositionFound] = MatchedInHidden[i];
				} else {
					// Not another free occurrence, discount Cows
					BullCowCount.Cows--;
				}
			}
			MatchedInHidden[i] = i;
		} else {
			// Not a Bull, let's look for a Cow
			PositionFound = LookForFreeMatch(Guess[i], 0, MatchedInHidden);
			if (PositionFound >= 0) {
				// Marking the possition found in MyHiddenWord with the position of the letter in Guess.
				MatchedInHidden[PositionFound] = i;
				BullCowCount.Cows++;
			}
		}

	}
	// Before leaving, check if the game was won.
	if (BullCowCount.Bulls == GetHiddenWordLength()) {
		bGameIsWon = true;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const {
	// Treat 0 and 1 letter words as isograms.
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;

	for (auto Letter : Word) {
		Letter = tolower(Letter);

		if (LetterSeen[Letter]) {
			return false;
		} else {
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const {
	for (auto Letter : Word) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}

int FBullCowGame::LookForFreeMatch(char letter, size_t start, std::vector<int>& matched) {
	size_t HiddenWordLength{ MyHiddenWord.length() };
	for (size_t i{ start }; i < HiddenWordLength; i++) {
		if (MyHiddenWord[i] == letter && matched[i] < 0) {
			return int(i);
		}
	}
	return -1;
}
