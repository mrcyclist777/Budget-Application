#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

#include "File.h"
#include "Markup.h"
#include "Transaction.h"
#include "AuxiliaryMethods.h"
#include "DateMethods.h"

using namespace std;

class FileWithExpenses :public File {
    int lastExpenseId = 0;

public:
    FileWithExpenses(string fileNameExpenses) : File(fileNameExpenses) {}

    void addExpenseToFile(Transaction expense);
    vector <Transaction> loadExpensesFromFile(int loggedUserId);
    int getLastExpenseId();
};

#endif
