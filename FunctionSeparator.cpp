#include "FunctionSeparator.hpp"
#include "Singleton.hpp"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

static Singleton global;

static string receivedInput;

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
            return "";
        }
    }
    
    currentIndex ++;
    while (receivedInput [currentIndex] != ' ' && receivedInput [currentIndex] != '\n' && receivedInput [currentIndex] != global.getfunctionDefChar()) {
        functionName += receivedInput [currentIndex];
        currentIndex ++;
    }
    if (receivedInput [currentIndex] == ' ' || receivedInput [currentIndex] == '\n') {
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
    if (functionData [functionData.size() - 1] == ' ' || functionData [functionData.size() - 1] == '\n') {
        functionData.pop_back();
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
        if (index < receivedInput.size()) {
            newFunctionData = getFunctionData (index);
        }
        global.addToFunctionList(newFunctionName, newFunctionData);
    }
    
}
