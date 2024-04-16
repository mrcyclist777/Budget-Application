#include "User.h"

int User::getId() {
    return id;
}

string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}

string User::getFirstName() {
    return firstName;
}

string User::getLastName() {
    return lastName;
}

void User::setId(int newId) {
    if (id >= 0)
        id = newId;
}

void User::setLogin(string newLogin) {
    login = newLogin;
}

void User::setPassword(string newPassword) {
    password = newPassword;
}

void User::setFirstName(string newFirstName) {
    firstName = newFirstName;
}

void User::setLastName(string newLastName) {
    lastName = newLastName;
}
