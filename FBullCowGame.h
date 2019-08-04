#pragma once
#include <iostream>
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset(); // TODO Make a better return value
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;
	bool IsIsogram(std::string);




};