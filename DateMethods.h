#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>

using namespace std;

class DateMethods {

public:
    static int numberOfDaysInMonth();
    static bool validateDate(string date);
    static int convertFromStringDateToInt(string dateAsString);
    static string convertFromIntDateToStringWithDashes(int dateAsInt);
    static int convertFromStringDateToIntWithoutDashes(string date);
    static string getCurrentDate();
    static int convertFromStringToInt(string num);
    static string convertFromIntToString(int num);
    static string convertFromFloatToString (double num);
    static float convertFromStringToFloat(string num);
    static int convertDateToInt(string date);
};

#endif
