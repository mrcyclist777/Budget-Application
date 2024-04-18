#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(Transaction income) {
    CMarkup xml;
    xml.ResetPos();
    if (!xml.Load(getFileName())) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    } else {
        xml.FindElem();
    }
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", DateMethods::convertFromIntToString(income.getTransactionId() + 1));
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", DateMethods::convertFromIntToString(income.getDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", DateMethods::convertFromFloatToString(income.getAmount()));
    lastIncomeId++;
    xml.Save(getFileName());
    cout << endl << "Income has been saved to file" << endl;
    Sleep(1000);
}

vector <Transaction> FileWithIncomes::loadIncomesFromFile(int loggedUserId) {
    CMarkup xml;
    Transaction income;
    vector <Transaction> incomes;
    xml.Load(getFileName());
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Income")) {
        xml.IntoElem();
        xml.FindElem("UserId");
        if(stoi(xml.GetData()) == loggedUserId) {
            income.setUserId(loggedUserId);
            xml.FindElem("IncomeId");
            income.setTransactionId(stoi(xml.GetData()));
            xml.FindElem("Date");
            income.setDate(DateMethods::convertFromStringDateToInt(xml.GetData()));
            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.FindElem("Amount");
            income.setAmount(DateMethods::convertFromStringToFloat(xml.GetData()));
            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    xml.OutOfElem();
    return incomes;
}

int FileWithIncomes::getLastIncomeId() {
    return lastIncomeId;
}
