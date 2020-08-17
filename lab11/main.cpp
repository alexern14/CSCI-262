/*
    tests.cpp

    Tests for the Queue class. 

    Code for CSCI 262 lab - Queue, part 1

    Author: C. Painter-Wakefield
*/

#include <iostream>
#include <string>
#include <assert.h>     /* assert */
#include "Queue.h"

void test0();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();

using namespace std;

int main() {

    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    cout << endl;

    cout << "All tests passed." << endl;
}




void test0() {

    Queue<char> q(0);

    for (int i =0; i <5; i++) {
        q.enqueue(i);
    }

    assert(q.front() == 0);
    q.dequeue();
    assert(q.front() == 1);
    q.dequeue();
    assert(q.front() == 2);
    q.dequeue();
    assert(q.front() == 3);
    q.dequeue();
    assert(q.front() == 4);
    cout <<  "Test 0 passed." << endl;
}

void test1() {

    Queue<char> q(4);
    q.enqueue(0);
    q.enqueue(1);

    assert(q.front() == 0);
    q.dequeue();
    assert(q.front() == 1);
    cout <<  "Test 1 passed." << endl;

}

void test2() {

    Queue<char> q(3);
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);

    assert(q.front() == 0);
    q.dequeue();
    assert(q.front() == 1);
    q.dequeue();
    assert(q.front() == 2);
    cout <<  "Test 2 passed." << endl;

}

void test3() {

    // Test if adding nothing will do something
    Queue<char> q(4);
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    q.dequeue();
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    assert(q.front() == 2);
    q.dequeue();
    assert(q.front() == 3);
    q.dequeue();
    assert(q.front() == 4);
    q.dequeue();
    assert(q.front() == 5);
    q.dequeue();
    assert(q.front() == 6);
    q.dequeue();
    cout <<  "Test 3 passed." << endl;

}

void test4() {

    Queue<char> a(4);
    a.enqueue(0);
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);

    Queue<char> b = a;

    assert(b.front() == 0);
    b.dequeue();
    assert(b.front() == 1);
    b.dequeue();
    assert(b.front() == 2);
    b.dequeue();
    assert(b.front() == 3);
    b.dequeue();

    assert(a.front() == 0);
    a.dequeue();
    assert(a.front() == 1);
    a.dequeue();
    assert(a.front() == 2);
    a.dequeue();
    assert(a.front() == 3);
    a.dequeue();
    cout <<  "Test 4 passed." << endl;

}

void test5() {

    Queue<char> a(4);
    Queue<char> b(0);
    a.enqueue(0);
    a.enqueue(1);
    a.enqueue(2);

    b = a;

    assert(a.front() == 0);
    a.dequeue();
    assert(a.front() == 1);
    a.dequeue();
    assert(a.front() == 2);
    a.dequeue();

    assert(b.front() == 0);
    b.dequeue();
    assert(b.front() == 1);
    b.dequeue();
    assert(b.front() == 2);
    b.dequeue();
    cout <<  "Test 5 passed." << endl;

}

void test6() {

    Queue<bool> q(2);
    q.enqueue(false);
    q.enqueue(false);
    q.enqueue(false);
    q.enqueue(true);
    q.enqueue(false);
    q.enqueue(true);

    assert(!q.front());
    q.dequeue();
    assert(!q.front());
    q.dequeue();
    assert(!q.front());
    q.dequeue();
    assert(q.front());
    q.dequeue();
    assert(!q.front());
    q.dequeue();
    assert(q.front());
    q.dequeue();
    cout <<  "Test 6 passed." << endl;

}

void test7() {

    Queue<std::string> a(0);
    a.enqueue("Hello");
    a.enqueue("World!");
    a.enqueue("One");
    a.dequeue();
    a.enqueue("Two");
    a.enqueue("Three");
    a.enqueue("Four");
    a.dequeue();

    Queue<std::string> q = a;

    assert(q.front() == "One");
    q.dequeue();
    assert(q.front() == "Two");
    q.dequeue();
    assert(q.front() == "Three");
    q.dequeue();
    assert(q.front() == "Four");
    q.dequeue();
    cout <<  "Test 7 passed." << endl;


}


