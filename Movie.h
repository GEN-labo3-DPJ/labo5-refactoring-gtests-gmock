// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <utility>

#include "MovieType.h"

class Movie {
public:
    Movie( std::string title, const MovieType* type);

    const MovieType& getMovieType() const;
    const std::string& getTitle() const;
    void changeMovieType(const MovieType* newType);

private:
    std::string _title;
    const MovieType* movieType;
};

inline Movie::
Movie( std::string title, const MovieType* type)
        : _title( std::move(title) ), movieType(type)
{}

inline const MovieType& Movie::
getMovieType() const {return *movieType;}

inline const std::string& Movie::
getTitle() const { return _title; }

inline void Movie::
changeMovieType(const MovieType* newType) {movieType=newType;}

#endif // MOVIE_H