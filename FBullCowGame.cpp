#include "FBullCowGame.h"
#include <map>
#define TMAP std::map

using FString = std::string;
using int32 = int;

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

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
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "ant";

	MyMaxTries = MAX_TRIES;

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
	else if (false)// if the guess ins't all lowercase // TDOO write lowercase
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

bool FBullCowGame::IsIsogram(FString Guess) const
{
	// Treat 0 and 1 letter words as isograms
	// Loop through characters of Guess
		// Check the character, and set that character true in the hash table
		// If character is already true, 
			//then break, and reuturn false that the word is not an isogram
		// else add letter to map
	// If at end of word, return true for isogram.
		

	return true;
}
