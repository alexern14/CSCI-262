#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "personality_test.h"

using namespace std;

void load_file(personality_test&);

/* main
 * Calls necessary functions in this file as well as functions in personality_test
 * @param None
 * @return None, Text to Console
 */
int main () {
    cout << "====================================" << endl;
    cout << "Welcome to CSCI262 Personality Test!" << endl;
    cout << "====================================" << endl << endl;

    personality_test test;

    load_file(test);
    //test.printout();
    test.run_test();


}

/* Load File Method
 * @param personality_test object (by reference)
 * @return None, Text to Console
 */
void load_file(personality_test& test) {
    string fileName;
    cout << "Please enter the input file name, e.g., \"questions.txt\": ";
    cin >> fileName;
    ifstream fin;
    fin.open(fileName);
    while (fin.fail()) {
        cout << "Error opening " << fileName;
        cin >> fileName;
        fin.clear();
        fin.open(fileName.c_str());
    }
    if (fin.is_open()) {
        //cout << "file opened properly";

        test.load(fin);

//        cout << "The file contained: ";
//
//        while (fin.good()) {
//
//            cout << (char) fin.get();
//        }
    }
}
