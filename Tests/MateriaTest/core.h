#pragma once
#include "materia.h"
#include <map>

namespace materia
{
    namespace elements
    {
        class element : public materia
        {
        protected:
            std::vector<const element*> _transmutes;
            std::vector<const element*> _destroys;
        public:
            element(baseType type, std::string name, std::vector<const element*> transmute, std::vector<const element*> destroy)
            {
                _type = type;
                _name = name;
                _transmutes = transmute;
                _destroys = destroy;
            }

            std::vector<const element*> transmutes() const
            {
                return _transmutes;
            };

            std::vector<const element*> destroys() const
            {
                return _destroys;
            };

            bool operator==(const element* arg) const
            {
                return this == arg;
            }
        };

        extern const element PLANT;
        extern const element AIR;
        extern const element FIRE;
        extern const element WATER;
        extern const element ROCK;

        const std::vector<const element*> CORE
        {
            &PLANT,& FIRE,& AIR ,& WATER,& ROCK,
        };

        static const element* Fire()
        {
            return &FIRE;
        };
        static const element* Water()
        {
            return &WATER;
        }
        static const element* Rock()
        {
            return &ROCK;
        }
        static const element* Wind()
        {
            return &AIR;
        }
        static const element* Plant()
        {
            return &PLANT;
        }

        static const std::vector<const element*>* library()
        {
            return &CORE;
        }
    }
}
