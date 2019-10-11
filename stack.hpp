#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
	Stack();
	~Stack();

	void push(T);
	bool pop(T&);
	bool print(void);
	bool isEmpty(void);

private:
	struct node {
		node() { next = NULL; }
		T data;
		node* next;
	}*top;

};
//--------------------------------------------------------
template <typename T>
Stack<T>::Stack() {
	top = NULL;
}

template<typename T>
Stack<T>::~Stack()
{
	node* p = top;
	while(p)
	{
		p = p->next;
		delete top;
		top = p;		
	}
}

//--------------------------------------------------------
template <typename T>
void Stack<T>::push(T x) 
{
	//(insert at head (top))
	node *p = new node;
	p->data = x;
	p->next = top;
	top = p;
}
//--------------------------------------------------------
template <typename T>
bool Stack<T>::pop(T& x)
{
	node* p = top;
	if (isEmpty())
	{
		return false;
	}
	x = p->data;
	p = p->next;
	delete top;
	top = p;
	return true;
}

template <typename T>
bool Stack<T>::print(void)
{
	node *p = top;

	while(p)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
	return true;
}
//--------------------------------------------------------
template <typename T>
bool Stack<T>::isEmpty(void) {
	return top == NULL;
}