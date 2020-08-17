/*
 CSCI 262 Data Structures, spring 2019, Project 4 - Markov
 *
 Created by Alex Ernst on 2019-04-08.
*/

#include <cstdlib>
#include <vector>
#include <map>

#include "model.h"
#include "map_model.h"

using namespace std;

string map_model::generate(int size) {

    int start = rand() % (_data.length() - _order);
    string seed = _data.substr(start, _order);
    string answer;
    vector<char> chars;

    for (int i = 0; i < size; i++) {
        chars.clear();
        chars = _map_model[seed];

        char next_char = chars.at(rand()% (chars.size()));
        answer.push_back(next_char);

        seed = seed.substr(1) + next_char;
    }

    return answer;
};