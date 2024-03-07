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
    private:
        std::string _name;
        std::vector<baseType> _transmutes;
        std::vector<baseType> _destroys;
        baseType _type;
    public:
        materia(baseType type, std::string name, std::vector<baseType> transmutes, std::vector<baseType> destroys);
        ~materia() {};
        std::string name() const
        {
            return _name;
        };
        std::vector<baseType> transmutes() const
        {
            return _transmutes;
        };
        std::vector<baseType> destroys() const
        {
            return _destroys;
        };
        baseType type() const
        {
            return _type;
        };
        compatibility* compatible(const materia*) const;
        const materia* operator+(const materia* arg)
        {
            compatibility* t = this->compatible(arg);
            switch (*t)
            {
            case compatibility::Destroy:
                break;
            case compatibility::Neutral:
                break;
            }
            return this;
        };
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


    class fire : public materia
    {
    public:
        using materia::materia;
    };

    class water : public materia
    {
    public:
        using materia::materia;
    };

    class wind : public materia
    {
    public:
        using materia::materia;
    };

    class plant : public materia
    {
    public:
        using materia::materia;
    };

    class rock : public materia
    {
        using materia::materia;
    };
    
    class ash :public materia
    {
        using materia::materia;
    };

}