#include "materias.h"

namespace materia
{
    namespace core_materias
    {
        const plant PLANT
        {
            Plant,
            "Plant",
            {},
            {Wind}
        };

        const fire FIRE
        {
            Fire,
            "Fire",
            {},
            {Plant}
        };

        const water WATER
        {
            Water,
            "Water",
            {Plant},
            {Fire}
        };

        const wind WIND
        {
            Wind,
            "Wind",
            {Fire},
            {Water},
        };

        const rock ROCK
        {
            Rock,
            "Rock",
            {},
            {Plant},
        };
    }

    const ash ASH
    {
        Wind,
        "Ash",
        {Plant,},
        {},
    }
    
}