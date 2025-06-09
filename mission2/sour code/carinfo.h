#pragma once

#include <map>
#include <string>

enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK
};

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA,
    BROKEN,
};

enum BrakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS
};

const std::map<Engine, std::string> engineTypeStr =
{
    {GM, "GM"},
    {TOYOTA, "TOYOTA"},
    {WIA, "WIA"}
};

const std::map<BrakeSystem, std::string> brakeTypeStr =
{
    {MANDO, "MANDO"},
    {CONTINENTAL, "CONTINENTAL"},
    {BOSCH_B, "BOSCH"}
};

const std::map<SteeringSystem, std::string> steeringTypeStr =
{
    {BOSCH_S, "BOSCH"},
    {MOBIS, "MOBIS"}
};
