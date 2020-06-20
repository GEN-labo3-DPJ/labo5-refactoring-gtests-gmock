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

    MovieType& getMovieType() const;
    const std::string& getTitle() const;

private:
    std::string _title;
    MovieType* movieType;
};

inline Movie::
Movie( const std::string& title, MovieType* type)
        : _title( title ), movieType(type)
{}

inline MovieType& Movie::
getMovieType() const {return *movieType;}

inline const std::string& Movie::
getTitle() const { return _title; }

#endif // MOVIE_H