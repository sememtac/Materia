#pragma once
#include <map>
#include <vector>
#include "materias.h"

namespace materia
{
    namespace elements 
    {
        class hammer : public rock
        {
        public:
            hammer(std::string arg) : rock(arg) {}
        };
        extern const hammer HAMMER;

        class ash : public fire
        {
        public:
            ash(std::string arg) : fire(arg) {}
        };
        extern const ash ASH;

        class fireHammer : public fire
        {
        public:
            fireHammer(std::string arg) : fire(arg) {}
        };
        extern const fireHammer FIREHAMMER;

        class magicStaff : public water
        {
        public:
            magicStaff(std::string arg) : water(arg) {}
        };
        extern const magicStaff MAGICSTAFF;

        class poisonJuice : public water
        {
        public:
            poisonJuice(std::string arg) : water(arg) {}
        };
        extern const poisonJuice POISONJUICE;

        class toxicCloud : public wind
        {
        public:
            toxicCloud(std::string arg) : wind(arg) {}
        };
        extern const toxicCloud TOXICCLOUD;

        class steam : public water
        {
        public:
            steam(std::string arg) : water(arg) {}
        };
        extern const steam STEAM;

        class embers : public wind
        {
        public:
            embers(std::string arg) : wind(arg) {}
        };
        extern const embers EMBERS;

        class steamClub : public plant
        {
        public:
            steamClub(std::string arg) : plant(arg) {}
        };
        extern const steamClub STEAMCLUB;

        class fog : public wind
        {
        public:
            fog(std::string arg) : wind(arg) {}
        };
        extern const fog FOG;

        class cannon : public rock
        {
        public:
            cannon(std::string arg) : rock(arg) {}
        };
        extern const cannon CANNON;

        class candles : public plant
        {
        public:
            candles(std::string arg) : plant(arg) {}
        };
        extern const candles CANDLES;
        
        class mock : public rock
        {
        public:
            mock(std::string arg) : rock(arg) {}
        };
        extern const mock MOCK;

        class sway : public plant
        {
        public:
            sway(std::string arg) : plant(arg) {}
        };
        extern const sway SWAY;

        class irritate : public fire
        {
        public:
            irritate(std::string arg) : fire(arg) {}
        };
        extern const irritate IRRITATE;

        const std::map<const materia*, std::vector<const materia*>> COMBINATIONS
        {
            { &HAMMER, { &PLANT, &ROCK }},
            { &ASH, { &PLANT, &FIRE }},
            { &FIREHAMMER, { &PLANT, &ROCK, &FIRE }},
            { &MAGICSTAFF, { &PLANT, &ROCK, &WATER }},
            { &POISONJUICE, {&PLANT, &FIRE, &WATER }},
            { &TOXICCLOUD, { &PLANT, &FIRE, &WIND }},
            { &STEAM, {&FIRE, &WATER }},
            { &EMBERS, {&FIRE, &WIND }},
            { &STEAMCLUB, {&FIRE, &WATER, &PLANT }},
            { &CANNON, {&FIRE, &WIND, &ROCK }},
            { &CANDLES,{&FIRE, &WIND, &PLANT }},
            { &MOCK, {&WIND, &ROCK }},
            { &SWAY, {&WIND, &PLANT }},
            { &IRRITATE, {&WIND, &ROCK, &FIRE }},
        };


    }

    static const std::map<const materia*, std::vector<const materia*>>* combinations()
    {
        return &(elements::COMBINATIONS);
    }
}