#include "materiaLib.h"
#include <queue>
#include <typeinfo>
#include <stdexcept>
#include "combination.h"

using namespace std;
namespace materia
{
	const materia* combine(vector<const materia*>* combination)
	{
		size_t s{ combination->size() };
		size_t index{};
		const materia* result{};
		bool skip{};
		if (s >= 2)
		{
			for (auto entry : COMBINATIONS)
			{
				skip = false;
				if (entry.second.size() == combination->size())
				{
					for (auto i : entry.second)
					{
						index = entry.second.size();
						for (size_t j = 0; j < index; j++)
						{
							auto iName = (*combination)[j]->name();
							auto eName = entry.second[j]->name();
							if (iName != eName)
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

	bool visited(const materia* arg, vector<const materia*> search)
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

	vector<vector<const materia*>> findPath(const materia* choice, int depth)
	{
		vector<vector<const materia*>> result;
		queue<vector<const materia*>> q{};
		q.push({ choice });

		while (!q.empty())
		{
			vector<const materia*> path = q.front();
			q.pop();

			if (path.size() == depth)
			{
				result.push_back(path);
				continue;
			}

			const materia* current = path.back();

			for (const materia* next : current->transmutes())
			{
				if (find(path.begin(), path.end(), next) == path.end())
				{
					vector<const materia*> newPath = path;
					newPath.push_back(next);
					q.push(newPath);
				}
			}
		}
		return result;
	}

	vector<vector<const materia*>> generate()
	{
		size_t s = elements::library()->size();
		auto randomChoice = rand() % s;
		int outCount{};
		const materia* choice = (*elements::library())[randomChoice];
		return findPath(choice, 3);
	}
}