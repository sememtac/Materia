#include "combination.h"

using namespace std;
namespace Materia
{


	const Materia* Combine(vector<BaseType>* t_arg)
	{
		size_t s{ t_arg->size() };
		size_t index{};
		const Materia* result{};
		bool skip{};
		if (s > 1)
		{
			for (auto entry : COMBINATIONS)
			{
				skip = false;
				if (entry.second.size() == s)
				{
					for (auto i : entry.second)
					{
						index = entry.second.size();
						for (size_t j = 0; j < index; j++)
						{
							auto t = entry.second[j];
							if (entry.second[j] != (*t_arg)[j])
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
	};
}
