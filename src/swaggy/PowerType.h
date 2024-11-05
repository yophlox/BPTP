#pragma once
#include <string>
#include <vector>

struct PowerType {
    std::string powerName;
    int powerID;
    int orderID;
    std::string devNotes;
    std::string missionTags;
    int priority;
    std::string castSoundEvent;
    std::string hitSoundEvent;
    std::string itemHitSoundEvent;
    std::string targetMethod;
    std::string parentItem;
    std::string originPower;
};

std::vector<PowerType> readPowerTypes(const std::string& filename);