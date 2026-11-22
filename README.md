# Expense Manager

This is a small C++ console project that I built to practice writing a more structured application instead of keeping everything in one file.

I started with a very simple expense tracker and gradually added more features, separated the code into multiple files, added file saving/loading, CMake, and basic tests.

## What the program can do

- Add a new expense
- Show all expenses
- Show the total amount spent
- Search expenses by category
- Edit an expense
- Delete an expense
- Save expenses to a text file
- Load saved expenses when the program starts
- Handle invalid user input

## Project structure

```text
Expense Manager v1/
├── main.cpp
├── Expense.h
├── Expense.cpp
├── ExpenseManager.h
├── ExpenseManager.cpp
├── tests.cpp
├── CMakeLists.txt
└── .gitignore
```

`Expense` represents one expense and stores its name, amount, and category.

`ExpenseManager` stores and manages all expenses.

`main.cpp` contains the console menu and user input.

`tests.cpp` contains basic tests for the main program logic.

## Building the project

I use CMake with MinGW.

From the project folder:

```bash
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
```

To run the application in PowerShell:

```powershell
.\expense_manager.exe
```

## Tests

The project currently has tests for:

- calculating the total
- checking whether the expense list is empty
- deleting expenses
- editing expenses

Tests can be run with:

```bash
ctest
```

Current result:

```text
100% tests passed, 0 tests failed
```

## Saving data

Expenses are saved in a simple text file.

Example:

```text
Coffee|3.5|Food
Train ticket|15|Transport
```

When the program starts, it reads the saved expenses from the file. When the program closes, it saves the current expenses again.

## What I practiced with this project

While building this project I practiced:

- C++ classes and objects
- encapsulation
- constructors
- getters and setters
- `std::vector`
- references
- `const`
- file input/output
- input validation
- editing and deleting vector elements
- separating `.h` and `.cpp` files
- CMake
- basic testing with CTest
- Git

## Next steps

I still want to improve the project by adding better error handling, more tests, sorting and statistics, and a cleaner separation between the user interface and the program logic.

The main goal of this project is to keep improving it step by step while learning how a real C++ project is structured.