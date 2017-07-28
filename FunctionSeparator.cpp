//
//  FunctionSeparator.cpp
//  Esoteric programming languages preprocessor
//
//  Created by Stefan Hagiu on 7/28/17.
//  Copyright © 2017 Stefan Hagiu. All rights reserved.
//

#include "FunctionSeparator.hpp"
#include "Singleton.hpp"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

Singleton global;

string receivedInput;

void readInput () {
    string textLine;
    fstream reader;
    reader.open (global.getinputFileName ());
    while (!reader.eof ()) {
        getline(reader, textLine);
        receivedInput += textLine;
    }
    
    separateInFunctions();
}

string getFunctionName (int &currentIndex) {
    string functionName;
    
    if (receivedInput [currentIndex] != global.getfunctionDefChar()) {
        cout << "Invalid input file";
        exit (EXIT_FAILURE);
    }
    
    currentIndex ++;
    while (receivedInput [currentIndex] != ' ') {
        functionName += receivedInput [currentIndex];
        currentIndex ++;
    }
    
    return functionName;
}

string getFunctionData (int &currentIndex) {
    string functionData;
    while (receivedInput [currentIndex] != global.getfunctionDefChar()) {
        functionData += receivedInput [currentIndex];
        currentIndex ++;
        if (currentIndex == receivedInput.size ()) {
            cout << "Invalid input file";
            exit (EXIT_FAILURE);
        }
    }
    return functionData;
}

void separateInFunctions () {
    string newFunctionName;
    string newFunctionData;
    int index = 0;
    
    while (index < receivedInput.size ()) {
        newFunctionName = getFunctionName (index);
        newFunctionData = getFunctionData (index);
    }
    global.addToFunctionList(newFunctionName, newFunctionData);
}
