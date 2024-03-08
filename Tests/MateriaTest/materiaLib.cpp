#include "materiaLib.h"
#include <queue>
#include <typeinfo>
#include <stdexcept>

using namespace std;
namespace materia
{
	const elements::combination* combine(vector<const elements::element*>* arg)
	{
		size_t s{ arg->size() };
		size_t index{};
		const elements::combination* result{};
		bool skip{};
		if (s > 1)
		{
			for (auto entry : *combinations())
			{
				skip = false;
				if (entry.second.size() == s)
				{
					for (auto i : entry.second)
					{
						index = entry.second.size();
						for (size_t j = 0; j < index; j++)
						{
							if (entry.second[j] != (*arg)[j])
							{
								skip = true;
								break;
							}
						}
						if (skip)
						{
							continue;
						}
						else
						{
							return result = entry.first;
						}
					}
				}	
			}
		}
		else
		{
			throw domain_error("Cannot combine with less than two materias");
		}
		return result;
	}

	bool visited(const elements::element* arg, vector<const elements::element*> search)
	{
		bool result{ true };

		if (empty(search))
		{
			result = false;
		}
		else
		{
			for (size_t i = 0; i < search.size(); i++)
			{
				result = search[i]->name() == arg->name();
				if (result)
				{
					break;
				}
			}
		}

		return result;
	}

	vector<vector<const elements::element*>> findPath(const elements::element* choice, int depth)
	{
		vector<vector<const elements::element*>> result;
		queue<vector<const elements::element*>> q{};
		q.push({ choice });

		while (!q.empty())
		{
			vector<const elements::element*> path = q.front();
			q.pop();

			if (path.size() == depth)
			{
				result.push_back(path);
				continue;
			}

			const elements::element* current = path.back();
			const elements::element* cast = dynamic_cast<const elements::element*>(current);

			for (const elements::element* next : cast->transmutes())
			{
				if (find(path.begin(), path.end(), next) == path.end())
				{
					vector<const elements::element*> newPath = path;
					newPath.push_back(next);
					q.push(newPath);
				}
			}
		}
		return result;
	}

	vector<vector<const elements::element*>> generate()
	{
		size_t s = elements::library()->size();
		auto randomChoice = rand() % s;
		int outCount{};
		const elements::element* choice = (*elements::library())[randomChoice];
		return findPath(choice, 3);
	}
}