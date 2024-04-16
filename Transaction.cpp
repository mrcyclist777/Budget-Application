#include "Transaction.h"

int Transaction::getTransactionId() {
    return transactionId;
}

int Transaction::getUserId() {
    return userId;
}

int Transaction::getDate() {
    return date;
}

string Transaction::getItem() {
    return item;
}

double Transaction::getAmount() {
    return amount;
}

void Transaction::setTransactionId(int newTransactionId) {
    transactionId = newTransactionId;
}

void Transaction::setUserId(int newUserId) {
    userId = newUserId;
}

void Transaction::setDate(int newDate) {
    date = newDate;
}

void Transaction::setItem(string newItem) {
    item = newItem;
}

void Transaction::setAmount(double newAmount) {
    amount = newAmount;
}

