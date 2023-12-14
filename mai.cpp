#include <iostream>
#include <fstream>
#include <string>

using namespace std;	

int main()
{
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cout << "Unable to open input file!" << endl;
        return 1;
    }

   
    ofstream outputFile("output.txt");

    
    if (!outputFile.is_open()) {
        cout << "Unable to open output file!" << endl;
        inputFile.close();  
        return 1;
    }

    string line;
    string lastLineWithoutSpace; 
    bool foundLineWithoutSpace = false;


    while (getline(inputFile, line)) {
        if (line.find(' ') == string::npos) {
            foundLineWithoutSpace = true;
            lastLineWithoutSpace = line;
        }
        outputFile << line << endl;
    }

    
    if (foundLineWithoutSpace) {
        outputFile << "------------" << endl;
    }
    else {
       
        outputFile << endl << "------------" << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Processing complete. Check the 'output.txt' file." << endl;

    return 0;
}
