#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const {
	return false;
}

void FBullCowGame::IncrementNumberTry() {
	MyCurrentTry++;
}

void FBullCowGame::Reset() {
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString) {
	return false;
}
