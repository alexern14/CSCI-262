/*
    hangman.cpp
        
    Method implementations for the hangman class.
    
    assignment: CSCI 262 Project - Evil Hangman        

    author: Alexandra Ernst

    last modified: 3/15/2019
*/

#include "hangman.h"
#include <fstream>
#include <iostream>

using namespace std;

// constructor
hangman::hangman() {

    ifstream infile;
    infile.open("dictionary.txt");

    if(!infile.is_open()){
        cout << "Unable to open file" << endl;
        exit(0);
    }
    set<string> dictionary;
    string data;
    while(getline(infile, data)){
        dictionary.insert(data);
    }
}

// badGuessString()
//
// Generates a Word of All zeros to represent an Incorrect Guess
string hangman::badGuessString( int word_length )
{
    string zeros;
    for (int i = 0; i < word_length; i++ ) {
        zeros += '0';
    }
    return zeros;
}

// trimDictionary()
//
//
void hangman::trimDictionary( int word_length, set<string>& list, set<string>& dictionary)
{
    while( list.empty() ) {
        for(auto itr = dictionary.begin(); itr != dictionary.end(); ++itr) {
            if ( (*itr).length() == word_length ) {
                list.insert(*itr);
            }
        }
        if( list.empty()) {
            word_length = get_integer( "No word that long in the Dictionary, Try Again!");
        }
    }
    return;
}

// was_char_guessed()
//
// Return true if letter was already guessed.
bool hangman::was_char_guessed(char guess, set<char> guessed_letters) {

    if(guessed_letters.find(guess) == guessed_letters.end()) return false;
    else return true;
}

// formWordFamiles()
//
// Forms the Map of word Families with their Frequencies
void hangman::formWordFamilies( char guess, set<string> list, hangman::wordFamilyMap& wordFamilies)
{
    // Loop over each word in the masterList
    string tempWord;
    for (auto itr = list.begin(); itr != list.end(); ++itr) {
        tempWord = *itr;
        //*debug* cout << tempWord << endl;

        // Replace word with the position locator of nextCh
        for (int i = 0; i < tempWord.length(); i++) {
            if (tempWord[i] == guess)
                tempWord[i] = '1';
            else tempWord[i] = '0';
        }
        // Add the word to some Family in the Map and increment Family's frequency
        if ( wordFamilies.find(tempWord) == wordFamilies.end() ) {
            // Object of the Struct WordFamily containing a family & its frequency
            hangman::WordFamily wordFamily;

            wordFamily.freq = 1;
            wordFamily.family.insert( *itr );
            wordFamilies.insert( pair<string, hangman::WordFamily> (tempWord, wordFamily) );
        } else {
            wordFamilies[tempWord].freq++;
            wordFamilies[tempWord].family.insert( *itr);
        }
    }
}

// updateWord()
//
// Update the Blank Word with the Guessed Letter
int hangman::updateWord( string wordCode, string badGuess, char guess, vector<char>& word)
{
    if ( wordCode == badGuess )
        return 0;

    int count = 0;
    for (int i = 0; i < wordCode.length(); i++){
        if ( wordCode[i] == '1') {
            word[i] = guess;
            count++;
        }
    }
    return count;
}

// printWordFamilyOthers()
//
// Outputs the result after Each Turn: Word, Number of Guesses left, number of letters left in list
void hangman::printWordFamily( vector<char> word, int num_guesses, bool show_word_number, set<string>& list )
{
    printVector( word);

    cout << "Guesses Left: " << num_guesses << endl;
    cout << endl;

    if ( show_word_number ) {
        cout << "Words left in my list: " << list.size() << endl;
        // uncomment the following two lines if you'd like to see the words in the remaining list
//        cout << "Words contained: ";
//        printSetOfStrings( list);
        cout << endl;
    }
}

// is_won()
//
// Return true if the game has been won by the player.
bool hangman::is_won() {
    bool is_won;
    if(num_guesses != 0){
        is_won = true;
    }else{
        is_won = false;
    }
    return is_won;
}

// is_lost()
//
// Return true if the game has been lost.
bool hangman::is_lost() {
    bool is_lost;
    if(num_guesses == 0){
        is_lost = true;
    }else{
        is_lost = false;
    }
    return is_lost;
}

// get_hidden_word()
//
// Return the true hidden word to show the player.
string hangman::get_hidden_word() {
    string hidden_word = *dictionary.begin();
    return hidden_word;
}

// Helper Functions:

// get_integer()
//
// gets a non-negative integer
int hangman::get_integer(string msg) {
    while (true) {
        string input;
        int result = 0;

        cout << msg << endl;
        getline(cin, input);

        result = atoi(input.c_str());
        if (result > 0) return result;

        cout << "I didn't understand that. Please enter a positive integer.";
        cout << endl;
    }
}

// printVector()
//
// Prints a Vector
void hangman::printVector( vector<char> word)
{
    for (size_t i = 0; i < word.size(); i++) {
        cout << word[i];
    }
    cout << '\n' << endl;
}

// printSet()
//
// prints a set of chars
void hangman::printSet( set<char> setOfChar )
{

    for ( auto itr = setOfChar.begin(); itr != setOfChar.end(); ++itr ){
        cout << *itr << ", ";
    }
    cout << "\b\b " << endl;
}

// printSetOfStrings()
//
// Prints the contents of a set of Strings
void hangman::printSetOfStrings( set<string>& setOfString )
{
    for ( auto itr = setOfString.begin(); itr != setOfString.end(); ++itr ){
        cout << *itr << ", ";
    }
    cout << "\b\b " << endl;
}