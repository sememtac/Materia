#pragma once
#include "materia.h"

namespace materia
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
    
    namespace combinations
    {
        namespace fire
        {
            class ash : public fire
            {
            public:
                ash(std::string arg) : fire(arg) {}
            };
        }

        namespace water
        {

        }

        namespace wind
        {

        }

        namespace plant
        {

        }

        namespace rock
        {
            class hammer : public rock
            {
            public:
                hammer(std::string arg) : rock(arg) {}
            };

            class boulder : public rock
            {
            public:
                boulder(std::string arg) : rock(arg) {}
            };
        }

        
    }

    




}