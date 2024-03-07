#pragma once
#include "materia.h"

namespace materia
{
    // Define materia property here
    //const materia EXAMPLE
    //{
    //	"Example",
    //	{},
    //	{}
    //};

    extern const materia PLANT;
    extern const materia WIND;
    extern const materia FIRE;
    extern const materia WATER;
    extern const materia ROCK;

    const std::vector<const materia*> LIBRARY
    {
        {&PLANT, &FIRE, &WIND , &WATER, &ROCK}
    };

}
