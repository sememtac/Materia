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
    compatibility materia::compatible(const materia* arg) const
    {
        compatibility result{ Neutral };
        for (auto i : arg->destroys())
        {
            // Try find this materia on the comparing materia's destroy list
            if (this->type() == i)
            {
                result = compatibility::Destroy;
            }
        }
        // If target cannot destroy this materia
        if (result != Destroy)
        {
            for (auto j : this->transmutes())
            {
                // Try find the comparison in this materis's xmute list
                if (arg->type() == j)
                {
                    result = compatibility::Xmute;
                }
            }
        }
        
        return result;
    }
}