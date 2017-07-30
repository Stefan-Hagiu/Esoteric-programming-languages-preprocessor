#include "FunctionSeparator.hpp"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

static Singleton global;

string getFunctionName (int &currentIndex, string receivedInput) {
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

string getFunctionData (int &currentIndex, string receivedInput) {
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

void separateInFunctions (string receivedInput) {
    string newFunctionName;
    string newFunctionData;
    int index = 0;
    
    if (receivedInput.size () == 0) {
        cout << "Invalid input file";
        exit (EXIT_FAILURE);
    }
    
    while (index < receivedInput.size () - 1) {
        newFunctionName = getFunctionName (index, receivedInput);
        if (index < receivedInput.size()) {
            newFunctionData = getFunctionData (index, receivedInput);
        }
        global.addToFunctionList(newFunctionName, newFunctionData);
    }
    
}
