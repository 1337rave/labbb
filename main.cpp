#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "File 'input.txt' not found. Creating a new file." << endl;
        ofstream newInputFile("input.txt");
        newInputFile << "Hello World!This text will be processed by the program.";
        newInputFile.close();
        inputFile.open("input.txt");
    }

    if (!inputFile.is_open()) {
        cerr << "Failed to open the input file." << endl;
        return 1; 
    }

    ofstream outputFile("output.txt");

    if (!outputFile.is_open()) {
        cerr << "Failed to open the output file." << endl;
        return 1; 
    }

    string word;

    while (inputFile >> word) {

        if (word.length() >= 7) {
            outputFile << word << " ";
        }
    }
    inputFile.close();
    outputFile.close();

    cout << "Words with seven or more letters have been written to output.txt." << endl;

    return 0;
}
