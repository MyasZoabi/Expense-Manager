cmake_minimum_required(VERSION 3.10)

project(ExpenseManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.11.0
)

FetchContent_MakeAvailable(Catch2)

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
target_link_libraries(
    tests
    PRIVATE Catch2::Catch2WithMain
)

enable_testing()
add_test(
    NAME ExpenseManagerTests
    COMMAND tests
)