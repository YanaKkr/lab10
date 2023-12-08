#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

void countNumbersAndWords(const string& inputFilename, const string& outputFilename) {
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "Unable to open input file " << inputFilename << endl;
        return;
    }

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "Unable to open output file " << outputFilename << endl;
        inputFile.close();  // Close input file before returning
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int positive = 0, negative = 0, zero = 0, words = 0;
        string word;

        while (ss >> word) {
            try {
                int value = stoi(word);

                if (value == 0) {
                    zero++;
                } else if (value > 0) {
                    positive++;
                } else {
                    negative++;
                }

                words++;
            } catch (const std::invalid_argument& e) {
                // Handle the case where 'word' is not a valid integer
                cerr << "Invalid integer found: " << word << endl;
            } catch (const std::out_of_range& e) {
                // Handle the case where 'word' is out of the range of int
                cerr << "Out of range integer found: " << word << endl;
            }
        }

        outputFile << "Positive numbers: " << positive << " | Negative numbers: " << negative
                   << " | Zeroes: " << zero << " | Words: " << words << endl;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    string inputFilename, outputFilename;

    cout << "Enter the input filename: ";
    cin >> inputFilename;

    cout << "Enter the output filename: ";
    cin >> outputFilename;

    countNumbersAndWords(inputFilename, outputFilename);

    cout << "Process complete. Results written to " << outputFilename << endl;

    return 0;
}
