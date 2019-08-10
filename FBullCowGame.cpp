#include "FBullCowGame.h"

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
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "auntie";

	MyMaxTries = MAX_TRIES;

	
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// if the guess isn't an isogram
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)// if the guess ins't all lowercase
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
	


	return EGuessStatus::OK; // TODO make actuall error check
}

// Recieves a VALID guess, incriments and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// incriment turn number
	MyCurrentTry++;

	// setup return variable
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();

	// loop through all letters in the guess
	for (int32 GuessIndex = 0; GuessIndex < Guess.length(); GuessIndex++)
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
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString)
{
	return false;
}
