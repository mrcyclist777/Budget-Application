#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>

#include "File.h"
#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"
#include "DateMethods.h"
#include <windows.h>

using namespace std;

class FileWithUsers :public File {

public:
    FileWithUsers (string fileNameUsers) :File(fileNameUsers) {}

    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void changeUserData(int loggedUserId, string newPassword);
};

#endif



