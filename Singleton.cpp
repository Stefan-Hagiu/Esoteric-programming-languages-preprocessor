#include "Singleton.hpp"
#include <vector>
#include <string>

using namespace std;

static char functionDefChar;
static char functionBodyChar;
static string inputFileName;
static string outputFileName;
static string finalMainFunctionData;


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
    int index;
    for (index = 0; index < functionList.size(); index++) {
        if (functionList [index].functionName == newFunction.functionName) {
            cout << "Error: function redefinition.";
            exit (EXIT_FAILURE);
        }
    }
    functionList.push_back(newFunction);
}

int Singleton::getFunctionCount () {
    return functionList.size();
}

functionClass Singleton::getFunctionAtIndex (int index) {
    return functionList [index];
}

string Singleton::getFunctionDataByFunctionName (string functionName) {
    int index;
    for (index = 0; index < functionList.size(); index++) {
        if (functionList [index].functionName == functionName) {
            return functionList [index].functionData;
        }
    }
    cout << "Invalid input";
    exit (EXIT_FAILURE);
}

void Singleton::setFinalMainFunctionData (std::string data) {
    finalMainFunctionData = data;
}
std::string Singleton::getFinalMainFunctionData () {
    return finalMainFunctionData;
}
