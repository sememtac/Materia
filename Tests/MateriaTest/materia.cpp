#include "materia.h"

using namespace std;
namespace materia
{
    compatibility materia::compatible(const materia* arg) const
    {
        compatibility result{ Neutral };
        if (this->type() != arg->type())
        {
            bool destroy{ false };
            switch (arg->type())
            {
            case baseType::Fire:
                destroy = (this->type() == baseType::Air || this->type() == baseType::Water);
                break;
            case baseType::Plant:
                destroy = (this->type() == baseType::Fire || this->type() == baseType::Rock);
                break;
            case baseType::Rock:
                destroy = (this->type() == baseType::Fire || this->type() == baseType::Water);
                break;
            case baseType::Water:
                destroy = (this->type() == baseType::Plant || this->type() == baseType::Air);
                break;
            case baseType::Air:
                destroy = (this->type() == baseType::Plant || this->type() == baseType::Rock);
                break;
            }
            if (destroy)
            {
                result = Destroy;
            }
            else
            {
                result = Xmute;
            }
        }
        return result;
    }
}