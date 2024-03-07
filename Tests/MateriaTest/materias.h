#pragma once
#include "materia.h"
#include "classes.h"
#include <map>

namespace materia
{
    // Define materia property here
    //const materia EXAMPLE
    //{
    //	"Example",
    //	{},
    //	{}
    //};

    extern const plant PLANT;
    extern const wind WIND;
    extern const fire FIRE;
    extern const water WATER;
    extern const rock ROCK;
    extern const ash ASH;
    extern const bounder BOULDER;
    
    const std::vector<const materia*> CORE_LIBRARY
    {
        {
            // core
            &PLANT, &FIRE, &WIND , &WATER, &ROCK,
            // stable
            // unstable
            // xmute
            // stable enclosed
            // xmute enclosed
        }
    };
}
