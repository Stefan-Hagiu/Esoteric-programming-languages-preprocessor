#include "FunctionExtender.hpp"
#include <string>
#include <vector>

using namespace std;

static Singleton global;
static vector<functionClass> functionValues;

static bool finishedExpanding = false;
static bool oneFunctionExpanded;

string findMainData () {
    int index;
    for (index = 0; index < functionValues.size(); index++) {
        if (functionValues [index].functionName == "main") {
            return functionValues [index].functionData;
        }
    }
    cout << "Invalid input";
    exit(EXIT_FAILURE);
}

string getFunctionDataByFunctionName (string functionName) {
    int index;
    for (index = 0; index < functionValues.size(); index++) {
        if (functionValues [index].functionName == functionName) {
            return functionValues [index].functionData;
        }
    }
    cout << "Invalid input";
    exit (EXIT_FAILURE);
}

void getFunctionValues() {
    int index;
    for (index = 0; index < global.getFunctionCount(); index++) {
        functionValues.push_back (global.getFunctionAtIndex(index));
    }
}

string getName (int firstIndex, int secondIndex, string data) {
    string name;
    int index;
    for (index = firstIndex; index <= secondIndex; index ++) {
        name += data [index];
    }
    return name;
}

void tryExpandingCode (string &functionData) {
    string newfunctionData;
    int firstOccurence;
    int secondOccurence;
    int index;
    
    while (functionData.find (global.getfunctionBodyChar(),0) != string::npos) {
        oneFunctionExpanded = true;
        firstOccurence = functionData.find (global.getfunctionBodyChar(),0);
        secondOccurence = functionData.find (global.getfunctionBodyChar(),firstOccurence + 1);
        if (secondOccurence == string::npos || secondOccurence == firstOccurence + 1) {
            cout << "Invalid input";
            exit(EXIT_FAILURE);
        }
        
        for (index = 0; index < firstOccurence; index++) {
            newfunctionData += functionData [index];
        }
        newfunctionData += getFunctionDataByFunctionName (getName (firstOccurence + 1, secondOccurence - 1, functionData) );
        for (index = secondOccurence + 1; index < functionData.size(); index ++) {
            newfunctionData += functionData [index];
        }
        functionData = newfunctionData;
        newfunctionData = "";
    }
}

void extendFunctions () {
    int index;
    getFunctionValues();
    while (!finishedExpanding) {
        oneFunctionExpanded = false;
        for (index = 0; index < functionValues.size(); index ++) {
            tryExpandingCode (functionValues [index].functionData);
        }
        finishedExpanding = !oneFunctionExpanded;
    }
    global.setFinalMainFunctionData(findMainData());
}
