#ifndef TOKEN_H
#define TOKEN_H

#include <math.h>
#include <iostream>

class Token
{
public:
	Token(); // default values for constructor
	Token(char, double);
	Token(char);
	Token(double);
	~Token();

	// setters
	void setOperateToken(char);
	void setValueToken(double);

	// getters
	char getOperateToken();
	double getValueToken();

private:
	char operateVal;
	double m_value;
};

#endif TOKEN_H


