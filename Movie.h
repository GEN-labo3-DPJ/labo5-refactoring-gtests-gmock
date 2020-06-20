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

    Movie( std::string title, const MovieType* type);

    const MovieType& getMovieType() const;
    const std::string& getTitle() const;

private:
    std::string _title;
    const MovieType* movieType;
};

inline Movie::
Movie( std::string title, const MovieType* type)
        : _title( title ), movieType(type)
{}

inline const MovieType& Movie::
getMovieType() const {return *movieType;}

inline const std::string& Movie::
getTitle() const { return _title; }

#endif // MOVIE_H