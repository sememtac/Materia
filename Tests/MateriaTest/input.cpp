#include "input.h"

using namespace std;
namespace Materia
{
    std::vector<BaseType>* Input(std::string t_arg, std::vector<BaseType>* t_input)
    {
        size_t s = t_arg.size();
        if (t_arg != "Generate")
        {
            for (size_t i = 0; i < t_arg.size(); i++)
            {
                BaseType choice{};
                switch (tolower(t_arg[i]))
                {
                case 'p':
                    choice = Plant;
                    break;
                case 'f':
                    choice = Fire;
                    break;
                case 'w':
                    choice = Water;
                    break;
                case 'a':
                    choice = Air;
                    break;
                case 'r':
                    choice = Rock;
                    break;
                }
                t_input->push_back(choice);
            }
        }
        
        return t_input;
    }
}