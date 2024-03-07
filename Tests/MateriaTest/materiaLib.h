#pragma once
#include "materias.h"

namespace materia
{
	std::vector<const materia*> generate();
	std::vector<const materia*> find(const materia*);
	bool visited(const materia*, std::vector<const materia*>);
}