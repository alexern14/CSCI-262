/*
    clock_time.cpp

    Created by Alex Ernst on 2019-03-25.
*/

#include <iostream>
#include <string>
#include <ctime>
#include "clock_time.h"

using namespace std;

int clock_time::get_hour() {
    return seconds/3600 ;
}

int clock_time::get_minute() {
    return (seconds%3600)/60;
}

int clock_time::get_second() {
    return seconds%60;
}

void clock_time::set_time(int h, int m, int s) {
    if (h < 0) h = 22-h;
    if (h > 24) h = h % 24;

    seconds = h*3600+m*60+s;
}

clock_time::clock_time() {
    seconds = 0;
}

clock_time::clock_time(int h, int m, int s) {
    set_time(h, m, s);
}

bool operator==(clock_time a, clock_time b) {
    return a.seconds == b.seconds;
}

bool operator!=(clock_time a, clock_time b) {
    return a.seconds != b.seconds;
}

clock_time operator+(clock_time a, clock_time b) {
    clock_time c;
    c.seconds = a.seconds + b.seconds;
    if (c.seconds > 24*3600-1) c.seconds = c.seconds - 24*3600;

    return c;
}

string to_string(clock_time c) {
    string s;
    s+=to_string(c.get_hour());
    if (to_string(c.get_minute()).size() == 1) s+=":0";
    if (to_string(c.get_minute()).size() == 2) s+=":";
    s+=to_string(c.get_minute());
    if (to_string(c.get_second()).size() == 1) s+=":0";
    if (to_string(c.get_second()).size() == 2) s+=":";
    s+=to_string(c.get_second());

    return s;
}

ostream &operator <<(ostream & out, clock_time c) {
    out << to_string(c);
    return out;

}

////////////////// Extra Credit /////////////////////////

string to_string2(clock_time c, bool h24) {
    if (h24) {
        string s;
        s+=to_string(c.get_hour());
        if (to_string(c.get_minute()).size() == 1) s+=":0";
        if (to_string(c.get_minute()).size() == 2) s+=":";
        s+=to_string(c.get_minute());
        if (to_string(c.get_second()).size() == 1) s+=":0";
        if (to_string(c.get_second()).size() == 2) s+=":";
        s+=to_string(c.get_second());

        return s;
    } else {
        if (c.get_hour() > 12) {
            string s;
            s += to_string(c.get_hour() - 12);
            if (to_string(c.get_minute()).size() == 1) s += ":0";
            if (to_string(c.get_minute()).size() == 2) s += ":";
            s += to_string(c.get_minute());
            if (to_string(c.get_second()).size() == 1) s += ":0";
            if (to_string(c.get_second()).size() == 2) s += ":";
            s += to_string(c.get_second());
            s += " PM.";
            return s;
        } else if (c.get_hour() == 12) {
            string s;
            s += to_string(c.get_hour());
            if (to_string(c.get_minute()).size() == 1) s += ":0";
            if (to_string(c.get_minute()).size() == 2) s += ":";
            s += to_string(c.get_minute());
            if (to_string(c.get_second()).size() == 1) s += ":0";
            if (to_string(c.get_second()).size() == 2) s += ":";
            s += to_string(c.get_second());
            s += " PM.";
            return s;
        } else {
            string s;
            if(c.get_hour()==0) {
                s += to_string(12);
            } else {
                s += to_string(c.get_hour());
            }
            if (to_string(c.get_minute()).size() == 1) s += ":0";
            if (to_string(c.get_minute()).size() == 2) s += ":";
            s += to_string(c.get_minute());
            if (to_string(c.get_second()).size() == 1) s += ":0";
            if (to_string(c.get_second()).size() == 2) s += ":";
            s += to_string(c.get_second());
            s += " AM.";
            return s;
        }
    }
}

void clock_time::set_now() {
    struct tm *current_time;
    time_t tim;
    time(&tim);
    current_time = localtime(&tim);
    int hrs = current_time->tm_hour;
    int mins = current_time->tm_min;
    int secs = current_time->tm_sec;
    set_time(hrs, mins, secs);
}