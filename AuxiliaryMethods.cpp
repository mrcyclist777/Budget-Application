#include "AuxiliaryMethods.h"

using namespace std;

string AuxiliaryMethods::loadLines() {
    string enter = "";
    getline(cin, enter);
    return enter;
}

int AuxiliaryMethods::loadIntegerNumber() {
    string input = "";
    int number = 0;
    while (true) {
        cin.sync();
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << endl;
        cout << "It's not a number. Enter again: " << endl;
    }
    return number;
}

char AuxiliaryMethods::loadChar() {
    string input = "";
    char sign  = {0};
    while (true) {
        getline(cin, input);
        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << endl;
        cout << "It's not a sign! Enter again: ";
    }
    return sign;
}

float AuxiliaryMethods::loadFloat () {
    string input = "";
    double number = 0;
    while (true) {
        cin.sync();
        getline(cin, input);

        if ( (number = atof(input.c_str())) )
            break;
        cout << endl;
        cout << "It's not a float number. Enter again: " << endl;
    }
    return number;
}

char AuxiliaryMethods::selectOptionsFromHomeMenu() {
    char choice;
    system("cls");
    cout << ">>> MAIN MENU <<<" << endl;
    cout << ">>> BUDGET APPLICATION <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit of the program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = loadChar();
    return choice;
}

char AuxiliaryMethods::selectOptionsFromUserMenu() {
    char choice;
    system("cls");
    cout << ">>> USER MENU <<<" << endl;
    cout << ">>> BUDGET APPLICATION <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance of this month" << endl;
    cout << "4. Balance of last month" << endl;
    cout << "5. Balance any time period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = loadChar();
    return choice;
}
