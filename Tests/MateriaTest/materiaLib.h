#pragma once
#include "materias.h"

using namespace std;
namespace materia
{
	std::vector<const materia*> generate();
	std::vector<const materia*> find(const materia*);
	bool compatible(const materia*, const materia*);
	bool visited(const materia*, vector<const materia*>);
}