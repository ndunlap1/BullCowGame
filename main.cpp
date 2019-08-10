/* This is the console executable, that makes  use of the Bull Cow Class
THis acts as the view in a MVC pattern and is responsible for all user interaction.
For game logic see the FBullCowGame class.


*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
void PrintGameSummary();
FText GetValidGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;

//Start of the game
int main()
{
	do
	{
		PrintIntro();
		PlayGame();

	} while (AskToPlayAgain());

	return 0;
}



void PrintIntro() {

	//Introduction to Game
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter iosgram that I'm thinking of?\n" << std::endl;
	return;
}

void PlayGame() {


	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "Number of max tries: " << MaxTries << std::endl;

	//Loop for the number of turns asking for guesses

	// Loop asking for guesses while the game 
	// is NOT won and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess(); //TODO make loop checking valid

		// Submit valid guess to game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << std::endl;

	}

	// TODO Sumarize game
	PrintGameSummary();
	return;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "You have won! Congratulations!\n";
	}
	else
	{
		std::cout << "You have lost. Better luck next time!\n";
	}
}

FText GetValidGuess() {

	FText Guess = "";
	EGuessStatus GuessStatus = EGuessStatus::Invalid_Status;
	do {
		// Get guess from the player
		Guess = "";
		std::cout << "Try " << BCGame.GetCurrentTry() << ". ";
		std::cout << "Please enter your guess:";
		getline(std::cin, Guess);

		// Check status and give feedback
		GuessStatus = BCGame.CheckGuessValidity(Guess);

		switch (GuessStatus)
		{
		case EGuessStatus::Incorrect_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word." << std::endl;
			break;
		case EGuessStatus::Extra_Words:
			std::cout << "Too many words! Please enter a single " << BCGame.GetHiddenWordLength() << " letter word." << std::endl;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters" << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please verify that all letters were entered in lowercase." << std::endl;
			break;
		case EGuessStatus::No_Input:
			std::cout << "No input was given." << std::endl;
			break;
		case EGuessStatus::Numbers_Included:
			std::cout << "Numbers should not be included." << std::endl;
			break;
		default:
			// assume guess is valid
			break;
		}
		std::cout << std::endl;
	} while (GuessStatus!= EGuessStatus::OK);
	return Guess;
}


bool AskToPlayAgain() {
	std::cout << "Do you want to play again with the same hidden word (y/n)? ";
	FText Response = "";
	getline(std::cin, Response);
	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}