# Expense Manager

This is a C++ console application I built to practice object-oriented programming and a more realistic software development workflow.

The project started as a simple one-file expense tracker and was gradually refactored into a multi-file application with separate UI and business logic, file persistence, automated tests, CMake, CTest, Git, GitHub, and GitHub Actions.

## Features

- Add expenses
- Show all expenses
- Calculate total expenses
- Search expenses by category
- Edit expenses
- Delete expenses
- Sort expenses by amount
  - lowest to highest
  - highest to lowest
- Show expense statistics
  - total
  - average
  - highest expense
  - lowest expense
- Validate user input
- Reject invalid or non-positive amounts
- Save expenses to a text file
- Load saved expenses when the application starts
- Skip malformed file entries instead of crashing

## Project Structure

```text
Expense Manager v1/
├── include/
│   ├── Expense.h
│   ├── ExpenseManager.h
│   └── ConsoleUI.h
│
├── src/
│   ├── Expense.cpp
│   ├── ExpenseManager.cpp
│   ├── ConsoleUI.cpp
│   └── main.cpp
│
├── tests/
│   └── tests.cpp
│
├── .github/
│   └── workflows/
│       └── cmake.yml
│
├── CMakeLists.txt
├── README.md
└── .gitignore
```

## Architecture

The project is separated into three main parts.

### Expense

Represents one expense and stores:

- name
- amount
- category

### ExpenseManager

Handles the main application logic, including:

- storing expenses
- adding, editing, and deleting expenses
- calculating totals and averages
- finding the highest and lowest expenses
- sorting expenses
- file persistence
- validation of business rules

### ConsoleUI

Handles user interaction:

- displaying menus
- reading input
- validating console input
- displaying results and messages

`main.cpp` is kept small and is responsible for starting the application, loading saved data, running the UI, and saving data when the program exits.

## Building the Project

The project uses CMake and C++17.

From the project directory:

```bash
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
```

The application can then be run from the build directory.

On Windows PowerShell:

```powershell
.\expense_manager.exe
```

## Testing

The project uses Catch2 for automated testing and CTest as the test runner.

Run the tests with:

```bash
ctest --output-on-failure
```

The current test suite covers:

- total calculation
- empty manager state
- adding expenses
- deleting expenses
- editing expenses
- invalid indexes
- invalid amounts
- sorting ascending and descending
- average calculation
- highest and lowest expenses
- file saving and loading
- malformed file data
- exception behavior for invalid access

## File Persistence

Expenses are stored in a simple text format:

```text
Coffee|3.5|Food
Train ticket|15|Transport
```

Each line contains:

```text
name | amount | category
```

When the application starts, saved expenses are loaded automatically.

When the application exits, the current data is saved again.

Malformed lines are skipped so that invalid file data does not crash the program.

## Continuous Integration

The repository uses GitHub Actions.

Every push to `main` automatically:

- checks out the repository
- configures CMake
- builds the project
- runs the automated tests

This helps make sure new changes do not break the existing application.

## Technologies and Concepts

This project helped me practice:

- C++17
- object-oriented programming
- classes and objects
- encapsulation
- composition
- constructors
- getters and setters
- `std::vector`
- references
- `const` correctness
- STL algorithms
- lambdas
- `std::sort`
- `std::min_element`
- `std::max_element`
- exception handling
- file I/O
- input validation
- multi-file project structure
- CMake
- Catch2
- CTest
- Git
- GitHub
- GitHub Actions / CI

## What I Learned

The main goal of this project was not only to add features, but to gradually improve the structure of the application.

During the project I moved from a single-file program to a more maintainable architecture, introduced automated testing, separated user interface logic from application logic, added persistence, and started using tools commonly found in a real C++ development workflow.

## Possible Future Improvements

Some ideas I may explore later:

- stronger separation between data and presentation
- more advanced statistics
- category summaries
- date support for expenses
- CSV or JSON storage
- import/export
- improved error reporting
- a graphical interface

## Status

The main functionality is implemented and covered by automated tests. The project is currently in a stable portfolio-ready state and may continue to evolve as I learn more C++ and software engineering.