//
//  Singleton.cpp
//  Esoteric programming languages preprocessor
//
//  Created by Stefan Hagiu on 7/28/17.
//  Copyright © 2017 Stefan Hagiu. All rights reserved.
//

#include "Singleton.hpp"
#include <vector>
#include <string>

using namespace std;

static char functionDefChar;
static char functionBodyChar;
static string inputFileName;
static string outputFileName;

class functionClass {
public:
    string functionName;
    string functionData;
};
static vector <functionClass> functionList;


void Singleton::setfunctionDefChar(char newfunctionDefChar) {
        functionDefChar = newfunctionDefChar;
    }
void Singleton::setfunctionBodyChar(char newfunctionBodyChar) {
        functionBodyChar = newfunctionBodyChar;
    }
void Singleton::setinputFileName (string newinputFileName) {
    inputFileName = newinputFileName;
}
void Singleton::setoutputFileName (string newoutputFileName) {
    outputFileName = newoutputFileName;
}

char Singleton::getfunctionDefChar () {
        return functionDefChar;
    }
char Singleton::getfunctionBodyChar () {
        return functionBodyChar;
    }
string Singleton::getinputFileName () {
    return inputFileName;
}
string Singleton::getoutputFileName () {
    return outputFileName;
}

void Singleton::addToFunctionList (string functionName, string functionData) {
    functionClass newFunction;
    newFunction.functionName = functionName;
    newFunction.functionData = functionData;
    functionList.push_back(newFunction);
}
