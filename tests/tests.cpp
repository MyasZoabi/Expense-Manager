#include <catch2/catch_test_macros.hpp>

#include "ExpenseManager.h"

#include <fstream>
#include <cstdio>
#include <stdexcept>


TEST_CASE("ExpenseManager calculates total") {
    ExpenseManager manager;

    manager.addExpense(
        Expense("Coffee", 3.50, "Food")
    );

    manager.addExpense(
        Expense("Train", 15.00, "Transport")
    );

    REQUIRE(manager.getTotal() == 18.50);
}


TEST_CASE("New ExpenseManager is empty") {
    ExpenseManager manager;

    REQUIRE(manager.isEmpty());
}


TEST_CASE("ExpenseManager deletes an expense") {
    ExpenseManager manager;

    manager.addExpense(
        Expense("Coffee", 3.50, "Food")
    );

    manager.addExpense(
        Expense("Train", 15.00, "Transport")
    );

    REQUIRE(manager.deleteExpense(1));
    REQUIRE(manager.getExpenseCount() == 1);
}


TEST_CASE("deleteExpense rejects invalid index") {
    ExpenseManager manager;

    manager.addExpense(
        Expense("Coffee", 3.50, "Food")
    );

    REQUIRE_FALSE(manager.deleteExpense(5));
    REQUIRE(manager.getExpenseCount() == 1);
}


TEST_CASE("editExpense updates all fields") {
    ExpenseManager manager;

    manager.addExpense(
        Expense("Coffee", 3.50, "Food")
    );

    REQUIRE(
        manager.editExpense(
            1,
            "Cappuccino",
            4.50,
            "Cafe"
        )
    );

    const Expense& expense = manager.getExpense(0);

    REQUIRE(expense.getName() == "Cappuccino");
    REQUIRE(expense.getAmount() == 4.50);
    REQUIRE(expense.getCategory() == "Cafe");
}


TEST_CASE("editExpense rejects invalid index") {
    ExpenseManager manager;

    manager.addExpense(
        Expense("Coffee", 3.50, "Food")
    );

    REQUIRE_FALSE(
        manager.editExpense(
            5,
            "Tea",
            4.00,
            "Drinks"
        )
    );

    REQUIRE(
        manager.getExpense(0).getName() == "Coffee"
    );
}


TEST_CASE("ExpenseManager saves and loads expenses") {
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


    REQUIRE(loadManager.getExpenseCount() == 2);

    REQUIRE(
        loadManager.getExpense(0).getName() == "Coffee"
    );

    REQUIRE(
        loadManager.getExpense(0).getAmount() == 3.50
    );

    REQUIRE(
        loadManager.getExpense(0).getCategory() == "Food"
    );

    REQUIRE(
        loadManager.getExpense(1).getName() == "Train"
    );

    REQUIRE(
        loadManager.getExpense(1).getAmount() == 15.00
    );

    REQUIRE(
        loadManager.getExpense(1).getCategory() == "Transport"
    );


    remove("test_expenses.txt");
}


TEST_CASE("loadFromFile skips malformed amount") {
    {
        std::ofstream file("bad_expenses.txt");

        file << "Coffee|3.5|Food\n";
        file << "Broken|abc|Other\n";
    }


    ExpenseManager manager;

    manager.loadFromFile("bad_expenses.txt");


    REQUIRE(manager.getExpenseCount() == 1);

    REQUIRE(
        manager.getExpense(0).getName() == "Coffee"
    );


    remove("bad_expenses.txt");
}


TEST_CASE("addExpense rejects non-positive amount") {
    ExpenseManager manager;

    bool added = manager.addExpense(
        Expense("Invalid", -10, "Other")
    );

    REQUIRE_FALSE(added);
    REQUIRE(manager.getExpenseCount() == 0);
}


TEST_CASE("editExpense rejects non-positive amount") {
    ExpenseManager manager;

    manager.addExpense(
        Expense("Coffee", 3.50, "Food")
    );

    bool edited = manager.editExpense(
        1,
        "Coffee",
        -5.00,
        "Food"
    );

    REQUIRE_FALSE(edited);

    REQUIRE(
        manager.getExpense(0).getAmount() == 3.50
    );
}


TEST_CASE("getExpense throws for invalid index") {
    ExpenseManager manager;

    manager.addExpense(
        Expense("Coffee", 3.50, "Food")
    );

    REQUIRE_THROWS_AS(
        manager.getExpense(5),
        std::out_of_range
    );
}

TEST_CASE("sortByAmountAscending sorts expenses from lowest to highest") {
    ExpenseManager manager;

    manager.addExpense(Expense("Train", 15.00, "Transport"));
    manager.addExpense(Expense("Coffee", 3.50, "Food"));
    manager.addExpense(Expense("Lunch", 10.00, "Food"));

    manager.sortByAmountAscending();

    REQUIRE(manager.getExpense(0).getAmount() == 3.50);
    REQUIRE(manager.getExpense(1).getAmount() == 10.00);
    REQUIRE(manager.getExpense(2).getAmount() == 15.00);
}

TEST_CASE("sortByAmountDescending sorts expenses from highest to lowest") {
    ExpenseManager manager;

    manager.addExpense(Expense("Train", 15.00, "Transport"));
    manager.addExpense(Expense("Coffee", 3.50, "Food"));
    manager.addExpense(Expense("Lunch", 10.00, "Food"));

    manager.sortByAmountDescending();

    REQUIRE(manager.getExpense(0).getAmount() == 15.00);
    REQUIRE(manager.getExpense(1).getAmount() == 10.00);
    REQUIRE(manager.getExpense(2).getAmount() == 3.50);
}