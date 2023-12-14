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
    string reversedContent;
    while (getline(inputFile, line)) {
        reversedContent = line + "\n" + reversedContent;
    }

    
    outputFile << reversedContent;

    
    inputFile.close();
    outputFile.close();

    cout << "Processing complete. Check the 'output.txt' file." << endl;

    return 0;
}
