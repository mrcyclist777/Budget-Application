#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int id;
    string login;
    string password;
    string firstName;
    string lastName;

public:
    int getId();
    string getLogin();
    string getPassword();
    string getFirstName();
    string getLastName();

    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
};

#endif
