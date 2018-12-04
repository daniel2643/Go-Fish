/*
 *    UtilityFunctions.app
 *    Week 07 Starter Files
 *
 *    Created by Joshua Olsen on 05/09/2016
 *    Copyright 2016 Monash University.
 */


#include "UtilityFunctions.h"

/**
	Returns a string that has had basic validation checks done.
	Currently only a length check but this could be extended

	@param Message to show the user until they enter something valid
	@return Validated string variable
*/
std::string getUserInput(std::string sMessage)
{
	bool isValid = false;
	std::string sUserInput = "";

	// While isValid is NOT true
	while (!isValid)
	{
		// Print out message function has been provided
		std::cout << sMessage << std::endl;

		// Use getline instead of cin directly to get input
		// Doing it this way will get everything entered up to \n delimiter (cin stops at a space)
		std::getline(std::cin, sUserInput);

		// Validation check to see if the user entered anything
		// More validation should be added here but this is an ok starting place
		if (sUserInput.length() > 0)
		{
			isValid = true;
		}
	}

	return sUserInput;
}

/**
	Returns a character that has had basic validation checks done.
	Makes use of getUserInput function for less duplicate code

	@param Message to show the user until they enter something valid
	@return Character user entered
*/
char getUserInputChar(std::string sMessage)
{
	bool isValid = false;
	char cUserInput;
	std::string sUserInput = "";

	// While isValid is NOT true
	while (!isValid)
	{
		// Call getUserInput function to get string. Saves on code duplication
		// and also ensures any extra validation is always done
		sUserInput = getUserInput(sMessage);

		// Make sure sUserInput is actually a character first
		if (sUserInput.length() == 1)
		{
			// Get first index of sUserInput as this is out char
			cUserInput = sUserInput[0];

			isValid = true;
		}
	}

	return cUserInput;
}
