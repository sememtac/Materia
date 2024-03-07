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
    };
    compatibility* materia::compatible(const materia* arg) const
    {
        compatibility result{ Neutral };
        for (auto i : arg->destroys())
        {
            // Try find head on the comparing materia's destroy list
            if (this->type() == i)
            {
                result = compatibility::Destroy;
                break;
            }
        }
        for (auto j : arg->transmutes())
        {
            if (this->type() == j)
            {
                result = compatibility::Xmute;
            }
        }
        return &result;
    }
}