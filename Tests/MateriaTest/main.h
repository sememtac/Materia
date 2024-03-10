#pragma once
#include "materia.h"
#include "combination.h"
#include "graph.h"
#include "input.h"
#include <queue>
#include <string>

static std::string Write(std::vector<const Materia::Materia*>);
static void GenerateSet(int arg);
void OutPutToFile(Materia::MateriaGraph);