#include "materias.h"

namespace materia
{
    const plant PLANT
    {
        Plant,
        "Plant",
        {&ROCK, &FIRE},
        {&WIND, &WATER}
    };

    const fire FIRE
    {
        Fire,
        "Fire",
        {&WATER, &WIND},
        {&PLANT, &ROCK}
    };

    const water WATER
    {
        Water,
        "Water",
        {&PLANT, &WIND},
        {&FIRE, &ROCK}
    };

    const wind WIND
    {
        Wind,
        "Wind",
        {&ROCK, &PLANT},
        {&WATER, &FIRE},
    };

    const rock ROCK
    {
        Rock,
        "Rock",
        {&FIRE, &WATER},
        {&PLANT, &WIND},
    };

    const combinations::fire::ash ASH 
    {
        "Ash"
    };

    const combinations::rock::boulder BOULDER
    {
        "Boulder",
    };


}