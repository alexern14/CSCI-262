/*
    main() function for CSCI 262 Data Structures - Inheritance.
*/
#include <iostream>
#include "int_counter.h"
#include "mod_counter.h"

using namespace std;

int main() {
   int_counter ic;
   mod_counter mc(7);
   int_counter* counters[2];
   counters[0] = &ic;
   counters[1] = &mc;

   string response;
   while (true) {
       for (int i = 0; i < 2; i++) {
           cout << counters[i]->to_string() << "  ";
           counters[i]->increment();
       }
	   cout << "Enter to continue, q to quit ";
	   getline(cin, response);
	   if (response == "q") break;
   }
}
