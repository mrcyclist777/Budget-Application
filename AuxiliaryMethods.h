#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <chrono>
#include <string>

using namespace std;

class AuxiliaryMethods {

public:
    static string loadLines();
    static int loadIntegerNumber();
    static char loadChar();
    static float loadFloat();
    static char selectOptionsFromHomeMenu();
    static char selectOptionsFromUserMenu();
};

#endif

