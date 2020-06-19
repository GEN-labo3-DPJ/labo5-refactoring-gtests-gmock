#include <iostream>

#include "Customer.h"
#include "Google_tests/lib/googletest/include/gtest/gtest.h"

int main() {

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid", MovieType::getRegular()),7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", MovieType::getNewRelease() ), 5));
    customer.addRental( Rental( Movie("Snow White",MovieType::getChildren()), 3 ));

    std::cout << customer.statement() << std::endl;

    return 0;
}
