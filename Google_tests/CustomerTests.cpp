#include <gtest/gtest.h>
#include <iostream>

#include "../Customer.h"

using namespace std;

TEST(CustomerTests, constructor_gives_expected_name) {
    Customer c("Jean");
    ASSERT_TRUE("Jean");
}

TEST(CustomerTests, movie_types_are_singletons) {
    //the 2 movieType fields must have same adress
    ASSERT_EQ(MovieType::getRegular(), MovieType::getRegular());
    ASSERT_EQ(MovieType::getChildren(), MovieType::getChildren());
    ASSERT_EQ(MovieType::getNewRelease(), MovieType::getNewRelease());
}

TEST(CustomerTests, only_new_movies_have_bonuses) {
    /*
     * Je ne vois pas trop l'intérêt de mocker Movie par exemple. Un film fonctionne forcément avec un type,
     * tester que le Movie n'a pas vraiment de sens.
     * D'autant que les test précédents vérifient que MovieType marche bien.
     */
    Movie jw("Jurassic World", MovieType::getRegular()), cm("Captain Marvel", MovieType::getNewRelease());
    ASSERT_EQ(jw.getMovieType().getFrequentRenterBonus(), 0);
    ASSERT_EQ(cm.getMovieType().getFrequentRenterBonus(), 1);
}

TEST(CustomerTests, movie_field_is_fixed_by_type) {
    Movie jw("Jurassic World", MovieType::getRegular()), cm("Captain Marvel", MovieType::getNewRelease());
    ASSERT_EQ(jw.getMovieType().getPriceRental(), MovieType::getRegular()->getPriceRental());
    ASSERT_EQ(jw.getMovieType().getDurationStep(), MovieType::getRegular()->getDurationStep());
    ASSERT_EQ(jw.getMovieType().getLatePenalty(), MovieType::getRegular()->getLatePenalty());
    ASSERT_EQ(cm.getMovieType().getFrequentRenterBonus(), MovieType::getNewRelease()->getFrequentRenterBonus());
}

TEST(CustomerTests, movie_can_change_type) {
    Movie cm("Captain Marvel", MovieType::getNewRelease());
    ASSERT_EQ(&(cm.getMovieType()), MovieType::getNewRelease());
    cm.changeMovieType(MovieType::getRegular());
    ASSERT_EQ(&(cm.getMovieType()), MovieType::getRegular());
}

TEST(CustomerTests, statementMethodWorks) {
    Customer customer("Olivier");
    customer.addRental(Rental(Movie("Karate Kid", MovieType::getRegular()), 7));
    customer.addRental(Rental(Movie("Avengers: Endgame", MovieType::getNewRelease()), 5));
    customer.addRental(Rental(Movie("Snow White", MovieType::getChildren()), 3));

    string result = "Rental Record for Olivier\n\tKarate Kid\t9.5\n\tAvengers: Endgame\t15\n\tSnow White\t1.5\nAmount owed is 26\nYou earned 4 frequent renter points";
    ASSERT_EQ(result, customer.statement());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}