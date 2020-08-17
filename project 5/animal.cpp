/*
	animal.cpp

	author: Alexandra Ernst
	date:  4/29/2019

	Animal/20 questions program for CSCI 262. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "node.h"
#include "read.h"
#include "play_game.h"
#include "expand.h"

using namespace std;

void save_game_tree(node* tree);
void delete_game_tree(node* tree);

int main() {

	node* root = read_game_tree();
	if (root == NULL) return -1;

	while (true) {
		string tmp;
		int choice;
		
		cout << "Welcome to 20 questions!" << endl;
		cout << "  1) Play the game" << endl;
		cout << "  2) Save the game file" << endl;
		cout << "  3) Quit" << endl;
		cout << "Please make your selection: ";

		getline(cin, tmp);
		choice = atoi(tmp.c_str());

		switch (choice) {
		case 1:
			play_game(root);
			break;
		case 2:
			save_game_tree(root);
			break;
		case 3:
			break;
		default:
			cout << "Sorry, I don't understand." << endl << endl;
		}
		if (choice == 3) break;
	}
	
	delete_game_tree(root);
	return 0;
}

void save_game_tree(node* tree) {

    ofstream fout("animal.txt");

    if (!fout) {
        cerr << "Cannot write to file" << endl;
        return;
    }

    write_preorder(tree, fout);
}

void delete_game_tree(node* tree) {

    delete tree;

}
