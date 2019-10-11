//
//  linkedlist.hpp
//  algo
//
//  Created by Anthony on 9/2/19.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <stdio.h>

struct node
{
    int data;
    node *next, *prev;
};

class LinkedList
{
private:
    node *first, *last;
    int size;
    
public:
    LinkedList();
    ~LinkedList();
    
    void insertItem(int item);
    void addFirst(int item);
    void addLast(int item);
    void removeFirst();
    void removeLast();
    bool contains(int item);
    int indexOf(int item);
    int getSize() { return size; }
    int * toArray();
    void reverse();
    int nthFromEnd(int n);
    int getMiddle();
    
    int removeItem(int item);
    int searchItem(int item);
    void displayItems();
};
#endif /* linkedlist_hpp */
