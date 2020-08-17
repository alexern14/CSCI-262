#ifndef _Queue_h
#define _Queue_h

/*
    Queue.h
        
    class definition for the Queue class.

    assignment: CSCI 262 Lab - Queues, part 1       

    author: 

    last modified: 9/7/2017
*/

#include <cstdlib>

class Queue {
public:
	// max elements in queue
	static const size_t ARRAY_SZ = 5;

	Queue() { ; }

//	bool enqueue(char c) { return true; }
//	bool dequeue()  { return true;	}
//	char front()    { return 0; }
//	bool is_empty() { return true; }

    bool enqueue(char c);
	bool dequeue();
	char front();
	bool is_empty();


	int _front = 0;
	int _back = 0;

	int _size = 0;


private:
	char _data[ARRAY_SZ];
};

#endif
