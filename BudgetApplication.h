#ifndef BUDGETAPPLICATION_H
#define BUDGETAPPLICATION_H

#include <iostream>
#include "BalanceManager.h"
#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "DateMethods.h"

using namespace std;

class BudgetApplication {
    BalanceManager *balanceManager;
    UserManager userManager;
    string const FILE_NAME_WITH_INCOMES;
    string const FILE_NAME_WITH_EXPENSES;

public:
    BudgetApplication (string userFileName, string incomesFileName, string expensesFileName) :
        userManager(userFileName),
        FILE_NAME_WITH_INCOMES(incomesFileName),
        FILE_NAME_WITH_EXPENSES(expensesFileName) {
        balanceManager = NULL;
    };

    ~BudgetApplication() {
        delete balanceManager;
        balanceManager = NULL;
    };

    void userRegister();
    void userLogin();
    void menu();
    void changeLoggedUserPassword();
    void userLogout();
    void addIncome();
    void addExpense();
    void displayLastMonthBudget();
    void displayThisMonthBudget();
    void displayAnyTimeBudget();
    bool ifTheUserIsLoggedIn();
};

#endif
