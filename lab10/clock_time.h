/*
    clock_time.h

    Created by Alex Ernst on 2019-03-25.
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#ifndef LAB10_CLOCK_TIME_H
#define LAB10_CLOCK_TIME_H

class clock_time
{
public:
    int get_hour();
    int get_minute();
    int get_second();
    void set_time(int h, int m, int s);
    clock_time();
    clock_time(int h, int m, int s);
    void set_now();

    friend bool operator==(clock_time a, clock_time b);
    friend bool operator!=(clock_time a, clock_time b);
    friend clock_time operator+(clock_time a, clock_time b);

private:
    int seconds;
};

string to_string(clock_time c);
ostream &operator << (ostream & out, clock_time c);

string to_string2(clock_time c, bool h24);

#endif //LAB10_CLOCK_TIME_H