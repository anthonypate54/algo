/* hello.cpp */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "arrays.hpp"
#include "linkedlist.hpp"
#include "reverser.hpp"
#include "expression.hpp"

int main()
{
	Expression* e = new Expression();

	const char* estr = "{([<1> + 2])}";

	if (e->evaluate(estr))
		printf("balanced\n");
	else printf("unbalanced\n");

	Reverser *r = new Reverser();
	
	char str[100];
	strcpy(str, "testing");

	printf("testing\n");
	printf("%s\n",r->reverse(str));

    LinkedList *abp = new LinkedList;
    abp->addFirst(10);
    abp->addFirst(20);
    abp->addFirst(5);
    abp->addFirst(6);
    abp->addLast(30);
    abp->addLast(40);
    abp->addLast(50);
    abp->addFirst(7);
    
    abp->removeFirst();
    abp->removeLast();
    printf("Index is %d\n", abp->indexOf(6));
    printf("Size is %d\n", abp->getSize());
    
    int *arr = abp->toArray();
    
    printf("[ ");
    for(int i=0; i<abp->getSize(); i++)
    {
        printf("%d, ", arr[i] );
    }
    printf(" ]\n");
    
    delete arr;
	int n = 4;
    printf("Value of %d from the end is %d\n", n,abp->nthFromEnd(n));
/*
    if(abp->removeItem(90) < 0)
        printf("NOT FOUND\n");
    if(abp->removeItem(70) < 0)
        printf("NOT FOUND\n");
    if(abp->removeItem(10) < 0)
        printf("NOT FOUND\n");
*/
    abp->reverse();
    abp->displayItems();
    
    delete abp;
}
