#include <gtest/gtest.h>
#include <iostream>

#include "../Customer.h"

using namespace std;

namespace {
    // The fixture for testing class Foo.
    class OurTest : public ::testing::Test {
    protected:
        // You can remove any or all of the following functions if their bodies would
        // be empty.

        OurTest() {
            // You can do set-up work for each test here.
        }

        ~OurTest() override {
            // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        void SetUp() override {
            // Code here will be called immediately after the constructor (right
            // before each test).
        }

        void TearDown() override {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }

        // Class members declared here can be used by all tests in the test suite
        // for Foo.
    };

    TEST(CustomerTests, constructor_gives_expected_name) {
        Customer c("Jean");
        ASSERT_TRUE("Jean");
    }

    TEST(CustomerTests, statementMethodWorks) {
        Customer customer("Olivier");
        customer.addRental( Rental( Movie("Karate Kid", MovieType::getRegular()),7));
        customer.addRental( Rental( Movie( "Avengers: Endgame", MovieType::getNewRelease() ), 5));
        customer.addRental( Rental( Movie("Snow White",MovieType::getChildren()), 3 ));

        string result="Rental Record for Olivier\n\tKarate Kid\t9.5\n\tAvengers: Endgame\t15\n\tSnow White\t1.5\nAmount owed is 26\nYou earned 4 frequent renter points";
        ASSERT_EQ(result, customer.statement());
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}