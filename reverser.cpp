#include "reverser.hpp"
#include "stack.hpp"


Reverser::Reverser() {}
Reverser::~Reverser() {}

char *Reverser::reverse(char* str) 
{
	if (str == NULL || strlen(str) == 0)
	{
		return NULL;
	}
	char tempArr[100];
	strcpy(tempArr, str);

	int i = 0;
	Stack<char> stack;

	while (tempArr[i])
	{
		stack.push(tempArr[i++]);
	}

	char t = '\0';
	i = 0;
	while (stack.pop(t))
	{
		str[i++] = t;
	}

	return str;
}
