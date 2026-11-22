#include "ConsoleUI.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

ConsoleUI::ConsoleUI(ExpenseManager& manager)
    : manager(manager) {
}

void ConsoleUI::run() {
    string name;
    double amount;
    string category;
    int choice = 0;

while (choice != 8) {

    cout << "\n--- Expense Manager ---\n";
    cout << "1. Add Expense\n";
    cout << "2. Show Expenses\n";
    cout << "3. Show Total\n";
    cout << "4. Show Expenses by Category\n";
    cout << "5. Delete Expense\n";
    cout << "6. Edit Expense\n";
    cout << "7. Sort Expenses by Amount\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";

    cin >> choice;
if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid choice!\n";
    continue;
}
// 1. Add Expense
if (choice == 1) {
 cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter expense name: ";
    getline(cin, name);

    cout << "Enter amount: ";
    cin >> amount;

// Validate amount
if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Invalid amount!\n";
    continue;
}
cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Enter category: ";
        getline(cin, category);

Expense expense(name, amount, category);
if (manager.addExpense(expense)) {
    cout << "Expense added successfully!\n";
}
else {
    cout << "Invalid expense amount.\n";
}
}  

// 2. Show Expenses
else if (choice == 2) {
    manager.showExpenses();
}
// 3. Show Total
else if (choice == 3) {
    cout << "Total: $" << manager.getTotal()<< "\n";
}      
// 4. Search by Category
else if (choice == 4) {
cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter category to search: ";
    getline(cin, category);
    manager.showByCategory(category);
}  
// 5. Expense Delete choice
else if (choice == 5) {
if (manager.isEmpty()) {
    cout << "No expenses to delete.\n";
    continue;
}
    int index;

    manager.showExpenses();

    cout << "Enter expense number to delete: ";
    cin >> index;

if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid number!\n";
    continue;
}
if (manager.deleteExpense(index)) {
    cout << "Expense deleted successfully!\n";
}
else {
    cout << "Invalid expense number.\n";
}
}
// 6. Edit Expense choice
else if (choice == 6){
if (manager.isEmpty()) {
    cout << "No expenses to edit.\n";
    continue;
}  
    int index;
    manager.showExpenses();
    cout << "Which Number Would you like to edit?\n";
    cin >> index;

if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid number!\n";
    continue;
}
cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter new name: ";
    getline(cin, name);
    cout << "Enter new amount: ";
    cin >> amount;
if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid amount!\n";
    continue;
}
if (amount <= 0) {
    cout << "Amount must be greater than 0.\n";
    continue;
}
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Enter new category: ";
getline(cin, category);

if (manager.editExpense(index, name, amount, category)) {
    cout << "Expense updated successfully!\n";
}
else {
    cout << "Invalid expense number.\n";
}
}
else if (choice == 7) {
    if (manager.isEmpty()) {
        cout << "No expenses to sort.\n";
        continue;
}

int sortChoice;

    cout << "1. Lowest to highest\n";
    cout << "2. Highest to lowest\n";
    cout << "Choose sorting order: ";

    cin >> sortChoice;

if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice!\n";
        continue;
}

if (sortChoice == 1) {
        manager.sortByAmountAscending();
        cout << "Expenses sorted from lowest to highest.\n";
        manager.showExpenses();
}
else if (sortChoice == 2) {
        manager.sortByAmountDescending();
        cout << "Expenses sorted from highest to lowest.\n";
        manager.showExpenses();
}
else {
        cout << "Invalid sorting option.\n";
}
}
// 8. Exit
else if (choice == 8) {
    cout << "Goodbye!\n";
}
// Invalid number
else {
    cout << "Invalid choice!\n";
}
}

    return ;
}      

