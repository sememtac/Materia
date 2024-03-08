#include "materia.h"

using namespace std;
namespace materia
{
    compatibility materia::compatible(const materia* arg) const
    {
        compatibility result{ Neutral };
        if (this->type() != arg->type())
        {
            for (auto i : arg->destroys())
            {
                // Try find this materia on the comparing materia's destroy list
                if (this->type() == i->type())
                {
                    result = compatibility::Destroy;
                    break;
                }
            }
            result = Xmute;
        }
        return result;
    }
}