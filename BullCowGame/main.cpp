/*
This is the console executable, that makes use of the BullCow class.
This acts as the view in a MVC pattern, and it is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>	// for the '>>' operator in line 11.
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintBack(FText& Guess);
bool AskToPlayAgain();

FBullCowGame BCGame;

// the entry point of our application
int main() {

	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}

// introduce the game
void PrintIntro() {
	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter word I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries{ BCGame.GetMaxTries() };
	FText Guess{};

	// loop for guesses while the game is NOT won and there are still tries remaining.
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {

		// Get Guess from user.
		Guess = GetValidGuess();
		// Submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount;
		BullCowCount = BCGame.SubmitValidGuess(Guess);
		// Increment number of tries.
		BCGame.IncrementNumberTry();
		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << '\n' << std::endl;
	}
	// TODO summarise game
}

// Loop continually until the user gives a valid guess
FText GetValidGuess() {
	do {
		// Get a guess from the player
		int32 CurrentTry{ BCGame.GetCurrentTry() };
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		FText Guess{};
		std::getline(std::cin, Guess);

		EGuessStatus Status{ BCGame.CheckGuessValidity(Guess) };

		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		case EGuessStatus::Not_Isogram:
		case EGuessStatus::OK:
		default:
			return Guess;
		}
	} while (true);
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	FText Response{};
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}