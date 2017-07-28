//
//  Singleton.cpp
//  Esoteric programming languages preprocessor
//
//  Created by Stefan Hagiu on 7/28/17.
//  Copyright © 2017 Stefan Hagiu. All rights reserved.
//

#include "Singleton.hpp"

static char functionDefChar;
static char functionBodyChar;

void Singleton::setfunctionDefChar(char newfunctionDefChar) {
        functionDefChar = newfunctionDefChar;
    }
void Singleton::setfunctionBodyChar(char newfunctionBodyChar) {
        functionBodyChar = newfunctionBodyChar;
    }
    
char Singleton::getfunctionDefChar () {
        return functionDefChar;
    }
char Singleton::getfunctionBodyChar () {
        return functionBodyChar;
    }
