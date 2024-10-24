#include <iostream>
#include <fstream>
#include <string>

#define E endl;

using namespace std;

int main() {
 
    ifstream badWordsFile("bad_words.txt");
    if (!badWordsFile) {
        cout << "File bad_words.txt does not exist." << E
        return 1;
    }

    string badWords[100];
    int badWordsCount = 0;
    while (badWordsFile >> badWords[badWordsCount]) {
        badWordsCount++;
    }
    badWordsFile.close();

    // Open input text file
    ifstream inputFile("input_text.txt");
    if (!inputFile) {
        cout << "File input_text.txt does not exist." << E
        return 1;
    }

    ofstream outputFile("filtered_text.txt");
    if (!outputFile) {
        cout << "File filtered_text.txt could not be created." << E
        return 1;
    }

    string word;
    bool isBadWord;

 
    while (inputFile >> word) {
        isBadWord = false;
        
      
        for (int i = 0; i < badWordsCount; ++i) {
            if (word == badWords[i]) {
                isBadWord = true;
                break;
            }
        }

    
        if (!isBadWord) {
            outputFile << word << " ";
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Filtered text written to file filtered_text.txt." << E

    return 0;
}
