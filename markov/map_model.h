/*
 CSCI 262 Data Structures, spring 2019, Project 4 - Markov
 *
 Created by Alex Ernst on 2019-04-08.
*/

#ifndef MARKOV_SMARTER_BETTER_FASTER_METHOD_H
#define MARKOV_SMARTER_BETTER_FASTER_METHOD_H

#include "model.h"

#include <map>
#include <vector>
#include <string>

using namespace std;

class map_model : public markov_model {
public:

    // give the model the example text and the model order; the model
    // should do any preprocessing in this call
    virtual void initialize(string text, int order) {

        // copy first order characters to back to simulate wrap-around
        _data = text + text.substr(0, order);
        _order = order;

        string seed;

        for (int i = 0; i < text.size(); i++) {
            seed = _data.substr(i, order);
            char next_char = _data[i + _order];
            _map_model[seed].push_back(next_char);
        }
    }

    virtual string generate(int size);

protected:
    string _data;
    int _order;

};

#endif