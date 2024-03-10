#pragma once
#include "materia.h"
#include <map>
#include <array>
#include <stdexcept>

namespace Materia
{
    const Materia* Combine(std::vector<BaseType>* t_arg);
    const Materia PF
    {
        BaseType::Fire,
        "Ash",
    };
    const Materia PR
    {
        BaseType::Rock,
        "Hammer",
    };
    const Materia PRF
    {
        BaseType::Fire,
        "Fire Hammer"
    };
    const Materia PRW
    {
        BaseType::Water,
        "Magic Staff"
    };
    const Materia PFW
    {
        BaseType::Water,
        "Poison Juice"
    };
    const Materia PFA
    {
        BaseType::Air,
        "Toxic Cloud"
    };
    const Materia FW
    {
        BaseType::Water,
        "Steam"
    };
    const Materia FA
    {
        BaseType::Air,
        "Embers"
    };
    const Materia FWP
    {
        BaseType::Plant,
        "Steam Club"
    };
    const Materia FWA
    {
        BaseType::Air,
        "Fog"
    };
    const Materia FAR
    {
        BaseType::Rock,
        "Cannon"
    };
    const Materia FAP
    {
        BaseType::Plant,
        "Candles"
    };
    const Materia AR
    {
        BaseType::Rock,
        "Mock"
    };
    const Materia AP
    {
        BaseType::Plant,
        "Sway"
    };
    const Materia ARF
    {
        BaseType::Fire,
        "Irritate"
    };
    const Materia ARW
    {
        BaseType::Water,
        "Depress"
    };
    const Materia APR
    {
        BaseType::Rock,
        "Quake"
    };
    const Materia APF
    {
        BaseType::Fire,
        "Burn"
    };
    const Materia WP
    {
        BaseType::Plant,
        "Club"
    };
    const Materia WA
    {
        BaseType::Air,
        "Rain"
    };
    const Materia WPR
    {
        BaseType::Rock,
        "Spear"
    };
    const Materia WPF
    {
        BaseType::Fire,
        "Torch"
    };
    const Materia WAR
    {
        BaseType::Rock,
        "Hailstone"
    };
    const Materia WAP
    {
        BaseType::Plant,
        "Rain Staff"
    };
    const Materia RF
    {
        BaseType::Fire,
        "Glass"
    };
    const Materia RW
    {
        BaseType::Water,
        "Sand"
    };
    const Materia RFW
    {
        BaseType::Water,
        "Sapphire"
    };
    const Materia RFA
    {
        BaseType::Air,
        "Shatter"
    };
    const Materia RAP
    {
        BaseType::Plant,
        "Sand Staff"
    };
    const Materia RWP
    {
        BaseType::Plant,
        "Mud Slide"
    };

    const std::map<const Materia*, std::vector<BaseType>> COMBINATIONS
    {
        { &PF, {Plant, Fire}},
        { &PR, { Plant, Rock}},
        { &PRF, { Plant, Rock, Fire }},
        { &PRW, { Plant, Rock, Water }},
        { &PFW, {Plant, Fire, Water }},
        { &PFA, {Plant, Fire, Air }},
        { &FW, {Fire, Water }},
        { &FA, {Fire, Air }},
        { &FWP, {Fire, Water, Plant }},
        { &FAR, {Fire, Air, Rock }},
        { &FAP, {Fire, Air, Plant }},
        { &AR, {Air, Rock }},
        { &AP, {Air, Plant }},
        { &ARF, {Air, Rock, Fire }},
        { &ARW, {Air, Rock, Water }},
        { &APR, {Air, Rock, Rock }},
        { &APF, {Air, Rock, Fire }},
        { &WP, {Water, Plant }},
        { &WA, {Water, Air }},
        { &WPR, {Water, Plant, Rock }},
        { &WPF, {Water, Plant, Fire }},
        { &WAR, {Water, Air, Rock }},
        { &WAP, {Water, Air, Plant }},
        { &RF, {Rock, Fire }},
        { &RW, {Rock, Water }},
        { &RFW, {Rock, Fire, Water }},
        { &RFA, {Rock, Fire, Air }},
        { &RAP, {Rock, Air, Plant }},
        { &RWP, {Rock, Water, Plant }},
    };

}