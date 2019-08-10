#pragma once
#include <iostream>
#include <string>
using int32 = int;
using FString = std::string;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Incorrect_Length,
	Extra_Words,
	No_Input,
	Not_Lowercase,
	Numbers_Included

};

enum class EResetStatus
{
	No_Hidden_Word,
	OK
};


class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset(); // TODO Make a better return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus CheckGuessValidity(FString Guess) const;

	bool IsGameWon() const;


	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	bool IsIsogram(FString);
	FString MyHiddenWord;



};