#include <iostream>
#include <fstream>
#include <sstream>
using namespace std; 

string findLastWordStartingWithA(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return "";
    }

    const int MAX_WORDS = 1000; 
    string words[MAX_WORDS];
    string word;
    int wordCount = 0;

    while (file >> word && wordCount < MAX_WORDS) {
        if (word.front() == 'a' || word.front() == 'A') {
            words[wordCount++] = word;
        }
    }

    file.close();

    string lastWordStartingWithA;
    for (int i = 0; i < wordCount; ++i) {
        lastWordStartingWithA = words[i];
    }

    return lastWordStartingWithA;
}

int main() {
    string filename = "/Users/anakuhar/Desktop/lab10.2/lab10.2.txt"; 

    string lastWord = findLastWordStartingWithA(filename);
    if (!lastWord.empty()) {
        cout << "Останнє слово, що починається з 'a': " << lastWord << endl;
    } else {
        cout << "Слово не знайдено." << endl;
    }

    return 0;
}
