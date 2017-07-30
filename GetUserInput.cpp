#include <iostream>
#include <string>
#include <fstream>

#include "GetUserInput.hpp"

using namespace std;

static Singleton global;
static string receivedInput;

void getUserInput () {
    Singleton s;
    char newInput;
    string newFileName;
    
    cout << "Please insert the char used to denote a function definition.\n";
    cin >> newInput;
    s.setfunctionDefChar(newInput);
    
    cout << "\n Please insert the char used to denote a function body.\n";
    cin >> newInput;
    s.setfunctionBodyChar(newInput);
    
    cout << "\n Please insert the name of the input file. (example: input.txt)\n";
    cin >> newFileName;
    s.setinputFileName(newFileName);
    
    cout << "\n Please insert the name of the output file. (example: output.txt)\n";
    cin >> newFileName;
    s.setoutputFileName(newFileName);
}

void readInput () {
    string textLine;
    fstream reader;
    reader.open (global.getinputFileName ());
    while (!reader.eof ()) {
        getline(reader, textLine);
        receivedInput += textLine;
        receivedInput += '\n';
    }
    
    separateInFunctions(receivedInput);
}

