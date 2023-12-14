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
        inputFile.close();  
        return 1;
    }

    string line;
    while (std::getline(inputFile, line)) {
        outputFile << line << endl;
    }

    
    inputFile.close();
    outputFile.close();

    cout << "Processing complete. Check the 'output.txt' file." << endl;

    return 0;
}
