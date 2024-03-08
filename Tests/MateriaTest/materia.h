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
        Air,
        Water,
        Rock,
    };

    const std::string compatibilityString[] = { "Neutral", "Xmute", "Destroy" };
    const std::string baseTypeString[] = { "Plant", "Wind", "Fire", "Water", "Rock" };

    class materia
    {
    protected:
        baseType _type;
        std::string _name;
    public:
        materia(baseType type , std::string arg) : _name(arg), _type(type) {}
        materia() : _type{}, _name{} {}
        ~materia() {};
        virtual std::string name() const
        {
            return _name;
        };
        virtual baseType type() const
        {
            return _type;
        };
        compatibility compatible(const materia*) const;
    };
}