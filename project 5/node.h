//
// Created by Alex Ernst on 2019-04-29.
//

#ifndef PROJECT_5_NODE_H
#define PROJECT_5_NODE_H

#include <string>

using namespace std;

class node {
public:
    string data;
    node* left;
    node* right;
    node(){
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

#endif //PROJECT_5_NODE_H
