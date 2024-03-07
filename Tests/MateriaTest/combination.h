#pragma once
#include <map>
#include <vector>
#include "materias.h"

namespace materia
{
    const std::map<const materia*, std::vector<const materia*>> COMBINATIONS
    {
        { &ASH, { &PLANT, &FIRE } },
        { &BOULDER, {&ROCK, &ROCK, &ROCK}},
    };
}