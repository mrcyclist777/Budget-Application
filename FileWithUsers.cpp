#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;
    xml.ResetPos();
    if (!xml.Load(getFileName())) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    } else {
        xml.FindElem();
    }
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("FirstName", user.getFirstName());
    xml.AddElem("LastName", user.getLastName());
    xml.Save(getFileName());
    cout << endl << "User has been saved to file" << endl;
    Sleep(1000);
}

vector <User> FileWithUsers::loadUsersFromFile() {
    CMarkup xml;
    User user;
    vector <User> users;
    xml.Load(getFileName());
    if (!xml.Load(getFileName())) {
        cout << "File is empty." << endl;
        system("pause");
    } else {
        xml.FindElem("Users");
        xml.IntoElem();
        while (xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setId(DateMethods::convertFromStringDateToInt(xml.GetData()));
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.FindElem("FirstName");
            user.setFirstName(xml.GetData());
            xml.FindElem("LastName");
            user.setLastName(xml.GetData());
            users.push_back(user);
            xml.OutOfElem();
        }
    }
    return users;
}

void FileWithUsers::changeUserData(int LoginUserId, string newPassword) {
    CMarkup xml;
    xml.Load(getFileName());
    xml.FindElem("Users");
    xml.IntoElem();
    while(xml.FindElem("User")) {
        xml.IntoElem();
        xml.FindElem("UserId");
        if(DateMethods::convertFromStringToInt(xml.GetData()) == LoginUserId) {
            xml.FindElem("Login");
            xml.FindElem("Password");
            xml.SetData(newPassword);
        }
    }
    xml.Save(getFileName());
    cout << endl << "User password has been changed in the file" << endl;
    Sleep(1000);
}
