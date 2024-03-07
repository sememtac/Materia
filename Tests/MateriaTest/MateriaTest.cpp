#include <iostream>
#include "main.h"
#include "time.h"
using namespace std;
string Write(vector <const materia::materia*> arg)
{
    string result{};
    for (auto item : arg)
    {
        result += ("(" + item->name() + ")");
    }
    return result;
}

int main()
{
    srand(time(0));
    auto graph = materia::materiaGraph();
    for (auto entry : materia::LIBRARY)
    {
        graph._materias.emplace_back(entry);
    }
    // auto find =  materia::generate();

    string out{};
    vector<const materia::materia*> f;
    for (int i = 0; i < 5; i++)
    {
        // int random = rand() % materia::LIBRARY.size();
        f = materia::find(materia::LIBRARY[i]);
        out = Write(f);
        cout << ("Generated an unsolved configuration based on: \n" + materia::LIBRARY[i]->name()) << endl;
        cout << out << endl;
    }

    out = "";
    size_t s = materia::LIBRARY.size();
    int roll1 = (rand() % s);
    int roll2 = (rand() % s);
    int roll3 = (rand() % s);
    vector<materia::baseType> it = { (materia::baseType)roll1, (materia::baseType)roll2, (materia::baseType)roll3};
    cout << "Generate :" << materia::baseTypeString[it[0]] + materia::baseTypeString[it[1]] + materia::baseTypeString[it[2]] << endl;
    for (size_t i = 0; i < it.size(); i++)
    {
        f = materia::find(materia::LIBRARY[it[i]]);
        out += Write(f);
    }
    cout << out << endl;
}


