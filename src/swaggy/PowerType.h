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
    
    // Timing fields
    std::string castTime;      // Initial startup frames
    float fixedRecoverTime;    // Fixed recovery time
    float recoverTime;         // Additional recovery time
    float antigravTime;        // Time where gravity is ignored
    float gCancelTime;         // Time window for gravity cancel
    float ignoreForcedFallTime;// Time to ignore forced falling
    float showCloudTime;       // Visual effect timing
    float cooldownTime;        // Time before move can be used again
    
    // Damage fields
    float baseDamage;
    float variableImpulse;
    float fixedImpulse;
    float minimumImpulse;
    float postHitDamageMultiplier;
    float postHitImpulseMultiplier;
    std::string impactOffsetX;  // Can be like "0,0" or complex values
    std::string impactOffsetY;
    std::string impactOffsetMaxX;
};

std::vector<PowerType> readPowerTypes(const std::string& filename);