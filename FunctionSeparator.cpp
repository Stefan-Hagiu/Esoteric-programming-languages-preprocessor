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
        receivedInput += '\n';
    }
    
    separateInFunctions();
}

string getFunctionName (int &currentIndex) {
    string functionName;
    while (receivedInput [currentIndex] != global.getfunctionDefChar()) {
        currentIndex ++;
        if (currentIndex == receivedInput.size ()) {
            cout << "Invalid input file";
            exit (EXIT_FAILURE);
        }
    }
    
    currentIndex ++;
    while (receivedInput [currentIndex] != ' ' && receivedInput [currentIndex] != '\n' && receivedInput [currentIndex] != global.getfunctionDefChar()) {
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
    currentIndex ++;
    return functionData;
}

void separateInFunctions () {
    string newFunctionName;
    string newFunctionData;
    int index = 0;
    
    if (receivedInput.size () == 0) {
        cout << "Invalid input file";
        exit (EXIT_FAILURE);
    }
    
    while (index < receivedInput.size () - 1) {
        newFunctionName = getFunctionName (index);
        newFunctionData = getFunctionData (index);
        global.addToFunctionList(newFunctionName, newFunctionData);
    }
    
}
