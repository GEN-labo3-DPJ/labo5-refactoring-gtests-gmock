//
// Created by David Dupraz on 19.06.2020.
//

#include "MovieType.h"

MovieType* MovieType::regular= nullptr;
MovieType* MovieType::newRelease= nullptr;
MovieType* MovieType::children= nullptr;

MovieType* MovieType::getRegular()
{
    if(regular== nullptr)
    {
        regular=new MovieType(REGULAR);
    }
    return regular;
}

MovieType* MovieType::getNewRelease()
{
    if(newRelease== nullptr)
    {
        newRelease=new MovieType(NEW_RELEASE);
    }
    return newRelease;
}

MovieType* MovieType::getChildren()
{
    if(children== nullptr)
    {
        children=new MovieType(CHILDRENS);
    }
    return children;
}
