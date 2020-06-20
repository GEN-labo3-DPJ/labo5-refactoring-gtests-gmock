// Customer.cpp
#include <sstream>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    unsigned frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for (Rental each: _rentals ) {
        double thisAmount = 0;

        Movie m=each.getMovie();
        thisAmount+=m.getMovieType().getPriceRental();
        if ( each.getDaysRented() > m.getMovieType().getDurationStep() )
        {
            thisAmount += ( each.getDaysRented() - m.getMovieType().getDurationStep() ) * m.getMovieType().getLatePenalty() ;
        }

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        if (each.getDaysRented() > 1 )
        {
            frequentRenterPoints+=each.getMovie().getMovieType().getFrequentRenterBonus();
        }

        // show figures for this rental
        result << "\t" << each.getMovie().getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}