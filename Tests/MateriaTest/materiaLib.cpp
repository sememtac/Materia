#include "materiaLib.h"
#include <queue>

using namespace std;
namespace materia
{
	std::vector<const materia*> find(const materia* choice)
	{
		queue<const materia*> q{};
		vector<const materia*> search{};
		q.push(choice);
		search.push_back(choice);
		string currentName{};
		string currentKillName{};
		bool skip{};

		while (!q.empty())
		{
			const materia* current = q.front();
			currentName = current->name();
			q.pop();

			for (auto item : LIBRARY)
			{ 
				// Reset Skip
				skip = false;
				if (currentName != item->name())
				{
					for (auto i : item->destroys())
					{
						// Found on the destroy list
						currentKillName = i->name();
						if (currentName == currentKillName)
						{
							skip = true;
							break;
						}
					}
					if (!skip)
					{
						for (auto j : current->destroys())
						{
							currentKillName = j->name();
							if (currentKillName == item->name())
							{
								skip = true;
								break;
							}
						}

						if (!skip)
						{
							// Check if this materia has been picked
							bool alreadyVisited{};
							for (size_t i = 0; i < search.size(); i++)
							{
								if (search[i]->name() == item->name())
								{
									alreadyVisited = true;
									break;
								}
							}

							if (!alreadyVisited)
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
