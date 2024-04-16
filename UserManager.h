#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager {
    int loggedUserId = 0;
    vector <User> users;
    FileWithUsers fileWithUsers;
    User enterRegisterData();
    int getNewUserId();
    bool ifTheLoginExist(const string &login);

public:
    UserManager(string nameFile) : fileWithUsers(nameFile) {
        loggedUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };

    void userRegister();
    void userLogin();
    void userLogout();
    void changeLoggedUserPassword();
    bool ifTheUserLoggedIn();
    int getLoggedUserId();
    int getIdForNewUser();
};

#endif
