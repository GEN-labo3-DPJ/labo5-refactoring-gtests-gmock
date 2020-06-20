// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;
    unsigned applyFrequentRenterBonus();
private:
    Movie _movie;
    int _daysRented;
};

inline Rental::
Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie& Rental::
getMovie() const { return _movie; }

inline unsigned Rental::
applyFrequentRenterBonus() {
    if(_daysRented>1)
    {
        return _movie.getMovieType().getFrequentRenterBonus();
    }
    return 0;
}

#endif // RENTAL_H