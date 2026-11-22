#include "ExpenseManager.h"
#include "ConsoleUI.h"

int main() {

    ExpenseManager manager;

    manager.loadFromFile("expenses.txt");

    ConsoleUI ui(manager);

    ui.run();

    manager.saveToFile("expenses.txt");

    return 0;
}