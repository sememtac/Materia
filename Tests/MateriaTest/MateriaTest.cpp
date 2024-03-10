#include "main.h"
#include <iostream>
#include "time.h"
#include <fstream>

using namespace std;

static string Write(vector<Materia::BaseType> t_arg)
{
    string result{};
    for (auto item : t_arg)
    {
        result += ("(" + Materia::baseTypeString[item] + ")");
    }
    return result;
}

void GenerateSet(int arg)
{
    Materia::BaseType roll1 = (Materia::BaseType)(rand() % arg);
    Materia::BaseType roll2 = (Materia::BaseType)(rand() % arg);
    Materia::BaseType roll3 = (Materia::BaseType)(rand() % arg);
    vector<Materia::BaseType> f;
    vector<Materia::BaseType*> it = { &roll1, &roll2, &roll3 };

    for (size_t i = 0; i < it.size(); i++)
    {
        Materia::BaseType selection{};
        switch (*it[i])
        {
        case Materia::BaseType::Fire:
            selection = Materia::BaseType::Fire;
            break;
        case Materia::BaseType::Plant:
            selection = Materia::BaseType::Plant;
            break;
        case Materia::BaseType::Rock:
            selection = Materia::BaseType::Rock;
            break;
        case Materia::BaseType::Water:
            selection = Materia::BaseType::Water;
            break;
        case Materia::BaseType::Air:
            selection = Materia::BaseType::Air;
            break;
        }
        f.emplace_back(selection);
    }

    cout << "Generated :" << endl;
    cout << Write(f) << endl;
}


void OutPutToFile(Materia::MateriaGraph* t_graph)
{
    int depth = 10;
    ofstream file("output.txt");
    if (file.is_open())
    {
        std::vector<std::vector<Materia::BaseType>> t{};
        for (int j = 0; j < 6; j++)
        {
            switch ((Materia::BaseType)j)
            {
            case Materia::BaseType::Fire:
                file << "\n Fire paths" << endl;
                t = Materia::MateriaGraph::FindPath(t_graph, Materia::BaseType::Fire, depth);
                for (size_t k = 0; k < t.size(); k++)
                {
                    file << Write(t[k]) << endl;
                }
                break;
            case Materia::BaseType::Plant:
                file << "\n Plant paths" << endl;
                t = Materia::MateriaGraph::FindPath(t_graph, Materia::BaseType::Plant, depth);
                for (size_t k = 0; k < t.size(); k++)
                {
                    file << Write(t[k]) << endl;
                }
                break;
            case Materia::BaseType::Rock:
                file << "\n Rock paths" << endl;
                t = Materia::MateriaGraph::FindPath(t_graph, Materia::BaseType::Rock, depth);
                for (size_t k = 0; k < t.size(); k++)
                {
                    file << Write(t[k]) << endl;
                }
                break;
            case Materia::BaseType::Water:
                file << "\n Water paths" << endl;
                t = Materia::MateriaGraph::FindPath(t_graph, Materia::BaseType::Water, depth);
                for (size_t k = 0; k < t.size(); k++)
                {
                    file << Write(t[k]) << endl;
                }
                break;
            case Materia::BaseType::Air:
                file << "\n Wind paths" << endl;
                t = Materia::MateriaGraph::FindPath(t_graph, Materia::BaseType::Air, depth);
                for (size_t k = 0; k < t.size(); k++)
                {
                    file << Write(t[k]) << endl;
                }
                break;
            }
        }
        file.close();
    }
}


int main()
{
    
    srand(time(0));

    Materia::MateriaGraph* t = new Materia::MateriaGraph();
    // std::vector<std::vector<Materia::BaseType>> f = Materia::FindPath(t, Materia::BaseType::Plant, 3);
    OutPutToFile(t);
input:
    std::vector<Materia::BaseType>* cLis = new std::vector<Materia::BaseType>{};
    std::string in;
    cin >> in;
    
    const Materia::Materia* result = Materia::Combine(Materia::Input(in, cLis));
    std::string output = (result == nullptr) ? "Incorrect combination" : result->name();
    cout << output << endl;
    goto input;
    return 0;
}

