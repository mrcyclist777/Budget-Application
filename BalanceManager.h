#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"
#include "DateMethods.h"
#include "Transaction.h"

using namespace std;

class BalanceManager {
    const int LOGIN_USER_ID;
    FileWithExpenses fileWithExpenses;
    FileWithIncomes fileWithIncomes;
    vector <Transaction> incomes;
    vector <Transaction> expenses;
    int loadDate();
    Transaction getNewIncomeData();
    Transaction getNewExpenseData();
    void showBalance(int startDate, int endDate);

public:
    BalanceManager(string fileNameIncomes, string fileNameExpenses, int loginUserId):
        fileWithIncomes(fileNameIncomes), fileWithExpenses(fileNameExpenses), LOGIN_USER_ID(loginUserId) {
        incomes = fileWithIncomes.loadIncomesFromFile(LOGIN_USER_ID);
        expenses = fileWithExpenses.loadExpensesFromFile(LOGIN_USER_ID);
    }

    void addIncome();
    void addExpense();
    void sortAllTransactionsByDate(vector <Transaction> &transactions);
    void displayLastMonthBudget();
    void displayThisMonthBudget();
    void displayAnyTimeBudget();
};

#endif
