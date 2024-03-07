#include "materias.h"

namespace materia
{

    const materia PLANT
    {
        "Plant",
        {},
        {&WIND}
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

    const materia WIND
    {
        "Wind",
        {&FIRE},
        {&WATER},
    };

    const materia ROCK
    {
        "Rock",
        {},
        {&PLANT},
    };

}