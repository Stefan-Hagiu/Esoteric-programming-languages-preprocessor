//
//  main.cpp
//  Esoteric programming languages preprocessor
//
//  Created by Stefan Hagiu on 7/28/17.
//  Copyright © 2017 Stefan Hagiu. All rights reserved.
//

#include <fstream>

#include "GetUserInput.hpp"
#include "Singleton.hpp"
#include "FunctionSeparator.hpp"
#include "FunctionExtender.hpp"

Singleton global;

int main() {
    getUserInput();
    readInput();
    extendFunctions();
    
    std::ofstream writer;
    writer.open (global.getoutputFileName());
    writer << global.returnMainData();
}
