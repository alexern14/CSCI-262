/*
    main.cpp
        
    Implements the user interface for hangman.
    
    assignment: CSCI 262 Project - Evil Hangman        

    author: Alexandra Ernst

    last modified: 3/15/2019
*/

#include <iostream>
#include <fstream>
#include "hangman.h"

using namespace std;

// helper function prototypes
bool get_yesno(string msg);  // return true == yes / false == no
char get_letter(string msg); // return a valid lowercase letter
string trim(string s);          // remove leading/trailing whitespace
bool mapCompare(const pair<string, hangman::WordFamily >& lhs,
                const pair<string, hangman::WordFamily >& rhs);

int main() {
    cout << "Welcome to Hangman!" << endl;
    cout << "===================" << endl << endl;

    // get the hangman object
    hangman game;

    // open dictionary file
    ifstream infile;
    infile.open("dictionary.txt");

    if(!infile.is_open()){
        cout << "Unable to open file" << endl;
        exit(0);
    }

    // read dictionary file
    set<string> dictionary;
    string data;
    while(getline(infile, data)){
        dictionary.insert(data);
    }

    bool new_game = true;

    // Keep playing the game until the user decides otherwise
    while (new_game ) {

        int word_length = game.get_integer("Enter word length to play with:");

        int num_guesses = game.get_integer("How many guesses would you like?");

        // remain possible for the current display word and previous guesses
        bool show_word_number = get_yesno("Would you like to see a running total"
                                          " of words in the list?");

        string badGuess = game.badGuessString( word_length );

        set<string> list;

        game.trimDictionary( word_length, list, dictionary);
        vector<char> word(word_length, '-');

        set<char> guessed_letters;

        cout << endl << "Your word is: ";
        game.printVector( word);

        if (guessed_letters.empty()) {
            cout << "You have not yet guessed any letters." << endl;
        } else {
            cout << "You have already guessed these letters: ";
            game.printSet(guessed_letters);
            cout << endl;
        }

        while (word_length > 0 && num_guesses > 0) {
            char guess = get_letter("What is your next guess?");
            bool bad_guess = game.was_char_guessed(guess, guessed_letters);
            if (bad_guess) {
                cout << "You already guessed that. Try Again!" << endl;
                continue;
            } else {
                guessed_letters.insert(guess);
            }
            hangman::wordFamilyMap wordFamilies;
            game.formWordFamilies(guess, list, wordFamilies);
            pair<string, hangman::WordFamily> maxWordFamily = *max_element(wordFamilies.begin(),
                                                                               wordFamilies.end(), mapCompare);
            list.clear();
            list = maxWordFamily.second.family;
            string wordCode = maxWordFamily.first;
            int lettersGuessed = game.updateWord(wordCode, badGuess, guess, word);
            if (lettersGuessed == 0) {
                num_guesses--;
            }else {
                word_length -= lettersGuessed;
            }
            cout << endl;
            game.printWordFamily(word, num_guesses, show_word_number, list);
        }
        if (game.is_won()) {
            cout << "Congratulations! You won the game!" << endl << endl;
        }
        if (game.is_lost()) {
            cout << "Oh no! You lost!!!" << endl;
            cout << "My secret word was: " << game.get_hidden_word() << endl;
        }
        new_game = get_yesno("Would you like to play again?");
        cout << endl;

    }

    cout << "Thank you for playing Hangman." << endl;

    return 0;
}

// Helper Functions:

// get_yesno()
// Prompt for a yes/no response, re-prompting if invalid
// input is given.
bool get_yesno(string msg) {
    while (true) {
        string input;

        cout << msg << endl;
        getline(cin, input);

        input = trim(input);
        for (int i = 0; i < input.size(); i++) {
            input[i] = tolower(input[i]);
        }

        if (input == "y" || input == "yes") return true;
        if (input == "n" || input == "no") return false;

        cout << "I didn't understand that. ";
        cout << "Please enter y(es) or n(o).";
        cout << endl;
    }
}

// get_letter()
// Prompt for a letter of the alphabet, re-prompting if invalid
// input is given.
char get_letter(string msg) {
    while (true) {
        string input;    
 
        cout << msg << endl;
        getline(cin, input);

        input = trim(input);

        if (input.size() == 1) {
            char result = tolower(input[0]);
            if (result >= 'a' && result <= 'z') return result;
        }
        
        cout << "I didn't understand that. ";
        cout << "Please enter a letter of the alphabet.";
        cout << endl;
    }
}

// trim()
//
//
string trim(string s) {
    int a, b;

    for (a = 0; a < s.size() && isspace(s[a]); a++);
    for (b = s.size() - 1; b >= a && isspace(s[b]); b--);

    return s.substr(a, b - a + 1);
}

// mapCompare()
//
//
bool mapCompare(const pair<string, hangman::WordFamily >& lhs,
                         const pair<string, hangman::WordFamily >& rhs)
{
    return lhs.second.freq < rhs.second.freq;
}