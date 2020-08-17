#ifndef _QUEUE_H
#define _QUEUE_H

/*
    Queue.h
        
    A working implementation of a fixed-size circular queue
    meeting the requirements of the Queue, part 1 lab.  Use
    or replace as you wish.
*/

#include <cstdlib>
#include <limits>

using namespace std;

template<class T>

class Queue {


public:


	Queue(size_t capacity) {
		_data = new T[capacity];
	}

	void enqueue(T c) {

		if (_size == _capacity) {

			// Not enough size

			size_t newCapacity = _capacity == 0 ? 1 : _capacity * 2;
			T* newData = new T[newCapacity];
			for(size_t i = _front; i < _capacity; ++i) {
				newData[i - _front] = _data[i];
			}

			if (_back > 0) {

				for(size_t i = _back - 1; i != numeric_limits<size_t>::max(); --i) {
					T a = _data[i];
					newData[_size - _front + i] = a;
				}
			}

			delete [] _data;
			_data = newData;
			_capacity = newCapacity;
			_front = 0;
			_back = _size;
		}

		_data[_back] = c;
		_back += 1;
		_back %= _capacity;
		_size += 1;
	}

	bool dequeue() {
		if (is_empty()) {
			return false;
		}
		_front += 1;
		_front %= _capacity;
		_size -= 1;
		return true;
	}

	T front()    {
		return _data[_front];
	}

	bool is_empty() {

		return _size == 0;

	}

	Queue(const Queue& queue) {
		_capacity = queue._capacity;
		_size = queue._size;
		_front = queue._front;
		_back = queue._back;
		_data = new T[_capacity];
		for(size_t i = _front; i < _size + _front; ++i) {
			_data[i] = queue._data[i];
		}
	}

	~Queue() {

		delete[] _data;

	}

	Queue operator=(const Queue& queue) {
		if (this == &queue) return *this;
		delete[] _data;
		_capacity = queue._capacity;
		_size = queue._size;
		_front = queue._front;
		_back = queue._back;
		_data = new T[_capacity];
		for(int i = 0; i < _size; ++i) {
			_data[i] = queue._data[i];
		}
		return *this;
	}

private:

	T* _data;
	size_t _capacity = 0;
	size_t _front = 0;
	size_t _back = 0;
	size_t _size = 0;

};

#endif
