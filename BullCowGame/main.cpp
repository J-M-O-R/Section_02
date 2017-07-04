#include <iostream>
#include <string>	// for the '>>' operator in line 11.

void PrintIntro();

// the entry point of our application
int main() {
	PrintIntro();
	// get a guess from the player
	std::cout << "Enter your guess: ";
	std::string Guess{};
	std::getline(std::cin, Guess);
	std::cout << std::endl;
	// repeat the guess back to them
	std::cout << "Your guess was: " << Guess << '\n';
	std::cout << std::endl;
	return 0;
}

void PrintIntro() {
	constexpr int WORD_LENGTH{ 5 };
	// introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}