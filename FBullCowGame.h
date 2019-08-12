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

struct FHiddenWordDictionary
{
	FString Three_HiddenWord[3] =
	{
		"and",
		"ant",
		"any"
	};
	FString Four_HiddenWord[3] =
	{
		"ahem",
		"park",
		"pack"
	};
	FString Five_HiddenWord[3] =
	{
		"dance",
		"darts",
		"mail"
	};
	FString Six_HiddenWord[3] =
	{
		"planets",
		"fabled",
		"falcon"
	};

};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Incorrect_Length,
	Not_Lowercase,

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

	void SetHiddenWord(FString NewWord);

	bool IsGameWon() const;
	FBullCowCount SubmitValidGuess(FString);

	FString CreateHiddenWord(FString WordLength);

private:
	int32 MyCurrentTry;
	bool IsIsogram(FString Guess) const;
	bool IsLowercase(FString Guess) const;
	FString MyHiddenWord;

	bool bGameIsWon;

};