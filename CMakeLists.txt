cmake_minimum_required(VERSION 3.10)

project(ExpenseManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main application
add_executable(
    expense_manager
    main.cpp
    Expense.cpp
    ExpenseManager.cpp
)
# Tests
add_executable(
    tests
    tests.cpp
    Expense.cpp
    ExpenseManager.cpp
)

enable_testing()
add_test(
    NAME ExpenseManagerTests
    COMMAND tests
)