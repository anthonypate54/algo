//
//  arrays.cpp
//  algo
//
//  Created by Anthony on 8/31/19.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include "arrays.hpp"

Array::Array(int size)
{
    count=0;
    items = new int[size]();

    length = size;
}
Array::~Array()
{
    delete[] items;
}

void Array::insertItem(int item)
{   //  if the array is full, resize it
    //  Add new item at end
    if(count == length)
    { // need a bigger array
        tempItems = new int[count+1];
        for(int i=0; i<count+1; i++)
        {
            tempItems[i] = items[i];
        }
        delete[] items;
        tempItems[count++] = item;
        items = tempItems;
        length++;
    }
    else
    {
        items[count++] = item;
    }
}
    
int Array::remove(int index)
{   // need to find the item
    // delete it and move the remaining items back one
    // dont forget item not found
    
    if(index < 0 || index >=count)
    {
        return 0;
    }
    
     for(int i=index; i<count;i++)
    {
        items[i] = items[i+1];
     }

    count--;
    return 1;
}

int Array::indexOf(int item)
{
    for(int i=0; i<count; i++)
    {
        if(items[i] == item)
            return i;
    }
    return -1;
}
    
void Array::print()
{
    for(int i=0; i<count; i++)
    {
        printf("%d\n", items[i]);
    }
}

