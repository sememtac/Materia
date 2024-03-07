#include "materias.h"

namespace materia
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
    const ash ASH
    {
        Wind,
        "Ash",
        {Plant,},
        {},
    };


}