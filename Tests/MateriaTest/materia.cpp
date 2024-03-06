#include "materia.h"

using namespace std;
namespace materia
{
	materia::materia()
	{
	}
	materia::materia(std::string name, std::vector<const materia*> transmutes, std::vector<const materia*> destroys)
	{
		_name = name;
		_transmutes = transmutes;
		_destroys = destroys;
	}
}