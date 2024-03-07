#include <iostream>
#include "main.h"

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
    srand(0);
    auto graph = materia::materiaGraph();
    for (auto entry : materia::LIBRARY)
    {
        graph._materias.emplace_back(entry);
    }
    // auto find =  materia::generate();

    for (int i = 0; i < 4; i++)
    {
        int random = rand() % materia::LIBRARY.size();
        vector<const materia::materia*> f = materia::find(materia::LIBRARY[random]);
        string out = Write(f);
        cout << ("Generated an unsolved configuration based on: \n" + materia::LIBRARY[random]->name()) << endl;
        cout << out << endl;
    }
}


