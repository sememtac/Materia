#pragma once
#include "materias.h"

using namespace std;
namespace materia
{
	// Declare materia externally here
	// extern const materia EXAMPLE;
    extern const materia PLANT;
    extern const materia AIR;
    extern const materia FIRE;
    extern const materia WATER;
    extern const materia ROCK;

    const std::vector<const materia*> LIBRARY
    {
        {&FIRE, &WATER, &PLANT, &AIR, &ROCK}
    };

	std::vector<const materia*> generate();
	std::vector<const materia*> find(const materia*);
}