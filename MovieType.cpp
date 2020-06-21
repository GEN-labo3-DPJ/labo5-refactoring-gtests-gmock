//MovieType.cpp

#include "MovieType.h"

const MovieType* MovieType::regular= new MovieType(2,2,1.5,0);
const MovieType* MovieType::newRelease =new MovieType(0,0,3,1);
const MovieType* MovieType::children=new MovieType(1.5,3,1.5,0);

const MovieType* MovieType::getRegular()
{
    return regular;
}

const MovieType* MovieType::getNewRelease()
{
    return newRelease;
}

const MovieType* MovieType::getChildren()
{
    return children;
}
