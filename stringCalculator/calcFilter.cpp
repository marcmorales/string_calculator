#include "calcFilter.h"

// default values initialized to filter values transfered to token.
CalcFilter::CalcFilter() :
	// TODO, find a way we can use a const value to initialize these variables.
	currentCharVal('@'),
	concatStringToDouble(NAN),
	appendCharToString("DefaultString"),
	triggerNumIdentifier(false),
	triggerOperatorIdentifier(false)
{
	std::cout << "constructor ran!\n"; // troubleshoot
}

CalcFilter::~CalcFilter() {}

void CalcFilter::stringToToken(std::string userString)
{
	for (size_t i = 0; i < userString.length(); ++i)
	{
		this->currentCharVal = userString[i]; // write the char val from userString into currentCharVal

		// check what kind of character is in currentCharVal
		myCharType charEnum(EcheckCurrentCharValue());

		// have some function that validates each enum value and sort currentCharVal to its proper type.
		updateCurrentCharToProperType(charEnum);

		/*
			Area for creating tokens, certain scenarios must be met to create tokens
		*/
		// -1 is because i (counter) will always be less than 1 as it starts from 0. this will probably cause a bug. verify
		if ((this->triggerNumIdentifier == false && this->concatStringToDouble != NAN) || i == userString.length() - 1)
		{
			Token tempToken(this->concatStringToDouble);
			if (triggerOperatorIdentifier)
			{
				tempToken.setOperateToken(this->currentCharVal); // this will make numToken return two values initiated with proper value
				this->appendCharToString = "DefaultString"; // TODO reset. Should not be a magic value
			}
			myToken.push_back(tempToken); // defined value and default operator
		}

		// create a robust reset function that accommodate current member variable status. currently doing it inline.
	}

	// parse tokens accumulated in myToken
}

myCharType CalcFilter::EcheckCurrentCharValue()
{
	// TODO, find a way to make this more organized. As of now, chain of if-else looks bad

	char myVal(this->currentCharVal);

	if (myVal >= '0' && myVal <= '9')
		return myCharType::isNumeral;

	else if (myVal >= 'a' && myVal <= 'z' || myVal >= 'A' && myVal <= 'Z')
		return myCharType::isLetter;
	
	else if (myVal == '.')
		return myCharType::isDot;
	
	else if (myVal == ' ')
		return myCharType::isSpace;
	
	else if (myVal == '+' || myVal == '-' || myVal == '*' || myVal == '/')
		return myCharType::isOperator;

	else if (myVal == '(' || myVal == ')')
		return myCharType::isParenthesis;
	

	return myCharType::isUnknown; // default return value
}

void CalcFilter::updateCurrentCharToProperType(myCharType& enumVal)
{
	// TODO, create a better way to change values for trigger booleans
	switch (enumVal)
	{
	case isNumeral:
		triggerNumIdentifier = true;
		triggerOperatorIdentifier = false;
		// TODO, fix this one, should not have "DefaultString" as a verifier.
		(this->appendCharToString == "DefaultString") // check if it still has the initial default value
			? this->appendCharToString = this->currentCharVal // replaces default value
			: this->appendCharToString += this->currentCharVal; // += operator appends a char into a string type just like push_back

		this->concatStringToDouble = std::stod(this->appendCharToString); // convert string value to double.
		break;
	case isLetter:
		triggerNumIdentifier = false;
		triggerOperatorIdentifier = false;
		// need to create a function to handle this as certain letters must come together to identify what letter/operator it is.
		// this is what defines string calculator, probably create a separate class for this.
		break;
	case isOperator:
		triggerNumIdentifier = false;
		triggerOperatorIdentifier = true;

		break;
	default:
		// error if this goes through
		break;
	}
}