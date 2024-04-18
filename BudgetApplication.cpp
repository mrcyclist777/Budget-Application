#include "BudgetApplication.h"

void BudgetApplication::menu() {
    char choice;
    while (true) {
        if (!userManager.ifTheUserLoggedIn()) {
            choice = AuxiliaryMethods::selectOptionsFromHomeMenu();
            switch (choice) {
            case '1':
                userRegister();
                break;
            case '2':
                userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Character not used. Enter again: " << endl << endl;
                system("pause");
                break;
            }
        } else if (userManager.getLoggedUserId() > 0) {
            choice = AuxiliaryMethods::selectOptionsFromUserMenu();
            switch (choice) {
            case '1':
                addIncome();
                break;
            case '2':
                addExpense();
                break;
            case '3':
                displayThisMonthBudget();
                break;
            case '4':
                displayLastMonthBudget();
                break;
            case '5':
                displayAnyTimeBudget();
                break;
            case '6':
                changeLoggedUserPassword();
                break;
            case '7':
                userLogout();
                break;
            default:
                cout << endl << "Character not used. Enter again: " << endl << endl;
                system("pause");
                break;
            }
        }
    }
}

void BudgetApplication::userRegister() {
    userManager.userRegister();
}

void BudgetApplication::userLogin() {
    userManager.userLogin();
    if (userManager.ifTheUserLoggedIn()) {
        balanceManager = new BalanceManager(FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES, userManager.getLoggedUserId());
    }
}

void BudgetApplication::addIncome() {
    balanceManager -> addIncome();
}

void BudgetApplication::addExpense() {
    balanceManager -> addExpense();
}

void BudgetApplication::changeLoggedUserPassword() {
    userManager.changeLoggedUserPassword();
}

void BudgetApplication::userLogout() {
    userManager.userLogout();
    delete balanceManager;
    balanceManager = NULL;
}

void BudgetApplication::displayLastMonthBudget() {
    balanceManager->displayLastMonthBudget();
}

void BudgetApplication::displayThisMonthBudget() {
    balanceManager->displayThisMonthBudget();
}

void BudgetApplication::displayAnyTimeBudget() {
    balanceManager->displayAnyTimeBudget();
}
