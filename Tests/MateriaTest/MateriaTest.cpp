#include <iostream>
#include "main.h"

int main()
{
    auto graph = materia::graph();
    for (auto entry : materia::LIBRARY)
    {
        graph._materias.emplace_back(entry);
    }
    // auto find =  materia::generate();

    auto f = materia::find(materia::LIBRARY[3]);
    std::cout << "Hello World!\n";
}
