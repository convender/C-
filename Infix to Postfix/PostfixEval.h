// TO BE COMPLETED:
//		compute()
//		evaluate()

// SOLUTION: PostfixEval.h
#ifndef POSTFIX_EVAL
#define POSTFIX_EVAL

#include <iostream>
#include <string>
#include <ctype.h>
#include "MyStack.h"
#include "CS255Exceptions.h"	// for expressionError exception

using namespace std;

class PostfixEval {
public:
	// default constructor. postfix expression is NULL string
	PostfixEval();

	// return the postfix expression
	string getPostfixExp() const;

	// change the postfix expression
	void setPostfixExp(const string& postfixExp);

	// evaluate the postfix expression and return its value.
	//  the function throws expressionError
	//  if an error (e.g. divison by zero) occurs during evaluation
	int evaluate();

private:
	// the postfix expression to evaluate
	string postfixExpression;

	// stack of operands
	myStack<int> operandStack;

	// pop left and right operands from stack.
	// Precondition: the stack must have at least two entries.
	// if the stack is empty prior to a pop() operation, the
	// function throws the exception expressionError
	void getOperands(int& left, int& right);

	// compute "left op right". if right is 0 and op
	// is '/' , the function throws expressionError
	int compute(int left, int right, char op) const;

	// is ch one of '+','-','*','/' ,'^'
	bool isOperator(char ch) const;
};

void PostfixEval::getOperands(int& left, int& right) {
	// can we pop the right operand?
	if (operandStack.isEmpty())
		throw  ExpressionError("postfixEval: Too many operators");

	// pop right operand
	right = operandStack.top();
	operandStack.pop();

	// can we pop the left operand?
	if (operandStack.isEmpty())
		throw  ExpressionError("PostfixEval: Too many operators");

	// pop left operand
	left = operandStack.top();
	operandStack.pop();
}

int PostfixEval::compute(int left, int right, char op) const {
	/**** TO BE COMPLETED *****/
	int answer = 0;
	switch (op) {
	case '+':
		answer = left + right;
		break;
	case '-': 
		answer = left - right;
		break;
	case '*': 
		answer = left * right;
		break;
	case '/' :
		if (right == 0) {
			throw ExpressionError("postfixEval: divide by 0");
		}
		else {
			answer = left / right;
		}
		break;
	case '^': 
		answer = pow(left, right);
		break;
	default: 
		throw ExpressionError("postfixEval: invalid operator");
		break;
	}
	return answer;
} // end compute()

bool PostfixEval::isOperator(char ch) const {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// default constructor
PostfixEval::PostfixEval() {}

string PostfixEval::getPostfixExp() const {
	return postfixExpression;
}

void PostfixEval::setPostfixExp(const string& postfixExp) {
	postfixExpression = postfixExp;
}

int PostfixEval::evaluate() {
	/**** TO BE COMPLETED *****/
	char ch;
	int left;
	int right;
	int answer;

	for (int i = 0; i < postfixExpression.length(); i++) {
		ch = postfixExpression.at(i);

		if (isdigit(ch)) {
			ch = ch - '0';
			operandStack.push(ch);
		}
		else if (isOperator(ch)) {
			getOperands(left, right);
			answer = compute(left, right, ch);
			operandStack.push(answer);
		}
	}
	if (operandStack.isEmpty() != true) {
		answer = operandStack.top();
		operandStack.pop();
		return answer;
	}
	else {
		throw ExpressionError("Too few operands");
	}
} // end evaluate();
#endif	// POSTFIX_EVAL

