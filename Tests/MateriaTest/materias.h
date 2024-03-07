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
    namespace core_materias
    {
        extern const plant PLANT;
        extern const wind WIND;
        extern const fire FIRE;
        extern const water WATER;
        extern const rock ROCK;
    }

    extern const ash ASH;
    
    const std::vector<const materia*> LIBRARY
    {
        {  
            // core
            &core_materias::PLANT, &core_materias::FIRE, &core_materias::WIND , &core_materias::WATER, &core_materias::ROCK,
            // stable
            // unstable
            // xmute
            // stable enclosed
            // xmute enclosed
        }
    };


    

}
