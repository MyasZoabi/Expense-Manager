#include "ExpenseManager.h"
#include <iostream>
#include <fstream>
using namespace std;

void ExpenseManager::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

void ExpenseManager::showExpenses() const {
    if (expenses.empty()) {
        cout << "No expenses found.\n";
        return;
}

    for (int i = 0; i < expenses.size(); i++) {
        cout << i + 1 << ". "
             << expenses[i].getName() << " | $"
             << expenses[i].getAmount() << " | "
             << expenses[i].getCategory() << "\n";
}
}

double ExpenseManager::getTotal() const {
    double total = 0;

    for (const Expense& expense : expenses) {
        total += expense.getAmount();
}

    return total;
}

void ExpenseManager::showByCategory(const string& category) const {
    bool found = false;

    for (const Expense& expense : expenses) {
        if (expense.getCategory() == category) {
            cout << expense.getName() << " | $"
                 << expense.getAmount() << " | "
                 << expense.getCategory() << "\n";

            found = true;
}
}

    if (!found) {
        cout << "No expenses found in this category.\n";
}
}

void ExpenseManager::deleteExpense(int index) {
    if (index < 1 || index > expenses.size()) {
        cout << "Invalid expense number.\n";
        return;
}

    expenses.erase(expenses.begin() + (index - 1));

    cout << "Expense deleted successfully!\n";
}

bool ExpenseManager::isEmpty() const {
    return expenses.empty();
}

void ExpenseManager::editExpense(
    int index,
    const string& newName,
    double newAmount,
    const string& newCategory
) {
    if (index < 1 || index > expenses.size()) {
        cout << "Invalid expense number.\n";
        return;
}

    Expense& expense = expenses[index - 1];

    expense.setName(newName);
    expense.setAmount(newAmount);
    expense.setCategory(newCategory);

    cout << "Expense updated successfully!\n";
}
void ExpenseManager::saveToFile(const string& filename) const {
    ofstream file(filename);

    for (const Expense& expense : expenses) {
        file << expense.getName() << "|"
             << expense.getAmount() << "|"
             << expense.getCategory() << "\n";
}
}
void ExpenseManager::loadFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        return;
}
    string name;
    string amountText;
    string category;

    while (getline(file, name, '|')) {
        getline(file, amountText, '|');
        getline(file, category);

        double amount = stod(amountText);

        Expense expense(name, amount, category);
        expenses.push_back(expense);
}
}
int ExpenseManager::getExpenseCount() const {
    return expenses.size();
}
const Expense& ExpenseManager::getExpense(int index) const {
    return expenses[index];
}