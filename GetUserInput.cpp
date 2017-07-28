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
    
    std::cout << "Please insert the char used to denote a function definition.\n";
    std::cin >> newInput;
    s.setfunctionDefChar(newInput);
    
    std::cout << "\n Please insert the char used to denote a function body.\n";
    std::cin >> newInput;
    s.setfunctionBodyChar(newInput);
}
