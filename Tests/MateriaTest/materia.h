#pragma once
#include <vector>
#include <string>

namespace Materia
{
    enum Compatibility
    {
        Neutral,
        Xmute,
        Destroy,
    };

    enum BaseType
    {
        Plant,
        Fire,
        Air,
        Water,
        Rock,
    };



    class Materia
    {
    protected:
        BaseType _type;
        std::string _name;
    public:
        Materia(BaseType t_type , std::string t_arg) : _name(t_arg), _type(t_type) {}
        ~Materia() {};
        virtual std::string name() const
        {
            return _name;
        };
        virtual BaseType type() const
        {
            return _type;
        };
        Compatibility Compatible(const Materia*) const;
    };

    const Materia FIRE
    {
        Fire,
        "Fire"
    };

    const Materia WATER
    {
        Water,
        "Water",
    };
    const Materia AIR
    {
        Air,
        "Air",
    };
    const Materia ROCK
    {
        Rock,
        "Rock",
    };
    const Materia PLANT
    {
        Plant,
        "Plant",
    };


    const std::string compatibilityString[] = { "Neutral", "Xmute", "Destroy" };
    const std::string baseTypeString[] = { PLANT.name(), AIR.name(), FIRE.name(), WATER.name(), ROCK.name() };


}