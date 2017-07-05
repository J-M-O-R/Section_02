#include <iostream>
#include <string>	// for the '>>' operator in line 11.
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
void PrintBack(std::string& Guess);
bool AskToPlayAgain();

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
	constexpr int WORD_LENGTH{ 5 };
	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {
	FBullCowGame BCGame;

	constexpr int NUMBER_OF_TURNS{ 5 };
	std::string Guess{};
	// loop for the number of turns asking for guesses
	for (int count{ 0 }; count < NUMBER_OF_TURNS; count++) {
		Guess = GetGuess();
		PrintBack(Guess);
		std::cout << std::endl;
	}
}

std::string GetGuess() {
	// get a guess from the player
	std::cout << "Enter your guess: ";
	std::string Guess{};
	std::getline(std::cin, Guess);

	return Guess;
}

void PrintBack(std::string& Guess) {
	// repeat the guess back to them
	std::cout << "Your guess was: " << Guess << '\n';
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	std::string Response{};
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}