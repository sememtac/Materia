#pragma once
#include "core.h"
#include "combination.h"

namespace materia
{
	std::vector<std::vector<const elements::element*>> generate();
	std::vector<std::vector<const elements::element*>> findPath(const elements::element*, int);
	bool visited(const elements::element*, std::vector<const elements::element*>);
	const elements::combination* combine(std::vector<const elements::element*>* arg);
}