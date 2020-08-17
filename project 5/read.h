//
// Created by Alex Ernst on 2019-04-29.
//

#ifndef PROJECT_5_READ_H
#define PROJECT_5_READ_H

#include "node.h"
#include <fstream>
#include <string>

node* read_game_tree();
void read_preorder(node* tree, std::ifstream &fin);

#endif //PROJECT_5_READ_H
