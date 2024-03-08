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
    extern const combinations::fire::ash ASH;
    extern const combinations::rock::boulder BOULDER;
    
    const std::vector<const materia*> CORE_LIBRARY
    {
        {
            // core
            &PLANT, &FIRE, &WIND , &WATER, &ROCK, &ASH, &BOULDER
            // stable
            // unstable
            // xmute
            // stable enclosed
            // xmute enclosed
        }
    };

    namespace elements
    {
        static const materia* fire()
        {
            return &FIRE;
        };
        static const materia* water()
        {
            return &WATER;
        }
        static const materia* rock()
        {
            return &ROCK;
        }
        static const materia* wind()
        {
            return &WIND;
        }
        static const materia* plant()
        {
            return &PLANT;
        }

        static const std::vector<const materia*>* library()
        {
            return &CORE_LIBRARY;
        }

        static const std::vector<const materia*> core()
        {
            return { &FIRE, &WATER, &ROCK, &WIND, &PLANT };
        }
    }


}
