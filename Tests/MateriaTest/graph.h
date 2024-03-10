#pragma once
#include "materia.h"
#include <queue>
namespace Materia
{
	class Edge
	{
	private:
		BaseType m_input;
		BaseType m_output;
	public:
		Edge(BaseType t_input, BaseType t_output) : m_input(t_input), m_output(t_output) {}
		BaseType Input() const
		{
			return m_input;
		}
		bool Input(BaseType t_input) const
		{
			return m_input == t_input;
		}
		BaseType Output() const
		{
			return m_output;
		}
	};

	class MateriaGraph
	{
		Edge m_edges[10]
		{
			Edge(Rock, Fire),
			Edge(Plant, Fire),
			Edge(Fire, Water),
			Edge(Rock, Water),
			Edge(Water, Air),
			Edge(Fire, Air),
			Edge(Water, Plant),
			Edge(Air, Plant),
			Edge(Air, Rock),
			Edge(Plant, Rock),
		};
	public:
		const Edge* Edges() const
		{
			return m_edges;
		};
		MateriaGraph();
		static std::vector<std::vector<BaseType>> FindPath(MateriaGraph*, BaseType, int);
		static std::vector<std::vector<BaseType>> Generate(MateriaGraph*);
	};




}