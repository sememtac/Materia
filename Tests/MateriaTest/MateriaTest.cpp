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
            selection = materia::elements::Fire();
            break;
        case materia::baseType::Plant:
            selection = materia::elements::Plant();
            break;
        case materia::baseType::Rock:
            selection = materia::elements::Rock();
            break;
        case materia::baseType::Water:
            selection = materia::elements::Water();
            break;
        case materia::baseType::Wind:
            selection = materia::elements::Wind();
            break;
        }
        f.emplace_back(selection);
    }

    cout << "Generated :" << endl;
    cout << Write(f) << endl;
}


void OutPutToFile()
{
    ofstream file("output.txt");
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
                    auto t = findPath(materia::elements::Fire(), i);
                    for (size_t k = 0; k < t.size(); k++)
                    {
                        file << Write(t[k]) << endl;
                    }
                }
                break;
            case materia::baseType::Plant:
                file << "\n Plant paths" << endl;
                for (int i = 0; i < 6; i++)
                {
                    auto t = findPath(materia::elements::Plant(), i);
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
                    auto t = findPath(materia::elements::Rock(), i);
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
                    auto t = findPath(materia::elements::Water(), i);
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
                    auto t = findPath(materia::elements::Wind(), i);
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
}

std::vector<const materia::materia*> Input(string arg)
{
    std::vector<const materia::materia*> result{};
    
    for (size_t i = 0; i < arg.size(); i++)
    {
        const materia::materia* materia{};
        switch (tolower(arg[i]))
        {
        case 'p':
            materia = materia::elements::Plant();
            break;
        case 'f':
            materia = materia::elements::Fire();
            break;
        case 'w':
            materia = materia::elements::Water();
            break;
        case 'a':
            materia = materia::elements::Wind();
            break;
        case 'r':
            materia = materia::elements::Rock();
            break;
        }
        result.push_back(materia);
    }
    return result;
}

int main()
{
    srand(time(0));

    std::vector<const materia::materia*> cLis{};
    std::string in;
    cin >> in;
    cLis = Input(in);
    cout << ::materia::combine(&cLis)->name() << endl;
    return 0;
}

