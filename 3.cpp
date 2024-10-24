#include <iostream>
#include <fstream>
#include <string>

#define E endl;

using namespace std;


string transliterate(const string& word) {
    char ukrainianChars[] = { 'А', 'Б', 'В', 'Г', 'Ґ', 'Д', 'Е', 'Є', 'Ж', 'З', 'И', 'І', 'Ї', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ь', 'Ю', 'Я' };
    string englishChars[] = { "A", "B", "V", "H", "G", "D", "E", "Ye", "Zh", "Z", "Y", "I", "Yi", "Y", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "F", "Kh", "Ts", "Ch", "Sh", "Shch", "", "Yu", "Ya" };

    string result = "";
    for (char c : word) {
        bool found = false;
        for (int i = 0; i < sizeof(ukrainianChars) / sizeof(ukrainianChars[0]); ++i) {
            if (c == ukrainianChars[i]) {
                result += englishChars[i];
                found = true;
                break;
            }
        }
        if (!found) {
            result += c; 
    }
    return result;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "File input.txt does not exist." << E
        return 1;
    }

    ofstream outputFile("output.txt");
    if (!outputFile) {
        cout << "File output.txt could not be created." << E
        return 1;
    }

    string word;

  
    while (inputFile >> word) {
        string transliteratedWord = transliterate(word);
        outputFile << transliteratedWord << " ";

    inputFile.close();
    outputFile.close();

    cout << "Transliterated text written to file output.txt." << E

    return 0;
}
