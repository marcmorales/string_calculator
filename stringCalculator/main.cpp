/* 
Author: Marc Paolo Morales
Check readmeForDevs.txt for the program's instructions
*/
#pragma once
#include <iostream>
#include <string>
#include "Token.h"
#include "calcFilter.h"

void stringCalcIntro();

int main()
{
	// TODO Introduction about the program, showing the user its functions and current limits
	stringCalcIntro();

	// TODO Ask the user to enter a string expression to be evaluated.
	/*brainstorming*/

	//char d('4');
	//std::string s("5");
	//s += d; // concatenate a char into string.
	//std::cout << s << '\n';
	//double x = std::stod(s);
	//x += 1;
	//std::cout << x << '\n';

	CalcFilter cf;
	std::string test("45+98");
	cf.stringToToken(test);

	// TODO String to be scanned and translated into a readable numerical expression
	// TODO Returns an answer or an error if the user entered unknown values.


	return 0;
}