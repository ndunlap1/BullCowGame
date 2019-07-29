#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();
string GetGuessAndPrintBack();


//Start of the game
int main()
{
	PrintIntro();

	//Loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;

	for(int Count = 1; Count <=NUMBER_OF_TURNS; Count++) {
		GetGuessAndPrintBack();
		cout << endl;
	}


	return 0;
}

void PrintIntro() {

	//Introduction to Game
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows" << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter iosgram that I'm thinking of?\n" << endl;
	return;
}

string GetGuess() {
	string Guess = "";
	cout << "Please enter your guess:";
	getline(cin, Guess);

	return Guess;
}

string GetGuessAndPrintBack() {
	string Guess = "";
	cout << "Please enter your guess:";
	getline(cin, Guess);
	cout << "\nYour guess was: " << Guess << endl;
	return Guess;
}