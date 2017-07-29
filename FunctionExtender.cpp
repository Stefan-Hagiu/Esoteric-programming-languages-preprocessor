//
//  FunctionExtender.cpp
//  Esoteric programming languages preprocessor
//
//  Created by Stefan Hagiu on 7/29/17.
//  Copyright © 2017 Stefan Hagiu. All rights reserved.
//

#include "FunctionExtender.hpp"
#include "Singleton.hpp"
#include <string>
#include <vector>

using namespace std;

static Singleton global;
static vector<functionClass> functionReferences;

static bool finishedExpanding = false;
static bool oneFunctionExpanded;

void getFunctionReferences() {
    int index;
    for (index = 0; index < global.getFunctionCount(); index++) {
        functionReferences.push_back (global.getFunctionAtIndexByReference(index));
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
        newfunctionData += global.getFunctionDataByFunctionName (getName (firstOccurence + 1, secondOccurence - 1, functionData) );
        for (index = secondOccurence + 1; index < functionData.size(); index ++) {
            newfunctionData += functionData [index];
        }
        functionData = newfunctionData;
    }
}

void extendFunctions () {
    int index;
    getFunctionReferences();
    while (!finishedExpanding) {
        oneFunctionExpanded = false;
        for (index = 0; index < functionReferences.size(); index ++) {
            tryExpandingCode (functionReferences [index].functionData);
        }
        finishedExpanding = !oneFunctionExpanded;
    }
}
