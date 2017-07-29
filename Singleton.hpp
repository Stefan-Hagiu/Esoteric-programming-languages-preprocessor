//
//  Singleton.hpp
//  Esoteric programming languages preprocessor
//
//  Created by Stefan Hagiu on 7/28/17.
//  Copyright © 2017 Stefan Hagiu. All rights reserved.
//

#ifndef Singleton_hpp
#define Singleton_hpp

#include <string>
#include <iostream>

class functionClass {
public:
    std::string functionName;
    std::string functionData;
};

class Singleton {
private:
    
public:
    
    void setfunctionDefChar (char newfunctionDefChar);
    void setfunctionBodyChar (char newfunctionBodyChar);
    void setinputFileName (std::string newinputFileName);
    void setoutputFileName (std::string newoutputFileName);
    
    char getfunctionDefChar ();
    char getfunctionBodyChar ();
    std::string getinputFileName ();
    std::string getoutputFileName ();
    
    void addToFunctionList (std::string functionName, std::string functionData);
    
    int getFunctionCount ();
    functionClass& getFunctionAtIndexByReference (int index);
    
};

#endif /* Singleton_hpp */
