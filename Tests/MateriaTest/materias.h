#pragma once
#include "materia.h"
#include "classes.h"
#include <map>

namespace materia
{
    namespace elements
    {
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
        // Define materia property here
        //const materia EXAMPLE
        //{
        //	"Example",
        //	{},
        //	{}
        //};
        
        extern const plant PLANT;
        extern const wind WIND;
        extern const fire FIRE;
        extern const water WATER;
        extern const rock ROCK;


        const std::vector<const materia*> CORE_LIBRARY
        {
            {
                &PLANT, &FIRE, &WIND , &WATER, &ROCK,
            }
        };


        static const materia* Fire()
        {
            return &FIRE;
        };
        static const materia* Water()
        {
            return &WATER;
        }
        static const materia* Rock()
        {
            return &ROCK;
        }
        static const materia* Wind()
        {
            return &WIND;
        }
        static const materia* Plant()
        {
            return &PLANT;
        }

        static const std::vector<const materia*>* library()
        {
            return &CORE_LIBRARY;
        }

        static const std::vector<const materia*> core()
        {
            return { &FIRE, &WATER, &ROCK, &WIND, &PLANT };
        }
    }


}
