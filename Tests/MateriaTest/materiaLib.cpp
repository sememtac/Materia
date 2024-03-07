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
		for (size_t i = 0; i < search.size(); i++)
		{
			result = search[i]->name() == arg->name();
			if (result)
			{
				break;
			}
		}
		return result;
	}

	vector<const materia*> find(const materia* choice)
	{
		queue<const materia*> q{};
		vector<const materia*> search{};
		q.push(choice);
		search.push_back(choice);
		bool skip{};

		while (!q.empty())
		{
			const materia* current = q.front();
			q.pop();

			for (auto item : CORE_LIBRARY)
			{
				// Reset Skip
				skip = false;
				if (current->name() != item->name())
				{
					skip = *(current->compatible(item)) == compatibility::Destroy;
					if (!skip)
					{
						skip = *(item->compatible(current)) == compatibility::Destroy;

						if (!skip)
						{
							// Check if this materia has been picked
							if (!visited(item, search))
							{
								// This materia will not destroy the head
								q.push(item);
								search.emplace_back(item);
							}
						}
					}
				}
			}
		}
		return search;
	}

	vector<const materia*> generate()
	{
		size_t s = CORE_LIBRARY.size();
		auto randomChoice = rand() % s;
		int outCount{};
		const materia* choice = CORE_LIBRARY[randomChoice];
		return find(choice);
	}
}
