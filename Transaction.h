#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction {
    int transactionId;
    int userId;
    int date;
    string item;
    double amount;

public:
    int getTransactionId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

    void setTransactionId(int newTransactionId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    bool operator < (Transaction &str) {
        return (date < str.date);
    }
};

#endif
