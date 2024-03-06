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
    const materia PLANT
    {
        "Plant",
        {},
        {}
    };

    const materia FIRE
    {
        "Fire",
        {},
        {&PLANT,}
    };

    const materia WATER
    {
        "Water",
        {&PLANT,},
        {&FIRE,}
    };

    const materia AIR
    {
        "Air",
        {&FIRE},
        {&WATER},
    };




    const materia ROCK
    {
        "Rock",
        {},
        {},
    };
}
