//
//  linkedlist.cpp
//  algo
//
//  Created by Anthony on 9/2/19.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include "linkedlist.hpp"

LinkedList::LinkedList()
{
    first = last = NULL;
    size=0;
}

LinkedList::~LinkedList()
{
    node *p = first;
    while(p)
    {
        p=p->next;
        delete first;
        first = p;
    }
}
void LinkedList::addFirst(int item)
{ // O(1)
    node *p = new node;
    p->data = item;
    p->next = NULL;
    p->prev = NULL;
    if(first == NULL)
    {
        first = p;
        last = p;
    }
    else
    {
        p->next = first;
        first->prev = p;
        first = p;
    }
    size++;
}
void LinkedList::addLast(int item)
{
    node *p = new node;
    p->data = item;
    p->next = NULL;
    p->prev = NULL;
    if(first == NULL)
    {
        last = p;
        first = p;
    }
    else
    {
        last->next = p;
        p->prev = last;
        last = p;
    }
    size++;
}
void LinkedList::removeFirst()
{
    node *p = NULL;
    if(first == NULL)
    {
        return;
    }
    
    if(first == last)
    {
        delete first;
        first = last = NULL;
    }
    else
    {
        p = first;
        first = first->next;
        first->prev = NULL;
        delete p;
    }
    size--;
}
void LinkedList::removeLast()
{
    node *p = first;    
    if(first == NULL)
    {
        return;
    }
    if(first == last)
    {
        delete first;
        first = last = NULL;
        size = 0;
        return;
    }
    else
    {
        p=last->prev;
        p->next = NULL;
        delete last;
        last = p;
        size--;
    }
}

void LinkedList::reverse()
{
    node *p=first;
    node *temp=NULL;
     
    if(p->next == NULL || p == NULL)
        return;
    
    while(p)
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p=p->prev;
    }
    temp = temp->prev;
    if(temp != NULL)
        first = temp;
 }

int LinkedList::nthFromEnd(int n)
{
    node *p = first;
    node *p1 = first;
    
    int count = 0;
    if(n > getSize())
        return -1;
    while(count < n)
    {
        p=p->next;
        count++;
    }
    
    while(p)
    {
        p1 = p1->next;
        p = p->next;
    }
    return p1->data;
}

int LinkedList::getMiddle()
{
    node *p = first;
    node *p1 = first;
    
    while(p1 != last && p1->next != last)
    {
        p1 = p1->next->next;
        p = p->next;
    }
    
     if(p1 == last)
    {
        printf("%d", p->data);
    }
    else
    {
        printf("%d %d\n", p->data, p->next->data);
    }
    return 0;
}

bool LinkedList::contains(int item)
{
    return indexOf(item) != -1;
}

int LinkedList::indexOf(int item)
{
    int index = 0;
    node *p = first;
    while(p)
    {
        if(p->data == item)
        {
            return index;
        }
        index++;
        p = p->next;
    }
    return -1;
}
void LinkedList::insertItem(int item)
{
    node *p = new node;
    p->data = item;
    p->next = NULL;
    if(first == NULL)
    {
        first = p;
        last = p;
    }
    else
    {
        last->next = p;
        last = p;
    }
    size++;
}

void LinkedList::displayItems()
{
    node *p = first;
    while(p)
    {
        printf("%d\n", p->data);
        p=p->next;
    }
}

int LinkedList::removeItem(int item)
{
    node *p = first;
    node *prev = NULL;
    bool found = false;
    while(p)
    {
        if(p->data == item)
        {
            found = true;
            break;
        }
        prev = p;
        p=p->next;
    }
    
    if(!found)
    {
        return -1;
    }
    
    if(p==first)
    { // first node
        p=p->next;
        delete first;
        first=p;
    }
    else if(p == last)
    { // last node
        prev->next=NULL;
        delete last;
        last=prev;
    }
    else
    {
        prev->next = p->next;
        delete p;
    }
    size--;
    return 1;
}
int LinkedList::searchItem(int item)
{
    node *p = first;
    while(p)
    {
        if(p->data == item)
        {
            return item;
        }
        p=p->next;
    }
    return 0;
}

int *LinkedList::toArray()
{
    int *array = new int[size]();
    
    int index = 0;
    node *p = first;
    while(p)
    {
        array[index++] = p->data;
        p=p->next;
    }
    return array;
}
