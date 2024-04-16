#include <iostream>
#include "BudgetApplication.h"

using namespace std;

int main() {
    BudgetApplication budgetApplication ("users.xml", "incomes.xml", "expenses.xml");
    budgetApplication.menu();
    return 0;
}
