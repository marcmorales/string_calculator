#include "Token.h"

Token::Token() : operateVal('#'), m_value(NAN) {} // default
Token::Token(char c, double d) : operateVal(c), m_value(d) {}
Token::Token(char c) : operateVal(c), m_value(NAN) {}
Token::Token(double d) : operateVal('#'), m_value(d) {}

Token::~Token() {
	std::cout << "token destructor ran\n"; // *troubleshooting*. remove at final refactor
}

void Token::setOperateToken(char c) { operateVal = c; }
void Token::setValueToken(double v) { m_value = v; }

char Token::getOperateToken() { return operateVal; }
double Token::getValueToken() { return m_value; }
