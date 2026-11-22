#include "Expense.h"

Expense::Expense(string name, double amount, string category)
    : name(name), amount(amount), category(category) {}

string Expense::getName() const {
    return name;
}

double Expense::getAmount() const {
    return amount;
}

string Expense::getCategory() const {
    return category;
}

void Expense::setName(const string& newName) {
    name = newName;
}

void Expense::setAmount(double newAmount) {
    amount = newAmount;
}

void Expense::setCategory(const string& newCategory) {
    category = newCategory;
}