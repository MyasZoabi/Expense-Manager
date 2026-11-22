#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "ExpenseManager.h"

class ConsoleUI {
private:
    ExpenseManager& manager;

public:
    ConsoleUI(ExpenseManager& manager);

    void run();
};

#endif