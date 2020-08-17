/*
 CSCI 262 Data Structures, spring 2019, Project 4 - Markov
 *
 Created by Alex Ernst on 2019-04-08.
*/

#include <cstdlib>
#include <vector>
#include <map>

#include "model.h"
#include "word_model.h"

using namespace std;

string word_model::generate(int size) {
    int start = rand() % (_data.size() - _order);
    vector<string> seed;
    string answer;

    for (int i = 0;i < _order ; i++){
        seed.push_back(_data[start + i]);
    }

    for (int i = 0; i < size; i++){
        vector<string> words = _word_model[seed];

        int pos = rand() % words.size();

        string next_word = words[pos];

        answer += next_word + " ";

        seed.push_back(next_word);
        seed.erase(seed.begin());
    }

    return answer;
}
