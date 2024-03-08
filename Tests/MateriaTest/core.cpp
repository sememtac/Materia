#include "core.h"

namespace materia
{
    namespace elements
    {
        const element PLANT
        {
            baseType::Plant,
            "Plant",
            {&ROCK, &FIRE},
            {&AIR, &WATER}
        };

        const element FIRE
        {
            baseType::Fire,
            "Fire",
            {&WATER, &AIR},
            {&PLANT, &ROCK}
        };

        const element WATER
        {
            baseType::Water,
            "Water",
            {&PLANT, &AIR},
            {&FIRE, &ROCK}
        };

        const element AIR
        {
            baseType::Air,
            "Wind",
            {&ROCK, &PLANT},
            {&WATER, &FIRE},
        };

        const element ROCK
        {
            baseType::Rock,
            "Rock",
            {&FIRE, &WATER},
            {&PLANT, &AIR},
        };
    }
    
}