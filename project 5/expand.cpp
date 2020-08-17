//
// Created by Alex Ernst on 2019-04-29.
//

#include <iostream>
#include <fstream>
#include <string>

#include "expand.h"

using namespace std;

void write_preorder(node* tree, std::ofstream &fout) {
    if (tree == nullptr) { return; }

    string output;

    if (tree -> left == nullptr) {
        output = "#A ";
    } else {
        output = "#Q ";
    }

    output += tree -> data;
    fout << output << endl;

    write_preorder(tree -> left, fout);
    write_preorder(tree -> right, fout);
}