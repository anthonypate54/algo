//
//  arrays.hpp
//  algo
//
//  Created by Anthony on 8/31/19.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef arrays_hpp
#define arrays_hpp

#include <stdio.h>

class Array
{
    int *items;
    int *tempItems;
    int count;
    int length;

public:
 
    Array(int size);
    ~Array();
    void insertItem(int item);
    int remove(int index);
    int indexOf(int item);
    void print();
};
#endif /* arrays_hpp */
