#include "input.h"

using namespace std;
namespace materia
{
    std::vector<const elements::element*> Input(std::string arg)
    {
        std::vector<const elements::element*> result{};

        size_t s = arg.size();
        if (arg != "Generate")
        {
            for (size_t i = 0; i < arg.size(); i++)
            {
                const elements::element* materia{};
                switch (tolower(arg[i]))
                {
                case 'p':
                    materia = elements::Plant();
                    break;
                case 'f':
                    materia = elements::Fire();
                    break;
                case 'w':
                    materia = elements::Water();
                    break;
                case 'a':
                    materia = elements::Wind();
                    break;
                case 'r':
                    materia = elements::Rock();
                    break;
                }
                result.push_back(materia);
            }
        }
        
        return result;
    }
}