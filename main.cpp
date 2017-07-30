#include <fstream>
#include "GetUserInput.hpp"
#include "Singleton.hpp"
#include "FunctionExtender.hpp"

static Singleton global;

int main() {
    getUserInput();
    readInput();
    extendFunctions();
    
    std::ofstream writer;
    writer.open (global.getoutputFileName());
    writer << global.getFinalMainFunctionData();
    writer.flush();
    return 0;
}
