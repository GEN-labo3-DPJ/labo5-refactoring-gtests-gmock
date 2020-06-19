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
        regular=new MovieType(2,2,1.5,0);
    }
    return regular;
}

MovieType* MovieType::getNewRelease()
{
    if(newRelease== nullptr)
    {
        newRelease=new MovieType(0,0,3,1);
    }
    return newRelease;
}

MovieType* MovieType::getChildren()
{
    if(children== nullptr)
    {
        children=new MovieType(1.5,3,1.5,0);
    }
    return children;
}
