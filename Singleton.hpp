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
    
public:
    
    void setfunctionDefChar(char newfunctionDefChar);
    void setfunctionBodyChar(char newfunctionBodyChar);
    
    char getfunctionDefChar ();
    char getfunctionBodyChar ();
};

#endif /* Singleton_hpp */
