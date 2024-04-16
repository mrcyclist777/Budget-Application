#include "BalanceManager.h"

void BalanceManager::addIncome() {
    system("cls");
    cout << endl << "Add new income: " << endl;
    Transaction income;
    income = getNewIncomeData();
    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);
    sortAllTransactionsByDate(incomes);
    cout << endl << "New income added." << endl;
    system("pause");
}

void BalanceManager::addExpense() {
    system("cls");
    cout << endl << "Add new expense: " << endl;
    Transaction expense ;
    expense = getNewExpenseData();
    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);
    sortAllTransactionsByDate(expenses);
    cout << endl << "New expense added." << endl;
    system("pause");
}

int BalanceManager::loadDate() {
    string date;
    while(true) {
        date = AuxiliaryMethods::loadLines();
        if (DateMethods::validateDate(date)) {
            return DateMethods::convertDateToInt(date);
        } else {
            cout << "Entered date is incorrect. Enter date in YYYY-MM-DD format again. " << endl;
        }
    }
}

Transaction BalanceManager::getNewIncomeData() {
    Transaction income;
    income.setTransactionId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGIN_USER_ID);
    char choice;
    bool menuChoose = true;
    string incomeDate, incomeAmount, newDate;
    system("cls");
    cout << "Do you add income from today ? : " << endl;
    cout << "Confirm with press 't': / other date press 'd' " << endl;
    while (menuChoose) {
        choice = AuxiliaryMethods::loadChar();
        switch (choice) {
        case 't':
            cout << endl;
            incomeDate = DateMethods::getCurrentDate();
            income.setDate(DateMethods::convertFromStringDateToInt(incomeDate));
            cout << endl << "Today date has been saved. " << endl;
            cout << endl;
            menuChoose = false;
            break;
        case 'd':
            cout << endl;
            cout << "Enter date in (YYYY-MM-DD) method: " << endl;
            newDate = AuxiliaryMethods::loadLines();
            while(!DateMethods::validateDate(newDate)) {
                cout << "Enter date in (YYYY-MM-DD) method: ";
                newDate = AuxiliaryMethods::loadLines();
            }
            income.setDate(DateMethods::convertDateToInt(newDate));
            menuChoose = false;
            cout << endl << "Date has been saved. " << endl;
            cout << endl;
            break;
        default:
            cout << "Please choose only 't' or 'd' characters. Enter again: " << endl;
            system("pause");
            break;
        }
    }
    cout << "Press source of income: " << endl;
    income.setItem(AuxiliaryMethods::loadLines());
    cout << endl;
    cout << "Press value of income: " << endl;
    income.setAmount(AuxiliaryMethods::loadFloat());
    return income;
}

Transaction BalanceManager::getNewExpenseData() {
    Transaction expense;
    expense.setTransactionId(fileWithExpenses.getLastExpenseId() + 1);
    expense.setUserId(LOGIN_USER_ID);
    char choice;
    bool menuChoose = true;
    string expenseDate, expenseAmount, newDate;
    system("cls");
    cout << "Do you add expanse from today ? : " << endl;
    cout << "Confirm with press 't': / other date press 'd' " << endl;
    while (menuChoose) {
        choice = AuxiliaryMethods::loadChar();
        switch (choice) {
        case 't':
            cout << endl;
            expenseDate = DateMethods::getCurrentDate();
            expense.setDate(DateMethods::convertFromStringDateToInt(expenseDate));
            cout << endl << "Today date has been saved. " << endl;
            cout << endl;
            menuChoose = false;
            break;
        case 'd':
            cout << endl;
            cout << "Enter date in (YYYY-MM-DD) method: " << endl;
            newDate = AuxiliaryMethods::loadLines();
            while(!DateMethods::validateDate(newDate)) {
                cout << "Enter date in (YYYY-MM-DD) method: ";
                newDate = AuxiliaryMethods::loadLines();
            }
            expense.setDate(DateMethods::convertDateToInt(newDate));
            menuChoose = false;
            cout << endl << "Date has been saved. " << endl;
            cout << endl;
            break;
        default:
            cout << "Please choose only 't' or 'd' characters. Enter again: " << endl;
            system("pause");
            break;
        }
    }
    cout << "Press source of expense: " << endl;
    expense.setItem(AuxiliaryMethods::loadLines());
    cout << endl;
    cout << "Press value of expense: " << endl;
    expense.setAmount(AuxiliaryMethods::loadFloat());
    return expense;
}

void BalanceManager::sortAllTransactionsByDate(vector <Transaction> &transactions) {
    if(transactions.empty()) {
        return;
    } else {
        sort(transactions.begin( ), transactions.end( ), [ ]( auto& lhs, auto& rhs ) {
            return lhs.getDate() < rhs.getDate();
        });
    }
}

void BalanceManager::showBalance(int startDate, int endDate) {
    float allOfIncomes = 0;
    float allOfExpenses = 0;
    int incomeNum = 1;
    int expenseNum = 1;
    sortAllTransactionsByDate(incomes);
    sortAllTransactionsByDate(expenses);
    system("cls");
    cout << "List of incomes" << endl;
    cout << " ---------- "<< endl;
    for (Transaction income : incomes) {
        if (income.getDate() >= startDate && income.getDate() <= endDate) {
            cout << "Income number: " << incomeNum << endl;
            cout << "Date: " << DateMethods::convertFromIntDateToStringWithDashes(income.getDate()) << endl;
            cout << "Item: " << income.getItem() << endl;
            cout << "Amount: " << income.getAmount() << endl;
            cout << endl;
            allOfIncomes += income.getAmount();
            incomeNum++;
        }
    }
    cout << "List of expenses" << endl;
    cout << " ---------- "<< endl;
    for (Transaction expense : expenses) {
        if (expense.getDate() >= startDate && expense.getDate() <= endDate) {
            cout << "Expense number: " << expenseNum << endl;
            cout << "Date: " << DateMethods::convertFromIntDateToStringWithDashes(expense.getDate()) << endl;
            cout << "Item: " << expense.getItem() << endl;
            cout << "Amount: " << expense.getAmount() << endl;
            cout << endl;
            allOfExpenses += expense.getAmount();
            expenseNum++;
        }
    }
    cout << "Incomes: " << allOfIncomes << endl;
    cout << "Expenses: " << allOfExpenses << endl;
    cout << "Balance: " << allOfIncomes - allOfExpenses << endl;
}

void BalanceManager::displayLastMonthBudget() {
    system("cls");
    string thisDate = DateMethods::getCurrentDate();
    int thisYear = DateMethods::convertFromStringToInt(thisDate.substr(0, 4));
    int thisMonth = DateMethods::convertFromStringToInt(thisDate.substr(5, 2));
    int maxDaysOfLastMonth = DateMethods::numberOfDaysInMonth();
    int lastMonth, lastYearOfMonth;
    if (thisMonth == 1) {
        lastYearOfMonth = thisYear - 1;
        lastMonth = 12;
    } else {
        lastYearOfMonth = thisYear;
        lastMonth = thisMonth - 1;
    }
    int startDate = thisYear * 10000 + thisMonth * 100 + 1;
    int endDate = startDate + maxDaysOfLastMonth;
    showBalance(startDate, endDate);
    system("pause");
}

void BalanceManager::displayThisMonthBudget() {
    system("cls");
    string thisDate = DateMethods::getCurrentDate();
    int thisYear = DateMethods::convertFromStringToInt(thisDate.substr(0, 4));
    int thisMonth = DateMethods::convertFromStringToInt(thisDate.substr(5, 2));
    int maxDaysOfThisMonth = DateMethods::numberOfDaysInMonth();
    int startDate = thisYear * 10000 + thisMonth * 100 + 1;
    int endDate = startDate + maxDaysOfThisMonth;
    showBalance(startDate, endDate);
    system("pause");
}

void BalanceManager::displayAnyTimeBudget() {
    system("cls");
    int startDate, endDate;
    cout << "Enter start date (YYYY-MM-DD) of balance to display: " << endl;
    startDate = loadDate();
    cout << endl;
    cout << "Enter end date (YYYY-MM-DD) of balance to display: " << endl;
    endDate = loadDate();
    if (endDate >= startDate) {
        showBalance(startDate, endDate);
        system("pause");
    } else {
        cout << endl << "End date is smaller then start date. Enter again with correct dates. " << endl;
        system("pause");
    }
}
