// COMPLETE -- MAKE NO CHANGES

// SOLUTION: ExpressionSymbol.h
#ifndef EXPRESSION_SYMBOL
#define EXPRESSION_SYMBOL

// a class that maintains the precedence of symbols
class ExpressionSymbol {
public:
	ExpressionSymbol(); // default constructor
	ExpressionSymbol(char ch); // initializes object with operator ch

	// Return true if stackPrecedence of left is >= inputPrecedence of right.
	//  Determines whether operator left on the stack should be output before
	//  pushing operator right on the stack
	friend bool operator>= (const ExpressionSymbol& left,
		const ExpressionSymbol& right);

	char getOp() const; //return operator

private:
	char op; // operator
	int inputPrecedence; // input precedence of op
	int stackPrecedence; // stack precedence of op
};

// default constructor
ExpressionSymbol::ExpressionSymbol() {}

// constructor that assigns operator and precedence values
ExpressionSymbol::ExpressionSymbol(char ch) {
	op = ch;    // assign operator

	switch (op) {

		// '+' and '-' have input/stack precedence 1
	case '+':
	case '-':  inputPrecedence = 1;
		stackPrecedence = 1;
		break;

		// '*' and '/' have input/stack precedence 2
	case '*':
	case '/':  inputPrecedence = 2;
		stackPrecedence = 2;
		break;

		// '^' is right associative. input precedence 4
		// and stack precedence 3
	case '^':  inputPrecedence = 4;
		stackPrecedence = 3;
		break;

		// '(' has input precendence 5, stack precedence -1
	case '(':  inputPrecedence = 5;
		stackPrecedence = -1;
		break;

		// ')' has input/stack precedence 0
	case ')':  inputPrecedence = 0;
		stackPrecedence = 0;
		break;
	}
}

char ExpressionSymbol::getOp() const {
	return op;
}

bool operator>= (const ExpressionSymbol& left, const ExpressionSymbol& right) {
	return left.stackPrecedence >= right.inputPrecedence;
}
#endif // EXPRESSION_SYMBOL

