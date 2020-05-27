//
// Created by pablo-pc on 27.05.2020.
//

#include <gtest/gtest.h>

#include "../Customer.h"

TEST(CustomerTests, constructor_gives_expected_name){
    Customer c("Jean");
    ASSERT_TRUE("Jean");
}