#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <vector>
#include <string>
#include "Expense.h"

using namespace std;

class ExpenseManager {
private:
    vector<Expense> expenses;

public:
    void addExpense(const Expense& expense);

    void showExpenses() const;

    double getTotal() const;

    void showByCategory(const string& category) const;

    bool deleteExpense(int index);

    bool isEmpty() const;

    bool editExpense(
        int index,
        const string& newName,
        double newAmount,
        const string& newCategory
);
void saveToFile(const string& filename) const;
void loadFromFile(const string& filename);
int getExpenseCount() const;
const Expense& getExpense(int index) const;
};

#endif