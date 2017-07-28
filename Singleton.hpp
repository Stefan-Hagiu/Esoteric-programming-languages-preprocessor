//
//  Singleton.hpp
//  Esoteric programming languages preprocessor
//
//  Created by Stefan Hagiu on 7/28/17.
//  Copyright © 2017 Stefan Hagiu. All rights reserved.
//

#ifndef Singleton_hpp
#define Singleton_hpp

class Singleton {
private:
    
    static char functionDefChar;
    static char functionBodyChar;
    
public:
    
    void setfunctionDefChar(char newfunctionDefChar);
    void setfunctionBodyChar(char newfunctionBodyChar);
    
    char getfunctionDefChar ();
    char getfunctionBodyChar ();
};

#endif /* Singleton_hpp */
