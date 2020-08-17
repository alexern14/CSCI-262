/*
    Queue.cpp
        
    Method implementations for Queue class

    assignment: CSCI 262 Lab - Queues, part 1        

    author: 

    last modified: 9/7/2017
*/

/* 
   NOTE: if you prefer, the Queue class is simple enough that you can do all
   of your methods inline.  In that case, you can remove this file.
*/

#include <Queue.h>

bool Queue::enqueue(char c){
    if (_size == ARRAY_SZ){
        return false;
    }

    _data[_back] = c;
    _back++;
    _back %= ARRAY_SZ;
    _size++;
    return true;
}

bool Queue::dequeue(){
    if (is_empty()){
        return false;
    }

    _front++;
    _front %= ARRAY_SZ;
    _size--;
    return true;
}

char Queue::front(){
    return _data[_front];
}

bool Queue::is_empty(){
    return _size == 0;
}

