//
// Created by Alex Ernst on 2019-04-29.
//

#ifndef LAB12B_BOUNDED_COUNTER_H
#define LAB12B_BOUNDED_COUNTER_H

#pragma once

#include "int_counter.h"

class bounded_counter:public int_counter{
public:
    bounded_counter(unsigned int b) {_bound = b;}
    virtual void increment() {
        if (_value < _bound) _value++;
    }

private:
    unsigned int _bound;
};

#endif //LAB12B_BOUNDED_COUNTER_H
