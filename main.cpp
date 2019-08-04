#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;

//Start of the game
int main()
{
	std::cout << BCGame.GetCurrentTry() << "and" << BCGame.GetMaxTries();
	do
	{

		PrintIntro();
		PlayGame();

	} while (AskToPlayAgain());

	return 0;
}



void PrintIntro() {

	//Introduction to Game
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter iosgram that I'm thinking of?\n" << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	std::cout << BCGame.GetCurrentTry() << "and" << BCGame.GetMaxTries();
	int MaxTries = BCGame.GetMaxTries();
	std::cout << "Number of max tries: " << MaxTries << std::endl;

	//Loop for the number of turns asking for guesses
	for (int Count = 1; Count <= MaxTries; Count++) {
		std::string Guess = GetGuess(); //TODO make loop checking valid

		// Submit valid guess to game
		// Print number of bulls and cows
		std::cout << "\nYour guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO Sumarize game

	return;


}

std::string GetGuess() {
	std::string Guess = "";
	std::cout << "Try " << BCGame.GetCurrentTry() << ". ";
	std::cout << "Please enter your guess:";
	getline(std::cin, Guess);
	return Guess;
}


bool AskToPlayAgain() {
	std::cout << "Do you want to play again? ";
	std::string Response = "";
	getline(std::cin, Response);
	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}