/*
 CSCI 262 Data Structures, spring 2019, Project 4 - Markov
 *
 Created by Alex Ernst on 2019-04-08.
*/

#ifndef MARKOV_WORD_MODEL_H
#define MARKOV_WORD_MODEL_H

#include "model.h"

#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class word_model : public markov_model {
public:
    virtual void initialize(string text, int order) {

        _order = order;

        istringstream ss (text);
        vector<string> words;

        while(!ss.eof()){
            string str1;
            ss >> str1;
            words.push_back(str1);
        }

        _data = words;

        for (int i = 0; i < order; i++){
            _data.push_back(words.at(i));
        }

        for (int i = 0; i < words.size(); i++){
            vector<string> seed;
            int position = i;
            for (int j = 0; j < _order ; j++) {
                seed.push_back(_data[position]);
                position++;
            }
            _word_model[seed].push_back(words[position]);
        }
    }
    virtual string generate(int size);


protected:
    vector<string> _data;
    int _order;
};

#endif //MARKOV_WORD_MODEL_H
