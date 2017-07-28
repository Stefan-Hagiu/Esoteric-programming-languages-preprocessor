//
//  Singleton.cpp
//  Esoteric programming languages preprocessor
//
//  Created by Stefan Hagiu on 7/28/17.
//  Copyright © 2017 Stefan Hagiu. All rights reserved.
//

#include "Singleton.hpp"

using namespace std;

char functionDefChar;
char functionBodyChar;
string inputFileName;
string outputFileName;


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
