#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

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

class FileWithIncomes :public File {
    int lastIncomeId = 0;

public:
    FileWithIncomes (string fileNameIncomes) :File(fileNameIncomes) {}

    void addIncomeToFile(Transaction income);
    vector <Transaction> loadIncomesFromFile(int loggedUserId);
    int getLastIncomeId();
};

#endif
