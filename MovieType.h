//
// Created by David Dupraz on 19.06.2020.
//

#ifndef LABO5_REFACTORING_GTESTS_GMOCK_MOVIETYPE_H
#define LABO5_REFACTORING_GTESTS_GMOCK_MOVIETYPE_H

class MovieType {
    static const int CHILDRENS   = 2;
    static const int REGULAR     = 0;
    static const int NEW_RELEASE = 1;

    double priceRental;
    unsigned durationStep;
    double latePenalty;

    static MovieType* regular;
    static MovieType* newRelease;
    static MovieType* children;

    MovieType(double price, unsigned durationStep, double penalty)
    {
        priceRental=price;
        this->durationStep=durationStep,
        latePenalty=penalty;
    }

public:
    double getPriceRental()
    {
        return priceRental;
    }

    unsigned getDurationStep()
    {
        return durationStep;
    }

    unsigned getLatePenalty()
    {
        return latePenalty;
    }

    static MovieType* getRegular();
    static MovieType* getNewRelease();
    static MovieType* getChildren();
};

#endif //LABO5_REFACTORING_GTESTS_GMOCK_MOVIETYPE_H
