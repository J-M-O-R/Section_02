#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const {
	return false;
}

void FBullCowGame::IncrementNumberTry() {
	MyCurrentTry++;
}

void FBullCowGame::Reset() {
	return;
}

bool FBullCowGame::CheckGuessValidity(std::string) {
	return false;
}
