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
FText GetGuess();
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
	// loop for the number of turns asking for guesses
	// TODO Change from FOR to WHILE loop once we are validating tries.
	for (int32 count{ 0 }; count < MaxTries; count++) {
		Guess = GetGuess();	// TODO Make loop checking valid.

		// Submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
		BCGame.IncrementNumberTry();
	}
	// TODO summarise game
}

FText GetGuess() {
	// Getting current try.
	int32 CurrentTry{ BCGame.GetCurrentTry() };
	// Get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText Guess{};
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	FText Response{};
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}