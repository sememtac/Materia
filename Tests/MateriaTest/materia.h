#pragma once
#include <string>
#include <vector>

namespace materia
{
    class materia
    {
        std::string _name;
        std::vector<const materia*> _transmutes;
        std::vector<const materia*> _destroys;
    public:
        materia();
        materia(std::string name, std::vector<const materia*> transmutes, std::vector<const materia*> destroys);
        ~materia() {};
        std::string name() const
        {
            return _name;
        }
        std::vector<const materia*> transmutes() const
        {
            return _transmutes;
        }
        std::vector<const materia*> destroys() const
        {
            return _destroys;
        }
    };

    //class edge
    //{
    //    std::vector<const materia*> _src;
    //    std::vector<const materia*> _dst;
    //    edge() {};
    //    ~edge() {};
    //};

    struct graph
    {
        std::vector<const materia*> _materias;
        //std::vector<edge*> _edges;
        graph() {};
        ~graph() {};
    };

    std::vector<const materia*>generate();



}