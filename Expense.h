#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
using namespace std;

class Expense {
private:
    string name;
    double amount;
    string category;

public:
    Expense(string name, double amount, string category);

    string getName() const;
    double getAmount() const;
    string getCategory() const;

    void setName(const string& newName);
    void setAmount(double newAmount);
    void setCategory(const string& newCategory);
};

#endif