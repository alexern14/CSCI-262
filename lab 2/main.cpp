#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {


    int number_of_lines = 0;
    string str;
    string x;
    string word;
    int line_number = 0;
    string searchword;

    ifstream fin;
    fin.open("lines.txt");

    while (getline(fin, str)) {
        //line_number++;

        if (fin) {
            while (fin >> word) {
                int len = word.size();
                if (word.size() > x.size()) {

                    x = word;
                }
            }
            cout << "the longest word is: " << x << endl;

        }

        string FileName;

        cout << "enter the word to look for: " << endl;
        cin >> searchword;
        cout << "Enter the name of file you want to open: ";
        cin >> FileName;

        ifstream FileSearch;

        FileSearch.open(FileName);

        while(!FileSearch.eof())
        {
            while (getline(fin,str)) {
                line_number++;
            }
            string temp;
            FileSearch >> temp;

            if(temp == searchword)
            {
                cout << searchword << " found on line: " << line_number << "\n\n";
                break;
            }
        }
        //cout << line_number;
    }
}



   /* while (getline(fin,str)){
        cout << str << endl;
        number_of_lines++;
        }

    }
    cout << word;

    cout << number_of_lines;

    //istringstream sin(str);

    //fin.close();
}

/*#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
    using namespace std;

    const string FNAME = "lines.txt";

    const string PUNC = ".?!,;";
    int main()
    {
        cout << "\n";
        cout << " FILENAME: " << FNAME << endl;
        cout << "\n";
        ifstream fin( FNAME.c_str() );
       if(fin )
        {
            int numWords = 0, numChars = 0;
            string word;
            cout << fixed << setprecision(0);
            string x;
            while( fin >> word )
            {
                ++numWords;
                int len = word.size();
                if( PUNC.find( word[len-1] ) != string::npos )
                    word.erase( len-1 );
                numChars += word.size();
                cout << ' ' << left << word;
                if(word.size() > x.size()){
                    x = word;
                }

            }
            fin.close();
            cout << "\n\n Number of words was " << numWords
                 << "\n Number of letters was " << numChars
                 << "\n Average letters per word was "
                 << double(numChars) / numWords << endl;
            cout << " Last word in file is: " << word << " and it is "
                 << word.size() << " letters long\n";
            cout << "the longest word is:" << x << endl;
        }
        else
            cout << "\nThere was a problem opening file "
                 << FNAME << endl;
        cout << "\nPress 'Enter' to continue/exit ... ";
        cin.get();
    } */
