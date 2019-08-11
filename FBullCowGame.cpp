#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {3, 5}, {4,5}, {5,5}, {6,5} };
	return WordLengthToMaxTries[MyHiddenWord.length()]; 
}

int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

FBullCowGame::FBullCowGame()
{
	Reset();
	return;
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = CreateHiddenWord(3);

	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const // TODO fix error checks
{
	// if the guess isn't an isogram // TODO write function+-
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))// if the guess ins't all lowercase // TDOO write lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())	// if the guess length is wrong 
	{
		return EGuessStatus::Incorrect_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
	


	return EGuessStatus::OK;
}

// Recieves a VALID guess, incriments and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	int32 GuessWordLength = Guess.length();

	// loop through all letters in the guess
	for (int32 GuessIndex = 0; GuessIndex < GuessWordLength; GuessIndex++)
	{
		// Compare letters against the hidden word
		for (int32 HiddenWordIndex = 0; HiddenWordIndex < HiddenWordLength; HiddenWordIndex ++)
		{
			// If they match then
			if (Guess[GuessIndex] == MyHiddenWord[HiddenWordIndex])
			{
				//if they are in the same place
				if (GuessIndex == HiddenWordIndex)
				{
					// incriment bulls if they're in the same place
					BullCowCount.Bulls++;
				}
				else
				{
					// incriment cows if they are not
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == HiddenWordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

FString FBullCowGame::CreateHiddenWord(int32 WordLength)
{
	FHiddenWordDictionary NewHiddenWord;
	switch (WordLength)
	{
	case 3:
		return NewHiddenWord.Three_HiddenWord[rand()%3];
		break;
	case 4:
		return NewHiddenWord.Four_HiddenWord[rand() % 3];
		break;
	case 5:
		return NewHiddenWord.Five_HiddenWord[rand() % 3];
		break;
	case 6:
		return NewHiddenWord.Six_HiddenWord[rand() % 3];
		break;
	default:
		return NewHiddenWord.Three_HiddenWord[rand() % 3];
		break;
	}
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	// Treat 0 and 1 letter words as isograms
	if (Guess.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; // Setup our map

	// Loop through characters of Guess
	for (auto Letter : Guess) // for all letters of the word
	{
		Letter = tolower(Letter); // Handle mixed case

		// Check the character, and set that character true in the hash table
		if (LetterSeen[Letter]) //Character is already true
		{
			return false; // Not an isogram
		}
		else
		{
			LetterSeen[Letter] = true; // Set character to true
		}
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
	if (Guess.length() <= 1) { return true; }

	// Loop through characters of Guess
	for (auto Letter : Guess) // for all letters of the word
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}

int32 FBullCowGame::GetHiddenWordDifficulty()
{
	FString PlayerHiddenWordLength;
	std::cout << " Please enter the length of the word that you would like to guess (3-6 characters long): ";
	getline(std::cin, PlayerHiddenWordLength);

	TMap<FString, int32> HiddenWordLength{
		{"3", 3},
		{"4", 4},
		{"5", 5},
		{"6", 6}
	};

	if (HiddenWordLength[PlayerHiddenWordLength] == NULL)
	{
		std::cout << "Unfortunately an isogram cannot be created with a length of " << PlayerHiddenWordLength << ". Switching the game over to a 3 letter isogram." << std::endl;
		return 3;
	}
	else
	{
		return HiddenWordLength[PlayerHiddenWordLength];
	}


}