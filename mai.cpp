#include <iostream>
#include <string>
#include <fstream>

using namespace std;	

int main()
{
    
    ifstream inputFile("input.txt");

    
    if (!inputFile.is_open()) {
        cerr << "Unable to open input file!" << endl;
        return 1;
    }

    
    ofstream outputFile("output.txt");

    
    if (!outputFile.is_open()) {
        cerr << "Unable to open output file!" << endl;
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

   cout << "Processing complete. Check the 'output.txt' file." << endl;

    return 0;
}
