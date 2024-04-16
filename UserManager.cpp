#include "UserManager.h"

using namespace std;

User UserManager::enterRegisterData() {
    User user;
    string login = "", password = "";
    user.setId(getIdForNewUser());
    cout << "Enter first name: ";
    user.setFirstName(AuxiliaryMethods::loadLines());
    cout << "Enter last name: ";
    user.setLastName(AuxiliaryMethods::loadLines());
    do {
        cout << "Enter login: ";
        login = AuxiliaryMethods::loadLines();
        user.setLogin(login);
    } while (ifTheLoginExist(user.getLogin()) == true);
    cout << "Enter password: ";
    password = AuxiliaryMethods::loadLines();
    user.setPassword(password);
    return user;
}

void UserManager::userRegister() {
    system("cls");
    cout << " >>> ADD NEW USER <<<" << endl << endl;
    User user = enterRegisterData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    cout << endl << "New account has been created" << endl;
    Sleep(1000);
}

void UserManager::userLogin() {
    system("cls");
    cout << " >>> LOGIN PANEL <<<" << endl << endl;
    string login = "", password = "";
    cout << "Enter login: ";
    login = AuxiliaryMethods::loadLines();
    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if(itr -> getLogin() == login) {
            for(int numAttempt = 3; numAttempt > 0; numAttempt--) {
                cout << "Enter password: " << endl;
                cout << "Left: " << numAttempt << " attempts." << endl;
                password = AuxiliaryMethods::loadLines();
                if (itr -> getPassword() == password) {
                    cout << endl << "Logged in. Go to User Menu!" << endl;
                    Sleep(1000);
                    loggedUserId = itr -> getId();
                    return;
                }
            }
            cout << endl << "You wrote your password 3 times incorrectly. Try again." << endl;
            system("pause");
            loggedUserId = 0;
            return;
        }
        itr++;
    }
    cout << endl << "User with that login doesn't exist" << endl;
    cout << endl;
    system("pause");
    loggedUserId = 0;
    return;
}

void UserManager::userLogout() {
    cout << endl << ">>> LOGOUT <<<" << endl;
    loggedUserId = 0;
    Sleep(1000);
}

void UserManager::changeLoggedUserPassword() {
    string newPassword = "";
    cout << endl << "Write new password: ";
    newPassword = AuxiliaryMethods::loadLines();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if(itr -> getId() == loggedUserId) {
            itr -> setPassword(newPassword);
            cout << endl << "Password has been changed" << endl;
            Sleep(1000);
        }
    }
    fileWithUsers.changeUserData(loggedUserId, newPassword);
}

bool UserManager::ifTheUserLoggedIn() {
    if(loggedUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedUserId() {
    return loggedUserId;
}

bool UserManager::ifTheLoginExist(const string &login) {
    for (auto itr = users.begin(); itr != users.end(); itr++) {
        if(itr -> getLogin() == login) {
            cout << endl << "Username is taken. Enter another name. " << endl;
            cout << endl;
            return true;
        }
    }
    return false;
}

int UserManager::getIdForNewUser() {
    if (users.empty() == true) {
        return 1;
    } else {
        return users.back().getId() + 1;
    }
}
