/*Filters user input into readable numerical value.
Current version:
	6/25/2019, 6/26/2019
		A function that will store numerical values.
			if reading a number, store it on a temp variable and wait for next input
			if reading another number or a dot, add it on the temp variable
			if reading anything else, terminate number reading and store whats on temp variable into token.
*/

#ifndef CALCFILTER_H
#define CALCFILTER_H

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include "Token.h"

enum myCharType
{
	isNumeral,
	isLetter,
	isOperator,
	isSpace,
	isParenthesis,
	isDot,
	isUnknown,
	isDebugging // temp
};

class CalcFilter
{

private:
	std::vector<Token> myToken; // stores all token for evaluation

	char currentCharVal; // stores current char from stringToToken loop
	std::string appendCharToString; // this concatenate/append char into a string type
	double concatStringToDouble; // convert what is stored in appendCharToString to type double

	bool triggerNumIdentifier; // trigger key for when to create token for numbers.
	bool triggerOperatorIdentifier; // trigger key for when to create token for operators.

public:
	CalcFilter();
	~CalcFilter();

	void stringToToken(std::string);
	myCharType EcheckCurrentCharValue();

	void updateCurrentCharToProperType(myCharType&);

};



#endif // CALCFILTER_H
