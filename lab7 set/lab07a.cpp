/*
    lab07a.cpp

    Author: C. Painter-Wakefield

    Created: 10/10/2018

    Starter code for lab 7, provides initial code to load in a dictionary
    of words, and run time tests on how long it takes to search for them.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>      // for clock()
#include <algorithm>  // for find()
#include <vector>
#include <set>
#include <iterator>

using namespace std;


/*************/
/* CONSTANTS */
/*************/
static const int TEST_SIZE = 10000;	// how many trials will we time?


/********/
/* MAIN */
/********/
int main() {
    // open dictionary and read in all the words
	cout << "Reading dictionary...";
    ifstream fin("dictionary.txt");
    if (!fin) {
        cerr << "Could not open 'dictionary.txt' for reading, exiting." << endl;
        return -1;
    }
    
    vector<string> words_vec;
    set<string> words_set;
    string word;
    while (!fin.eof()) {
        getline(fin, word);
        words_vec.push_back(word);
        words_set.insert(word);
    }
    fin.close();
	cout << "done." << endl;


    // create a vector of strings to search for - we'll pick words spaced
    // evenly throughout the collection.
	cout << "Creating test words collection...";

	//set
	set<string> test_set_words;
	auto iter = words_set.begin();
    for (int i = 0; i < TEST_SIZE; i++) {
        int index = int(words_set.size() / double(TEST_SIZE) * i);
        advance(iter, i);
        test_set_words.insert(*iter);
    }

    //vector
//	vector<string> test_words;
//    for (int i = 0; i < TEST_SIZE; i++) {
//        int index = int(words_vec.size() / double(TEST_SIZE) * i);
//        test_words.push_back(words_vec[index]);
//    }

	cout << "done." << endl;


    // time finding all the test words from test_vec
    clock_t start, stop;  // stores the start/stop clock values
    int count;            // how many words did we find?

	cout << "Timing Vector...";
    start = clock();
    /************** CODE TO BE TIMED ***************/
    count = 0;

    //set
    for (int j = 0; j < test_set_words.size(); j++) {
        if (words_set.count(test_set_words.at(j))){
            count++;
        }
    }

    //vector
//    for (string s: test_set_words) {
//        if (find(words_vec.begin(), words_vec.end(), s) != words_vec.end()) count++;
//    }
    /***********************************************/
    stop = clock();
	cout << "done." << endl << endl;

    // This next line takes the elapsed "clock time" and converts to seconds    
    double seconds = (stop - start) / double(CLOCKS_PER_SEC);

    cout << "Found " << count << " of " << TEST_SIZE << " words in ";
    cout << seconds << " seconds." << endl;


    return 0;
}
