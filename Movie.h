// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

#include "MovieType.h"

class Movie {
public:
    static const int CHILDRENS   = 2;
    static const int REGULAR     = 0;
    static const int NEW_RELEASE = 1;

    Movie( const std::string& title, MovieType* type);

    double getPriceRental() const;
    unsigned getDurationStep() const;
    double getLatePenalty() const;
    void setPriceCode( int arg );
    std::string getTitle() const;

private:
    std::string _title;
    //int _priceCode;
    MovieType* movieType;
};

inline Movie::
Movie( const std::string& title, MovieType* type)
        : _title( title ), movieType(type)
{}

inline double Movie::
getPriceRental() const { return movieType->getPriceRental(); }

inline unsigned Movie::
getDurationStep() const {return movieType->getDurationStep();}

inline double Movie::
getLatePenalty() const { return movieType->getLatePenalty(); }

/*inline void Movie::
setPriceCode( int arg ) { _priceCode = arg; }*/

inline std::string Movie::
getTitle() const { return _title; }

#endif // MOVIE_H