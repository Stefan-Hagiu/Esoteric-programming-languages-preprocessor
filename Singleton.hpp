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
    functionClass getFunctionAtIndex (int index);
    std::string getFunctionDataByFunctionName (std::string functionName);
    
    void setFinalMainFunctionData (std::string data);
    std::string getFinalMainFunctionData ();
    
};

#endif /* Singleton_hpp */
