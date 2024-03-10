#include "materia.h"

using namespace std;
namespace Materia
{
    const Materia* ELEMENTS[5]
    {
        &FIRE,
        &WATER,
        &AIR,
        &ROCK,
        &PLANT
    };

    Compatibility Materia::Compatible(const Materia* arg) const
    {
        Compatibility result{ Neutral };
        if (this->type() != arg->type())
        {
            bool destroy{ false };
            switch (arg->type())
            {
            case BaseType::Fire:
                destroy = (this->type() == BaseType::Air || this->type() == BaseType::Water);
                break;
            case BaseType::Plant:
                destroy = (this->type() == BaseType::Fire || this->type() == BaseType::Rock);
                break;
            case BaseType::Rock:
                destroy = (this->type() == BaseType::Fire || this->type() == BaseType::Water);
                break;
            case BaseType::Water:
                destroy = (this->type() == BaseType::Plant || this->type() == BaseType::Air);
                break;
            case BaseType::Air:
                destroy = (this->type() == BaseType::Plant || this->type() == BaseType::Rock);
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