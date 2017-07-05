#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const {
	return false;
}

void FBullCowGame::IncrementNumberTry() {
	MyCurrentTry++;
}

void FBullCowGame::Reset() {
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	return;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	return EWordStatus::OK;
}

// Receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	// Increment the turn number.
	MyCurrentTry++;
	// Setup a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in the guess
	// Vector that marks the positions matched in MyHiddenWord, by saving the position in Guess which made the match.
	std::vector<int> MatchedInHidden(MyHiddenWord.length(), -1);
	int PositionFound{ -1 };
	size_t GuessLength{ Guess.length() };

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
	// compare letters against the hidden word
	return BullCowCount;
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
