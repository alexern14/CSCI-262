#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "personality_test.h"

using namespace std;

/* Load method
 * 2) Ensure to see if the input is "correct" (do at least one simple check, like first character is a number)
 * Input: istream object
 * Output: Boolean
 */
bool personality_test::load(istream &in) {
    int num_lines;
    in >> num_lines;
    string garbage;
    getline(in, garbage);
    for(int i =0; i < num_lines; i++){

        int category_id;
        in >> category_id;
        string line;
        getline(in, line);

        char no_answer = line.at(line.size() - 1);
        line.pop_back();
        line.pop_back();
        char yes_answer = line.at(line.size() - 1);
        line.pop_back();
        line.pop_back();
        line = line.substr(1, line.size());
        //cout << category_id << line << yes_answer << no_answer;

       question q;
       q.category_id = category_id;
       q.line = line;
       q.yes_answer = yes_answer;
       q.no_answer = no_answer;

       questions.push_back(q);

    }
    return true;
    //cout << "called load" << endl;
    //return false;
}

/* personality_test::printout method
 * 1) Printout the questions to ensure that the load method was written correctly
 * This part will not be graded, just for your own check
 */
void personality_test::printout() {
    cout << "called printout" << endl;
}

/* Run Test method
 * @param: None
 * @return: None, Text to Console
 */
void personality_test::run_test() {

    string personality = analyze_personality();
    categorize_output(personality);
    save_output(personality);
}

/* Analyze Personality Method
 * @param None
 * @return string
 */
string personality_test::analyze_personality() {

    int num_lines;
    string personality;
    int countI = 0, countE = 0, countN = 0, countS = 0, countF = 0, countT = 0, countP = 0, countJ = 0;
    string categories;
    for (int i = 0; i < num_lines; i++) {

        cout << questions[i].line << "? y/n" << endl;
        string answer;
        cin >> answer;

        char answers;

        if (answer == "n" || answer == "N" || answer == "no" || answer == "NO" || answer == "No") {
            answers = questions[i].no_answer;
            categories += answers;

        } else if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes" || answer == "YES") {
            answers = questions[i].yes_answer;
            categories += answers;
        } else {
            cout << "Sorry, I didn't recognize your input, please type again." << endl;
            i--;
            continue;
        }
    }

    for (int j = 0; j < num_lines; j++) {

        if (categories[j] == 'I') countI++;
        if (categories[j] == 'E') countE++;
        if (categories[j] == 'N') countN++;
        if (categories[j] == 'S') countS++;
        if (categories[j] == 'F') countF++;
        if (categories[j] == 'T') countT++;
        if (categories[j] == 'P') countP++;
        if (categories[j] == 'J') countJ++;
    }

    string personality_EI;
    if (countE > countI) {
        personality_EI = "E";
        personality += "E";
    } else {
        personality_EI = "I";
        personality += "I";
    }
    string personality_NS;
    if (countN > countS) {
        personality_NS = "N";
        personality += "N";
    } else {
        personality_NS = "S";
        personality += "S";
    }
    string personality_FT;
    if (countF > countT) {
        personality_FT = "F";
        personality += "F";
    } else {
        personality_FT = "T";
        personality += "T";
    }
    string personality_PJ;
    if (countP > countJ) {
        personality_PJ = "P";
        personality += "P";
    } else {
        personality_PJ = "J";
        personality += "J";
    }

    //cout << personality << endl;
    return personality;

}

/* Categorize Output Method
 * @param Personality type string (eg. "ENFJ")
 * @return None, Text to console
 */
void personality_test::categorize_output(string my_personality) {
    string fileName;
    cout << endl << "Please enter the analysis file name, e.g., 'analysis.txt': ";
    cin >> fileName;
    ifstream fin;
    fin.open(fileName);
    while (fin.fail()) {
        cout << "Error opening " << fileName;
        cin >> fileName;
        fin.clear();
        fin.open(fileName.c_str());
    }

    int num_lines;
    fin >> num_lines;
    string str;

    string p_type, category, type, description;

    while(getline(fin, str)){
        if (str.find(my_personality)){
            fin >> p_type >> category >> type;
            getline(fin, description);
        }
    }

    question o;
    o.p_type = p_type;
    o.category = category;
    o.type = type;
    o.description = description;
    output.push_back(o);

    cout << endl << "=====================" << endl;
    cout << "Your personality type is: " << p_type << endl;
    cout << "The category is: " << category << endl;
    cout << "You are: The " << type << endl;
    cout << "Description: " << description << endl;
    cout << "=====================" << endl;

}

/* Save Output
 * @param string (the thing to write)
 * @return None, creates a file
 */
void personality_test::save_output(string personality) {

    string p_type = output[0].p_type;
    string category = output[0].category;
    string type = output[0].type;
    string description = output[0].description;

    string save;
    cout << "Would you like to save? y/n" << endl;
    cin >> save;
    if (save == "y" || save == "Y" || save == "yes" || save == "Yes" || save == "YES") {
        cout << "Please enter a file name" << endl;
        string save_file;
        cin >> save_file;
        ofstream outfile;
        outfile.open(save_file);
        outfile << "Your personality type is: " << p_type << endl;
        outfile << "The category is: " << category << endl;
        outfile << "You are: The " << type << endl;
        outfile << "Description: " << description << endl;
        outfile.close();
    }
    string again;
    cout << "Would you like to play again? y/n" << endl;
    while(again == "y" || again == "Y" || again == "yes" || again == "Yes" || again == "YES") {

    }
}
