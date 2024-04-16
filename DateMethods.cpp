#include "DateMethods.h"

int DateMethods::numberOfDaysInMonth() {
    int month = 0, year = 0;
    int numberOfDaysinThisMonth = 0;

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 10 || month == 12)
        numberOfDaysinThisMonth = 31;
    else if (month == 2) {
        bool leapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
        if (leapYear == 0)
            numberOfDaysinThisMonth = 28;
        else
            numberOfDaysinThisMonth = 29;
    } else
        numberOfDaysinThisMonth = 30;
    return numberOfDaysinThisMonth;
}

bool DateMethods::validateDate(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    string currentDate = getCurrentDate();
    int currentYear = stoi(currentDate.substr(0, 4));
    int currentMonth = stoi(currentDate.substr(5, 2));
    if (year < 2000 || year > currentYear)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > numberOfDaysInMonth())
        return false;
    if (year == currentYear && month > currentMonth)
        return false;
    return true;
}

int DateMethods::convertFromStringDateToInt(string dateAsString) {
    for (int i = 0; i < (int)dateAsString.length(); i++) {
        if (dateAsString[i] == '-') {
            dateAsString.erase(i, 1);
            i--;
        }
    }
    return convertFromStringToInt(dateAsString);
}

string DateMethods::convertFromIntDateToStringWithDashes(int oldDate) {
    string year, month, day;
    string newDate = DateMethods::convertFromIntToString(oldDate);
    year = newDate.substr(0,4);
    month = newDate.substr(4,2);
    day = newDate.substr(6,2);
    return year + "-" + month + "-" + day;
}

int DateMethods::convertFromStringDateToIntWithoutDashes(string date) {
    for (int i = 0; i < (int)date.length(); i++) {
        if (date[i] == '-') {
            date.erase(i, 1);
            i--;
        }
    }
    return convertFromStringToInt(date);
}

string DateMethods::getCurrentDate() {
    stringstream ss;
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d");
    return ss.str();
}

string DateMethods::convertFromIntToString(int num) {
    ostringstream ss;
    ss << num;
    string str = ss.str();
    return str;
}

int DateMethods::convertFromStringToInt(string num) {
    int numInt;
    istringstream iss(num);
    iss >> numInt;
    return numInt;
}

string DateMethods::convertFromFloatToString(double num) {
    ostringstream ss;
    ss << num;
    string str = ss.str();
    return str;
}

float DateMethods::convertFromStringToFloat(string num) {
    float numInt;
    istringstream iss(num);
    iss >> numInt;
    return numInt;
}

int DateMethods::convertDateToInt(string date) {
    string year, month, day;
    year = date.substr(0,4);
    month = date.substr(5,2);
    day = date.substr(8,2);
    int dateAsInt = stoi(year + month + day);
    return dateAsInt;
}


