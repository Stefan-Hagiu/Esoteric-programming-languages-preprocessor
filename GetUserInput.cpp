//
//  GetUserInput.cpp
//  Esoteric programming languages preprocessor
//
//  Created by Stefan Hagiu on 7/28/17.
//  Copyright © 2017 Stefan Hagiu. All rights reserved.
//

#include <iostream>
#include "Singleton.hpp"
#include "GetUserInput.hpp"

void getUserInput () {
    Singleton s;
    char newInput;
    std::string newFileName;
    
    std::cout << "Please insert the char used to denote a function definition.\n";
    std::cin >> newInput;
    s.setfunctionDefChar(newInput);
    
    std::cout << "\n Please insert the char used to denote a function body.\n";
    std::cin >> newInput;
    s.setfunctionBodyChar(newInput);
    
    std::cout << "\n Please insert the name of the input file. (example: input.txt)\n";
    std::cin >> newFileName;
    s.setinputFileName(newFileName);
    
    std::cout << "\n Please insert the name of the output file. (example: output.txt)\n";
    std::cin >> newFileName;
    s.setoutputFileName(newFileName);
}
