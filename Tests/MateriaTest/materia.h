#pragma once
#include <vector>
#include <string>

namespace materia
{
    enum compatibility
    {
        Neutral,
        Xmute,
        Destroy,
    };

    enum baseType
    {
        Plant,
        Fire,
        Wind,
        Water,
        Rock,
    };

    const std::string baseTypeString[] = { "Plant", "Wind", "Fire", "Water", "Rock" };

    class materia
    {
    protected:
        std::vector<const materia*> _transmutes;
        std::vector<const materia*> _destroys;
        baseType _type;
        std::string _name;
    public:
        materia(baseType type, std::string name, std::vector<const materia*> transmute, std::vector<const materia*> destroy) :
            _type(type), _name(name), _transmutes(transmute), _destroys(destroy) {}
        materia(std::string arg) : _name(arg), _type{}, _transmutes{}, _destroys{} {}
        materia() : _name{}, _type{}, _transmutes{}, _destroys{} {}
        ~materia() {};
        std::string name() const
        {
            return _name;
        };
        std::vector<const materia*> transmutes() const
        {
            return _transmutes;
        };
        std::vector<const materia*> destroys() const
        {
            return _destroys;
        };
        baseType type() const
        {
            return _type;
        };
        compatibility compatible(const materia*) const;
    };

    //class edge
    //{
    //    std::vector<const materia*> _src;
    //    std::vector<const materia*> _dst;
    //    edge() {};
    //    ~edge() {};
    //};

    struct materiaGraph
    {
        std::vector<const materia*> _materias;
        materiaGraph() {};
        ~materiaGraph() {};
    };
}