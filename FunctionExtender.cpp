//
//  FunctionExtender.cpp
//  Esoteric programming languages preprocessor
//
//  Created by Stefan Hagiu on 7/29/17.
//  Copyright © 2017 Stefan Hagiu. All rights reserved.
//

#include "FunctionExtender.hpp"
#include "Singleton.hpp"
#include <vector>

using namespace std;

static Singleton global;
static vector<functionClass> functionReferences;

void getFunctionReferences() {
    int index;
    for (index = 0; index < global.getFunctionCount(); index++) {
        functionReferences.push_back (global.getFunctionAtIndexByReference(index));
    }
}

void extendFunctions () {
    getFunctionReferences();
}
