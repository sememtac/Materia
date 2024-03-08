#include "materias.h"

namespace materia
{
    namespace elements
    {
        const plant PLANT
        {
            baseType::Plant,
            "Plant",
            {&ROCK, &FIRE},
            {&WIND, &WATER}
        };

        const fire FIRE
        {
            baseType::Fire,
            "Fire",
            {&WATER, &WIND},
            {&PLANT, &ROCK}
        };

        const water WATER
        {
            baseType::Water,
            "Water",
            {&PLANT, &WIND},
            {&FIRE, &ROCK}
        };

        const wind WIND
        {
            baseType::Wind,
            "Wind",
            {&ROCK, &PLANT},
            {&WATER, &FIRE},
        };

        const rock ROCK
        {
            baseType::Rock,
            "Rock",
            {&FIRE, &WATER},
            {&PLANT, &WIND},
        };
    }
    
}