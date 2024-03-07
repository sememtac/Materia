#include "materiaLib.h"
#include <queue>
#include <typeinfo>
using namespace std;
namespace materia
{
	bool compatible(const materia* lhs, const materia* rhs)
	{
		bool result { true };
		for (auto i : rhs->destroys())
		{
			// Try find head on the comparing materia's destroy list
			// if (lhs->name() == i->name())
			if (lhs->type() == i)
			{
				result = false;
				break;
			}
		}
		return result;
	}
	bool visited(const materia* arg, vector<const materia*> search)
	{
		bool result { true };
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

	std::vector<const materia*> find(const materia* choice)
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

			for (auto item : LIBRARY)
			{ 
				// Reset Skip
				skip = false;
				if (current->name() != item->name())
				{
					skip = !compatible(current, item);
					if (!skip)
					{
						skip = !compatible(item, current);

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
	};

	std::vector<const materia*> generate()
	{
		size_t s = LIBRARY.size();
		auto randomChoice = rand() % s;
		int outCount{};
		const materia* choice = LIBRARY[randomChoice];
		return find(choice);
	}
}
