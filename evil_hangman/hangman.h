#ifndef _HANGMAN_H
#define _HANGMAN_H

/*
    hangman.h
        
    Class definition for the hangman class.

    assignment: CSCI 262 Project - Evil Hangman        

    author: Alexandra Ernst

    last modified: 3/15/2019
*/

#include <set>
#include <vector>
#include <map>

using namespace std;

/******************************************************************************
   class hangman

   Maintains game state for a game of hangman.

******************************************************************************/

class hangman {
public:
    hangman();

    struct WordFamily {
        int freq;
        set<string> family;
    };

    typedef map< string, WordFamily>  wordFamilyMap;

    set<string> dictionary;
    int num_guesses;

    // Generates a Word of All zeros to represent an Incorrect Guess
    string badGuessString( int word_length );

    void trimDictionary( int word_length, set<string>& list, set<string>& dictionary);

    // Has this character already been guessed?
    bool was_char_guessed(char c, set<char> guessed_letters);

    // Forms the Map of word Families with their Frequencies
    void formWordFamilies(char guess, set<string> dictionary, hangman::wordFamilyMap& wordFamilies);

    // Update the Blank Word with the Guessed Letter
    int updateWord( string wordCode, string badGuess, char guess, vector<char>& word);

    // Outputs the result after Each Turn: Word, Number of Guesses left, number of letters left in list
    void printWordFamily( vector<char> word, int num_guesses, bool show_num_words, set<string>& list );

    // Has the game been won/lost?  (Else, it continues.)
    bool is_won();
    bool is_lost();

    // Return the true hidden word.
    string get_hidden_word();

    // gets a non-negative integer
    int get_integer(string msg);

    // Prints a Vector
    void printVector( vector<char> word);

    // prints a set of chars
    void printSet( set<char> setOfChar );

    // Prints the contents of a set of Strings
    void printSetOfStrings( set<string>& setOfString );

private:
    
};

#endif