#include <iostream>
#include <fstream>
using namespace std;

void countBasicCharacters(const string& filename, int* &charCount, int& size) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        return;
    }

    string wordToFind = "BASIC";

    char ch;
    while (file.get(ch)) {
        if (wordToFind.find(ch) != string::npos) {
            int index = static_cast<unsigned char>(ch);
            if (index >= size) {
                int* temp = new int[index + 1]();
                for (int i = 0; i < size; ++i) {
                    temp[i] = charCount[i];
                }
                delete[] charCount;
                charCount = temp;
                size = index + 1;
            }
            charCount[index]++;
        }
    }

    file.close();
}

int main() {
    string filename = "/Users/anakuhar/Desktop/lab10.1/lab10.1.txt"; 

    int* charCount = new int[256](); 

    int size = 256;

    countBasicCharacters(filename, charCount, size);

    for (int i = 0; i < size; ++i) {
        if (charCount[i] > 0) {
            cout << "Character '" << static_cast<char>(i) << "' occurs " << charCount[i] << " times." << endl;
        }
    }

    delete[] charCount; 

    return 0;
}