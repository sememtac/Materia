#include "materia.h"

using namespace std;
namespace materia
{
	materia::materia(baseType type, std::string name, std::vector<baseType> transmutes, std::vector<baseType> destroys)
	{
		_type = type;
		_name = name;
		_transmutes = transmutes;
		_destroys = destroys;
	}
}