cmake_minimum_required(VERSION 3.10)

project(ExpenseManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    expense_manager
    src/main.cpp
    src/Expense.cpp
    src/ExpenseManager.cpp
    src/ConsoleUI.cpp
)

add_executable(
    tests
    tests/tests.cpp
    src/Expense.cpp
    src/ExpenseManager.cpp
)

enable_testing()

add_test(
    NAME ExpenseManagerTests
    COMMAND tests
)