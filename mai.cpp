#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;	

int main()
{
    
    ifstream inputFile("input.txt");

    
    if (!inputFile.is_open()) {
        cout << "Unable to open input file!" << endl;
        return 1;
    }

    ofstream outputFile("statistics.txt");

    
    if (!outputFile.is_open()) {
        cout << "Unable to open output file for statistics!" << endl;
        inputFile.close();  
        return 1;
    }

    
    char ch;
    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    while (inputFile.get(ch)) {
        charCount++;

        if (ch == '\n') {
            lineCount++;
        }
        else if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            }
            else {
                consonantCount++;
            }
        }
        else if (std::isdigit(ch)) {
            digitCount++;
        }
    }

    outputFile << "Number of characters: " << charCount << endl;
    outputFile << "Number of lines: " << lineCount << endl;
    outputFile << "Number of vowels: " << vowelCount << endl;
    outputFile << "Number of consonants: " << consonantCount << endl;
    outputFile << "Number of digits: " << digitCount << endl;

    
    inputFile.close();
    outputFile.close();

    cout << "Statistics generated. Check the 'statistics.txt' file." << endl;

    return 0;
}
