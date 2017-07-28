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

void separateInFunctions () {
    
}
