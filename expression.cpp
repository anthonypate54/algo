#include "expression.hpp"
#include "stack.hpp"

Expression::Expression() {}
Expression::~Expression() {}

bool Expression::evaluate(const char* arr)
{
	Stack<char> stack;
	char top;

	for (int i = 0; i < strlen(arr); i++)
	{
		char ch = arr[i];
		if (ch == '(' || ch == '<' || ch == '[' || ch == '{')
			stack.push(ch);
		if (ch == ')' || ch == '>' || ch == ']' || ch == '}')
		{
			if (stack.isEmpty())
				return false;
			stack.pop(top);

			if ( (ch == '(' && top != ')') ||
				(ch == '<' && top != '>') ||
				(ch == '[' && top != ']') ||
				(ch == '{' && top != '}')
				)
			{
				return false;
			}
		}
	}

	return stack.isEmpty();
}
