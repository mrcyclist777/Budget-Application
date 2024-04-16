#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Transaction expense) {
    CMarkup xml;
    xml.ResetPos();
    if (!xml.Load(getFileName())) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    } else {
        xml.FindElem();
    }
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId",DateMethods::convertFromIntToString(expense.getTransactionId()));
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", DateMethods::convertFromIntToString(expense.getDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", DateMethods::convertFromFloatToString(expense.getAmount()));
    lastExpenseId++;
    xml.Save(getFileName());
    cout << endl << "Expense has been saved to file" << endl;
    Sleep(1000);
}

vector <Transaction> FileWithExpenses::loadExpensesFromFile(int loggedUserId) {
    CMarkup xml;
    Transaction expense;
    vector <Transaction> expenses;
    xml.Load(getFileName());
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Expense")) {
        xml.IntoElem();
        xml.FindElem("UserId");
        if(stoi(xml.GetData()) == loggedUserId) {
            expense.setUserId(loggedUserId);
            xml.FindElem("ExpenseId");
            expense.setTransactionId(stoi(xml.GetData()));
            xml.FindElem("Date");
            expense.setDate(DateMethods::convertFromStringDateToInt(xml.GetData()));
            xml.FindElem("Item");
            expense.setItem(xml.GetData());
            xml.FindElem("Amount");
            expense.setAmount(DateMethods::convertFromStringToFloat(xml.GetData()));
            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    xml.OutOfElem();
    return expenses;
}

int FileWithExpenses::getLastExpenseId() {
    return lastExpenseId;
}

