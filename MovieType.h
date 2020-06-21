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
    unsigned frequentRenterBonus;

    static const MovieType* regular;
    static const MovieType* newRelease;
    static const MovieType* children;

    MovieType(double price, unsigned durationStep, double penalty,unsigned bonus)
    {
        priceRental=price;
        this->durationStep=durationStep,
        latePenalty=penalty;
        frequentRenterBonus=bonus;
    }

public:
    double getPriceRental() const
    {
        return priceRental;
    }

    unsigned getDurationStep() const
    {
        return durationStep;
    }

    double getLatePenalty() const
    {
        return latePenalty;
    }

    unsigned getFrequentRenterBonus() const
    {
        return frequentRenterBonus;
    }

    virtual ~MovieType(){}

    static const MovieType* getRegular();
    static const MovieType* getNewRelease();
    static const MovieType* getChildren();
};

#endif //LABO5_REFACTORING_GTESTS_GMOCK_MOVIETYPE_H
