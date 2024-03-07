#include <iostream>
#include "main.h"
#include "time.h"

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

void RandomSetTest(std::string* arg)
{
    size_t s = materia::CORE_LIBRARY.size();
    int roll1 = (rand() % s);
    int roll2 = (rand() % s);
    int roll3 = (rand() % s);
    vector<const materia::materia*> f;
    vector<int*> it = { &roll1, &roll2, &roll3 };
    cout << "Generate :" << materia::baseTypeString[(materia::baseType)*it[0]] + materia::baseTypeString[(materia::baseType)*it[1]] + materia::baseTypeString[(materia::baseType)*it[2]] << endl;
    for (size_t i = 0; i < it.size(); i++)
    {
        f = materia::find(materia::CORE_LIBRARY[*it[i]]);
        *arg += Write(f);
    }
    cout << *arg << endl;
}

static void GenerateCoreSet(std::string* arg)
{
    vector<const materia::materia*> f;
    for (int i = 0; i < 5; i++)
    {
        // int random = rand() % materia::LIBRARY.size();
        f = materia::find(materia::CORE_LIBRARY[i]);
        *arg = Write(f);
        cout << ("Generated an unsolved configuration based on: \n" + materia::CORE_LIBRARY[i]->name()) << endl;
        cout << *arg << endl;
    }
}

int main()
{
    srand(time(0));
    auto graph = materia::materiaGraph();
    for (auto entry : materia::CORE_LIBRARY)
    {
        graph._materias.emplace_back(entry);
    }

    string out{};
    GenerateCoreSet(&out);

    out = "";
    RandomSetTest(&out);
    std::vector<const materia::materia*> cLis{ &materia::PLANT , &materia::FIRE };
    std::vector<const materia::materia*>* bar = &cLis;
    auto foo = materia::combine(bar);
}

