#pragma once
#include <map>
#include <vector>
#include "core.h"

namespace materia
{
    namespace elements 
    {
        class combination : public materia
        {
        public:
            using materia::materia;
        };

        extern const combination PR, PF, PRF, PRW, PFW, PFA, FW ,FA, FWP, FWA, FAR, FAP, 
            AR, AP, ARF, ARW, APR, APF, WP, WA, WPR, WPF, WAR, WAP, RF, RW, RFW, RFA, RAP, RWP;

        const std::map<const combination*, std::vector<const element*>> COMBINATIONS
        {
            { &PR, { &PLANT, &ROCK }},
            { &PF, { &PLANT, &FIRE }},
            { &PRF, { &PLANT, &ROCK, &FIRE }},
            { &PRW, { &PLANT, &ROCK, &WATER }},
            { &PFW, {&PLANT, &FIRE, &WATER }},
            { &PFA, { &PLANT, &FIRE, &AIR }},
            { &FW, {&FIRE, &WATER }},
            { &FA, {&FIRE, &AIR }},
            { &FWP, {&FIRE, &WATER, &PLANT }},
            { &FAR, {&FIRE, &AIR, &ROCK }},
            { &FAP,{&FIRE, &AIR, &PLANT }},
            { &AR, {&AIR, &ROCK }},
            { &AP, {&AIR, &PLANT }},
            { &ARF, {&AIR, &ROCK, &FIRE }},
            { &ARW, {&AIR, &ROCK, &WATER }},
            { &APR, {&AIR, &PLANT, &ROCK }},
            { &APF, {&AIR, &PLANT, &FIRE }},
            { &WP, {&WATER, &PLANT }},
            { &WA, {&WATER, &AIR }},
            { &WPR, {&WATER, &PLANT, &ROCK }},
            { &WPF, {&WATER, &PLANT, &FIRE }},
            { &WAR, {&WATER, &AIR, &ROCK }},
            { &WAP, {&WATER, &AIR, &PLANT }},
            { &RF, {&ROCK, &FIRE, }},
            { &RW, {&ROCK, &WATER, }},
            { &RFW, {&ROCK, &FIRE, &WATER }},
            { &RFA, {&ROCK, &FIRE, &AIR }},
            { &RAP, {&ROCK, &AIR, &PLANT }},
            { &RWP, {&ROCK, &WATER, &PLANT }},
        };
    }

    static const std::map<const elements::combination*, std::vector<const elements::element*>>* combinations()
    {
        return &(elements::COMBINATIONS);
    }
}