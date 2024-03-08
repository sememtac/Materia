#include <iostream>
#include "main.h"
#include "time.h"
#include <fstream>

using namespace std;

static string Write(vector<const materia::materia*> arg)
{
    string result{};
    for (auto item : arg)
    {
        result += ("(" + item->name() + ")");
    }
    return result;
}

void GenerateSet(int arg)
{
    materia::baseType roll1 = (materia::baseType)(rand() % arg);
    materia::baseType roll2 = (materia::baseType)(rand() % arg);
    materia::baseType roll3 = (materia::baseType)(rand() % arg);
    vector<const materia::materia*> f;
    vector<materia::baseType*> it = { &roll1, &roll2, &roll3 };

    for (size_t i = 0; i < it.size(); i++)
    {
        const materia::materia* selection{};
        switch (*it[i])
        {
        case materia::baseType::Fire:
            selection = materia::elements::fire();
            break;
        case materia::baseType::Plant:
            selection = materia::elements::plant();
            break;
        case materia::baseType::Rock:
            selection = materia::elements::rock();
            break;
        case materia::baseType::Water:
            selection = materia::elements::water();
            break;
        case materia::baseType::Wind:
            selection = materia::elements::wind();
            break;
        }
        f.emplace_back(selection);
    }

    cout << "Generated :" << endl;
    cout << Write(f) << endl;
}

int main()
{
    srand(time(0));
    auto graph = materia::materiaGraph();
    for (auto entry : materia::CORE_LIBRARY)
    {
        graph._materias.emplace_back(entry);
    }

    

    std::vector<const materia::materia*> cLis{ &materia::PLANT , materia::elements::fire()};
    std::vector<const materia::materia*>* bar = &cLis;
    auto foo = materia::combine(bar);
    cout << foo->name() << endl;
    cLis = { &materia::ROCK, &materia::ROCK };
    auto wtf = materia::combine(bar);
    cout << wtf->name() << endl;
    ofstream file ("output.txt");
    if (file.is_open())
    {
        for (int j = 0; j < 6; j++)
        {
            switch ((materia::baseType)j)
            {
            case materia::baseType::Fire:
                file << "\n Fire paths" << endl;
                for (int i = 0; i < 6; i++)
                {
                    auto t = findPath(materia::elements::fire(), i);
                    for (size_t k = 0; k < t.size(); k++)
                    {
                        file << Write(t[k]) << endl;
                    }
                }
                break;
            case materia::baseType::Plant:
                file <<  "\n Plant paths" << endl;
                for (int i = 0; i < 6; i++)
                {
                    auto t = findPath(materia::elements::plant(), i);
                    for (size_t k = 0; k < t.size(); k++)
                    {
                        file << Write(t[k]) << endl;
                    }
                }
                break;
            case materia::baseType::Rock:
                file << "\n Rock paths" << endl;
                for (int i = 0; i < 6; i++)
                {
                    auto t = findPath(materia::elements::rock(), i);
                    for (size_t k = 0; k < t.size(); k++)
                    {
                        file << Write(t[k]) << endl;
                    }
                }
                break;
            case materia::baseType::Water:
                file << "\n Water paths" << endl;
                for (int i = 0; i < 6; i++)
                {
                    auto t = findPath(materia::elements::water(), i);
                    for (size_t k = 0; k < t.size(); k++)
                    {
                        file << Write(t[k]) << endl;
                    }
                }
                break;
            case materia::baseType::Wind:
                file << "\n Wind paths" << endl;
                for (int i = 0; i < 6; i++)
                {
                    auto t = findPath(materia::elements::wind(), i);
                    for (size_t k = 0; k < t.size(); k++)
                    {
                        file << Write(t[k]) << endl;
                    }
                }
                break;
            }
        }
        file.close();
    }
    return 0;
}

