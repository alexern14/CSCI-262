#ifndef _PERSONALITY_TEST_H
#define _PERSONALITY_TEST_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class question{
public:
    int category_id;
    string line;
    char yes_answer;
    char no_answer;

    string p_type, category, type, description;

};

// personality test class
class personality_test {
    public:
        bool load(istream&);
        void printout();
        void run_test();
        string analyze_personality();
        void categorize_output(string);
        void save_output(string);
        vector <question> questions;
        vector <question> output;

    private:
        // Add anything you may need
};

#endif
