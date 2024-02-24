// TO BE COMPLETED:
//		postfix()

// SOLUTION: InfixToPost.h
#ifndef INFIX_TO_POSTFIX
#define INFIX_TO_POSTFIX

#include <iostream>
#include <string>
#include "MyStack.h"
#include <ctype.h>

#include "ExpressionSymbol.h"	// expressionSymbol class
#include "CS255Exceptions.h"	// for expressionError exception
#include "ExpressionSymbol.h"

using namespace std;

// labels designating the parentheses characters
const char lParen = '(';
const char rParen = ')';

class InfixToPostfix
{
public:
	// default constructor. infix expression is NULL string
	InfixToPostfix();

	// initialize the infix expression
	InfixToPostfix(const string& infixExp);

	// change the infix expression
	void setInfixExp(const string& infixExp);

	// return a string that contains the equivalent postfix expression.
	//   The function throws ExpressionError if an error occurs during conversion
	string postfix();

private:
	// the infix expression to convert
	string infixExpression;

	// built to contain the postfix equivalent of infixExpression
	string postfixExpression;

	// stack of expressionSymbol objects
	myStack<ExpressionSymbol> operatorStack;

	// The expressionSymbol object op holds the current symbol.
	//   Pop the stack and output as long as the symbol
	//   on the top of the stack has a precedence >= that of
	//   the current operator
	void outputHigherOrEqual(const ExpressionSymbol& op);

	// is ch one of '+','-','*','/', '^'
	bool isOperator(char ch) const;
};

// Determine which operators need to be popped from stack
//	before adding the new operator, "op"
//  Determines whether operator left on the stack should be output before
//  pushing operator right on the stack
void InfixToPostfix::outputHigherOrEqual(const ExpressionSymbol& op) {
	ExpressionSymbol op2;

	while (!operatorStack.isEmpty() && (op2 = operatorStack.top()) >= op) {
		operatorStack.pop();
		postfixExpression += op2.getOp();
		postfixExpression += ' ';
	}
}

bool InfixToPostfix::isOperator(char ch) const {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

InfixToPostfix::InfixToPostfix() {}

InfixToPostfix::InfixToPostfix(const string& infixExp) : infixExpression{ infixExp } {}

void InfixToPostfix::setInfixExp(const string& infixExp) {
	// assign a new infix expression
	infixExpression = infixExp;
	// make postfixExpression the NULL string
	postfixExpression = "";
}

string InfixToPostfix::postfix() {
	/**** TO BE COMPLETED *****/
	ExpressionSymbol op;
	char ch;
	for (int i = 0; i < infixExpression.length(); i++) {
		ch = infixExpression.at(i);

		if (isdigit(ch)) {
			postfixExpression = postfixExpression + ch;
			postfixExpression = postfixExpression + " ";
		}
		else if (isOperator(ch) || ch == '(') {
			op = ExpressionSymbol(ch);
			outputHigherOrEqual(op);
			operatorStack.push(op);
		}
		else if (ch == ')') {
			op = ExpressionSymbol(ch);
			//if ((operatorStack.isEmpty() != true) && (operatorStack.top().getOp() != '(')) {
			outputHigherOrEqual(op);

			//postfixExpression = postfixExpression + operatorStack.top()
			//postfixExpression = postfixExpression + " ";
			//operatorStack.pop();
		//}
			if (operatorStack.isEmpty()) {
				throw ExpressionError("infix2Postfix: Missing '('");
			}
			else {
				operatorStack.pop();
			}
		}
		else if (isspace(ch) == false) {
			throw ExpressionError("infix2Postfix: Invalid input");
		}
			//if ((operatorStack.isEmpty() == false) && (operatorStack.top() == '(')) {
			//	operatorStack.pop();
			//}
	}
		while (operatorStack.isEmpty() == false) {
			op = operatorStack.top();
			operatorStack.pop();
			if (op.getOp() == '(') {
				throw ExpressionError("infix2Postfix: missing ')'");
			}
			else {
				postfixExpression = postfixExpression + op.getOp();
			postfixExpression = postfixExpression + " ";
			//operatorStack.pop();
		}
	}
	return postfixExpression;
		/*if (isdigit(ch)) {
			postfixExpression.push_back(ch);
		}
		else if (isOperator(ch)) {
			op = ch;
			
			outputHigherOrEqual(op);
			operatorStack.push(op);
		}
		else if (ch == '(') {
			op = ch;
			operatorStack.push(op);
			
		}
		else if (ch == ')') {
				op = operatorStack.top();
				operatorStack.pop();
				postfixExpression = postfixExpression + op.getOp();
				postfixExpression = postfixExpression + ' ';
			}
			if (operatorStack.isEmpty()) {
				throw ExpressionError("infix2Postfix: Missing '('");
			}
			
			else {
				operatorStack.pop();
			}
		}
		else {
			throw ExpressionError("NOT COrrect FIX IT MANNN");
		}
	}
		op = operatorStack.top();
		operatorStack.pop();
		if (op.getOp() == '(') {
			throw ExpressionError("Unmatched left parenthesis");
		postfixExpression += op.getOp();
		postfixExpression += ' ';
	}
	*/
} //end postfix()
#endif	// INFIX_TO_POSTFIX
