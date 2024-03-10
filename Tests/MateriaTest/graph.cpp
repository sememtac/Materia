#include "graph.h"

using namespace std;
namespace Materia
{
	MateriaGraph::MateriaGraph()
	{
	}
	std::vector<std::vector<BaseType>> MateriaGraph::FindPath(MateriaGraph* t_graph, BaseType t_choice, int t_depth)
	{
		std::vector<std::vector<BaseType>> search{};
		queue<std::vector<BaseType>> q{};
		q.push({ t_choice });

		while (!q.empty())
		{
			std::vector<BaseType> path{ q.front() };
			q.pop();

			if (path.size() == t_depth)
			{
				search.push_back(path);
				continue;
			}

			BaseType current = path.back();

			for (int i = 0; i < 10; i++)
			{
				auto currentEdge = t_graph->Edges()[i];
				if (t_graph->Edges()[i].Input() == current)
				{
					vector<BaseType> newPath = path;
					newPath.push_back(t_graph->Edges()[i].Output());
					q.push(newPath);
				}
			}

		}

		return search;
	}

	std::vector<std::vector<BaseType>> MateriaGraph::Generate(MateriaGraph* t_graph)
	{
		return std::vector<std::vector<BaseType>>();
	}
	

}