//
// Created by Alex Ernst on 2019-04-29.
//

#include <iostream>
#include <fstream>
#include <string>

#include "read.h"

using namespace std;

node* read_game_tree() {

    ifstream fin("animal.txt");
    if (!fin) {
        cerr << "Error opening file" << endl;
        return nullptr;
    }

    node* root = new node;
    root -> data = "";

    read_preorder(root, fin);
    fin.close();

    return root;

}

void read_preorder(node* tree, ifstream &fin) {
    string node_type;
    fin >> node_type;

    string input;
    string tmp;
    getline(fin, input);

    size_t found = input.find_first_not_of(" ");
    if (found == string::npos) input = "";

    size_t str_end = input.find_last_not_of(" ");
    size_t str_range = str_end - found + 1;

    tmp = input.substr(found, str_range);
    tree -> data = tmp;

    if (node_type == "#A") {
    } else if (node_type == "#Q") {
        tree -> left = new node;
        tree -> right = new node;
        read_preorder(tree -> left, fin);
        read_preorder(tree -> right, fin);
    } else {
        cerr << "Error reading file" << endl;
        exit (-1);
    }
}