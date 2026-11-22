#include <iostream>
#include "ExpenseManager.h"
#include <cstdio>
using namespace std;

int passed = 0;
int failed = 0;

// General pattern for all Tests (Testing Framework)
void check(bool condition, const string& testName) {
if (condition) {
    cout << "Test passed: " << testName << "\n";
    passed++;
}
else {
    cout << "Test failed: " << testName << "\n";
    failed++;
}
}

int main() {
// Add Expense Test
    ExpenseManager manager;
    Expense expense1("Coffee", 3.50, "Food");
    Expense expense2("Train", 15.00, "Transport");

    manager.addExpense(expense1);
    manager.addExpense(expense2);
    check(manager.getTotal() == 18.50, "getTotal()");

// Empty Test
ExpenseManager emptyManager;
check(emptyManager.isEmpty(), "isEmpty()");

// Delete Expense Test
ExpenseManager deleteManager;
deleteManager.addExpense(Expense("Coffee", 3.50, "Food"));
deleteManager.addExpense(Expense("Train", 15.00, "Transport"));

deleteManager.deleteExpense(1);

check(
    deleteManager.getExpenseCount() == 1,
    "deleteExpense()"
);

// Edit Expense Test
ExpenseManager editManager;
editManager.addExpense(
    Expense("Coffee", 3.50, "Food")
);

editManager.editExpense(
    1,
    "Cappuccino",
    4.50,
    "Cafe"
);

const Expense& expense = editManager.getExpense(0);

check(
    expense.getName() == "Cappuccino" &&
    expense.getAmount() == 4.50 &&
    expense.getCategory() == "Cafe",
    "editExpense() updates all fields"
);
// passed and failed Tests count 
cout << "\nTest Summary: \n";
cout << "Passed: " << passed << "\n";
cout << "Failed: " << failed << "\n";
 
if (failed > 0) {
    return 1;
}

ExpenseManager invalidDeleteManager;

invalidDeleteManager.addExpense(
    Expense("Coffee", 3.50, "Food")
);

bool deleted = invalidDeleteManager.deleteExpense(5);

check(
    deleted == false &&
    invalidDeleteManager.getExpenseCount() == 1,
    "deleteExpense() rejects invalid index"
);

ExpenseManager invalidEditManager;

invalidEditManager.addExpense(
    Expense("Coffee", 3.50, "Food")
);

bool edited = invalidEditManager.editExpense(
    5,
    "Tea",
    4.00,
    "Drinks"
);

check(
    edited == false &&
    invalidEditManager.getExpense(0).getName() == "Coffee",
    "editExpense() rejects invalid index"
);

ExpenseManager saveManager;

saveManager.addExpense(
    Expense("Coffee", 3.50, "Food")
);

saveManager.addExpense(
    Expense("Train", 15.00, "Transport")
);

saveManager.saveToFile("test_expenses.txt");
   
ExpenseManager loadManager;
loadManager.loadFromFile("test_expenses.txt");

check(
    loadManager.getExpenseCount() == 2,
    "loadFromFile() restores expense count"
);

check(
    loadManager.getExpense(0).getName() == "Coffee" &&
    loadManager.getExpense(0).getAmount() == 3.50 &&
    loadManager.getExpense(0).getCategory() == "Food",
    "save/load preserves first expense"
);

check(
    loadManager.getExpense(1).getName() == "Train" &&
    loadManager.getExpense(1).getAmount() == 15.00 &&
    loadManager.getExpense(1).getCategory() == "Transport",
    "save/load preserves second expense"
);

remove("test_expenses.txt");

return 0;
}