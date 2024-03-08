#pragma once
#include "materias.h"

namespace materia
{
	std::vector<std::vector<const materia*>> generate();
	std::vector<std::vector<const materia*>> findPath(const materia*, int);
	bool visited(const materia*, std::vector<const materia*>);
	const materia* combine(std::vector<const materia*>*);
}