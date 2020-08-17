//
// Created by Alex Ernst on 2019-04-29.
//

#include <queue>
#include <string>
#include <iostream>

#include "play_game.h"
#include "node.h"

using namespace std;

void play_game(node* root) {
    node* current_node = root;
    queue<pair<string, bool>> question_history;
    bool left_child = true;
    node* parent_node = root;

    while (true) {
        cout << current_node->data << " (y/n): ";
        char input;
        do {
            cin >> input;
            input = tolower(input);
        } while (input != 'y' && input != 'n');

        if (current_node -> left == nullptr) {

            if (input == 'y' || input == 'Y') {

                cout << "YAY! I guessed your animal!" << endl << endl;

            } else if (input == 'n') {

                cout << "BOO! I don't know!" << endl << endl;
                cout << "Would you like to expand the game tree (y/n)? ";
                cin >> input;
                if (input == 'n' || input == 'N') { break; }

                cout << "I asked the following:" << endl;
                while (question_history.empty() == false) {
                    cout << question_history.front().first << " ";
                    cout << (question_history.front().second ? "YES" : "NO") << endl;
                    question_history.pop();
                }
                cout << "Enter a new animal in the form of a question, " << endl;
                cout << "e.g., 'Is it a whale?':" << endl;
                cin.ignore();
                string new_animal;
                getline(cin, new_animal);
                cout << "Now enter a question for which the answer is 'yes' for your new answer, and does not contradict your previous answers:" << endl;
                string new_question;
                getline(cin, new_question);

                node* new_question_node = new node;
                new_question_node -> data = new_question;
                new_question_node -> left = new node;
                new_question_node -> left -> data = new_animal;
                new_question_node -> right = current_node;

                if (left_child) {
                    parent_node -> left = new_question_node;
                } else {
                    parent_node -> right = new_question_node;
                }
            }
            break;
        } else {

            pair<string, bool> ans;
            ans.first = current_node -> data;
            ans.second = input == 'y';

            question_history.push(ans);
            parent_node = current_node;

            if (input == 'y') {

                current_node = current_node -> left;
                left_child = true;

            } else if (input == 'n') {

                current_node = current_node -> right;
                left_child = false;
            }
        }
    }
}