#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct PowerType {
    std::string name;
    int id;
    int category;
    std::string description;
    std::string tags;
    std::string sfxTrigger;
    std::string sfxHit;
    std::string sfxBlock;
    std::string powerGroup;
    std::string weaponGroup;
    std::string parentPower;
    bool isProjectile;
    bool isCharge;
    std::vector<int> hitWidth;
    std::vector<int> hitHeight;
    std::vector<int> hitOffsetX;
    std::vector<int> hitOffsetY;
    std::vector<int> moveX;
    std::vector<int> moveY;
    std::string hitStopSelf;
    std::string hitStopTarget;
    std::string hitLag;
    bool canHitMultiple;
    bool canHitSelf;
    bool canHitTeammates;
    bool canHitStunned;
    bool ignoresGrabInvuln;
    bool ignoresInvuln;
    bool doesNotCollide;
    std::string specialEffect;
    std::string animation;
    std::string hitboxActiveFrames;
    int startupFrames;
    int recoveryFrames;
    int projectileSpeed;
    int projectileAcceleration;
    int projectileMaxSpeed;
    int projectileDuration;
    int projectileQuantity;
    int projectileSpread;
    int projectileStagger;
    int projectileStartX;
    int projectileStartY;
    int projectileFireAngle;
    bool projectileFireRandomAngle;
    int projectileRotationSpeed;
    int projectileMaxBounces;
    std::string projectileHitEffect;
    std::string projectileNoHitEffect;
    std::string projectileDestroyEffect;
    std::string projectileDestroyEffectTime;
    int baseDamage;
    int minDamage;
    int maxDamage;
    int baseKnockback;
    int knockbackGrowth;
    int knockbackCap;
    int knockbackType;
    int angle;
    int angleFlip;
    int weight;
    bool resetHitstun;
    bool resetKnockbackDecay;
    std::string hitEffectTemplate;
    std::string blockEffectTemplate;
    std::string hitSoundEffect;
    std::string blockSoundEffect;
    std::string hitLagSoundEffect;
    std::string chargeSoundEffect;
    std::string projectileSoundEffect;
    std::string loopSoundEffect;
    std::string rumbleEffect;
    std::string hitGroundEffect;
    std::string persistentHitEffect;
    int reflectDamageMultiplier;
    int reflectKnockbackMultiplier;
    bool canBeReflected;
    bool canBeAbsorbed;
    int absorbAmount;
    bool canClank;
    int clankedByPriority;
    int priority;
    bool piercesShield;
    int shieldDamageMultiplier;
    bool breaksShield;
    bool canGrab;
    std::string grabEffect;
    std::string throwEffect;
    int throwDamage;
    int throwKnockbackGrowth;
    int throwKnockbackBase;
    int throwAngle;
    int throwSpeed;
    int throwTechDistance;
    int throwRange;
    int throwInvincibility;
    bool isThrowTech;
    std::string altThrowEffect;
    int altThrowDamage;
    int altThrowKnockbackGrowth;
    int altThrowKnockbackBase;
    int altThrowAngle;
    std::string commandGrabEffect;
    int commandGrabDamage;
    int commandGrabKnockbackGrowth;
    int commandGrabKnockbackBase;
    int commandGrabAngle;
    bool isCounter;
    std::string counterEffect;
    int counterMultiplier;
    int counterKnockbackMultiplier;
    int counterDuration;
    bool isInvulnerable;
    bool isArmored;
    int armorAmount;
    bool isUninterruptible;
    bool isSuperArmored;
    int superArmorAmount;
    bool isIntangible;
    std::string landingLag;
    std::string landingLagHeavy;
    bool canEdgeCancel;
    bool canB_Reverse;
    bool canWaveBounce;
    bool canFastFall;
    bool canWallJump;
    bool wallJumpHorizontal;
    bool wallJumpVertical;
    std::string airType;
    std::string landType;
    std::string specialType;
    std::string specialInfo;
    std::string grabBoxes;
    std::string hurtBoxes;
    std::string windboxes;
    std::string commandGrabBoxes;
    std::string ledgeGrabBoxes;
    std::string reflectBoxes;
    std::string absorbBoxes;
    std::string counterBoxes;
    std::string specialScript;
    std::string onHitScript;
    std::string onBlockScript;
    std::string onStartupScript;
    std::string onActiveScript;
    std::string onEndScript;
    std::string persistentScript;
    std::string projectileScript;
    std::string projectileDestroyScript;
    std::string projectileHitScript;
    std::string projectileBlockScript;
    std::string projectileActiveScript;
    std::string projectileEndScript;
    std::string altInputScript;
    std::string chargeScript;
    std::string releaseScript;
    std::string whiffScript;
    std::string hitScript;
    std::string blockScript;
    std::string grabScript;
    std::string throwScript;
    std::string commandGrabScript;
    std::string counterScript;
    std::string reflectScript;
    std::string absorbScript;
    std::string spikeScript;
    std::string sweetspotScript;
    std::string sourspotScript;
    std::string tipper;
    std::string sourspot;
    std::string sweetspot;
    bool canHitCanceled;
    std::string cancelsInto;
    bool canBeParried;
    bool canBeTechedOff;
    bool ignoresDI;
    bool ignoresLSI;
    bool ignoresHitstunModifier;
    bool ignoresShieldPushback;
    bool ignoresGrabArmor;
    bool ignoresWeight;
    bool ignoresStaleness;
    bool ignoresInvincibility;
    bool ignoresIntangibility;
    bool ignoresRebound;
    bool ignoresShieldstun;
    bool ignoresShieldDamage;
    bool ignoresShieldPush;
    bool ignoresShieldTilt;
    bool ignoresShieldSizeMultiplier;
    bool ignoresShieldDamageMultiplier;
    bool ignoresShieldStunMultiplier;
    bool ignoresShieldPushMultiplier;
    bool ignoresShieldTiltMultiplier;
    bool ignoresShieldSizeMultiplierMultiplier;
    bool ignoresShieldDamageMultiplierMultiplier;
    bool ignoresShieldStunMultiplierMultiplier;
    bool ignoresShieldPushMultiplierMultiplier;
    bool ignoresShieldTiltMultiplierMultiplier;
    bool ignoresShieldSizeMultiplierMultiplierMultiplier;
    bool ignoresShieldDamageMultiplierMultiplierMultiplier;
    bool ignoresShieldStunMultiplierMultiplierMultiplier;
    bool ignoresShieldPushMultiplierMultiplierMultiplier;
    bool ignoresShieldTiltMultiplierMultiplierMultiplier;
    std::string hitSpark;
    std::string blockSpark;
    std::string clankSpark;
    std::string reflectSpark;
    std::string absorbSpark;
    std::string counterSpark;
    std::string grabSpark;
    std::string throwSpark;
    std::string commandGrabSpark;
    std::string spikeEffect;
    std::string sweetspotEffect;
    std::string sourspotEffect;
    std::string tipperEffect;
    std::string hitParticles;
    std::string blockParticles;
    std::string clankParticles;
    std::string reflectParticles;
    std::string absorbParticles;
    std::string counterParticles;
    std::string grabParticles;
    std::string throwParticles;
    std::string commandGrabParticles;
    std::string spikeParticles;
    std::string sweetspotParticles;
    std::string sourspotParticles;
    std::string tipperParticles;
    std::string projectileSprite;
    std::string projectileSpriteFacing;
    int projectileSpriteFrames;
    bool projectileSpriteLoop;
    int projectileSpriteFrameRate;
    std::string projectileSpritePalette;
    std::string projectileSpritePaletteSwap;
    std::string projectileSpritePaletteSwapSlot;
    std::string projectileSpritePaletteSwapSlotIndex;
    std::string projectileTrailSprite;
    std::string projectileTrailSpriteFacing;
    int projectileTrailSpriteFrames;
    bool projectileTrailSpriteLoop;
    int projectileTrailSpriteFrameRate;
    std::string projectileTrailSpritePalette;
    std::string projectileTrailSpritePaletteSwap;
    std::string projectileTrailSpritePaletteSwapSlot;
    std::string projectileTrailSpritePaletteSwapSlotIndex;
    std::string projectileDestroySprite;
    std::string projectileDestroySpriteFacing;
    int projectileDestroySpriteFrames;
    bool projectileDestroySpriteLoop;
    int projectileDestroySpriteFrameRate;
    std::string projectileDestroySpritePalette;
    std::string projectileDestroySpritePaletteSwap;
    std::string projectileDestroySpritePaletteSwapSlot;
    std::string projectileDestroySpritePaletteSwapSlotIndex;
    std::string projectileHitSprite;
    std::string projectileHitSpriteFacing;
    int projectileHitSpriteFrames;
    bool projectileHitSpriteLoop;
    int projectileHitSpriteFrameRate;
    std::string projectileHitSpritePalette;
    std::string projectileHitSpritePaletteSwap;
    std::string projectileHitSpritePaletteSwapSlot;
    std::string projectileHitSpritePaletteSwapSlotIndex;
};

std::string stripQuotes(const std::string& str) {
    std::string result = str;
    result.erase(std::remove(result.begin(), result.end(), '"'), result.end());
    return result;
}

std::vector<std::string> splitCSV(const std::string& line) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string cell;

    while (std::getline(ss, cell, ',')) {
        result.push_back(stripQuotes(cell));
    }

    return result;
}

std::vector<PowerType> readPowerTypes(const std::string& filename) {
    std::vector<PowerType> powerTypes;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return powerTypes;
    }

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> tokens = splitCSV(line);
        if (tokens.size() < 3) {
            std::cerr << "Skipping malformed line: " << line << std::endl;
            continue;
        }

        PowerType powerType;
        try {
            powerType.name = tokens[0];
            powerType.id = std::stoi(tokens[1]);
            powerType.category = std::stoi(tokens[2]);
            powerType.description = tokens[3];
            powerType.tags = tokens[4];
            powerType.sfxTrigger = tokens[5];
            powerType.sfxHit = tokens[6];
            powerType.sfxBlock = tokens[7];
            powerType.powerGroup = tokens[8];
            powerType.weaponGroup = tokens[9];
            powerType.parentPower = tokens[10];
        }
        catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << std::endl;
            std::cerr << "Error: " << e.what() << std::endl;
            continue;
        }

        powerTypes.push_back(powerType);
    }

    file.close();
    return powerTypes;
}

void printPowerType(const PowerType& pt) {
    std::cout << "Name: " << pt.name << "\n"
        << "ID: " << pt.id << "\n"
        << "Category: " << pt.category << "\n"
        << "Description: " << pt.description << "\n"
        << "Tags: " << pt.tags << "\n"
        << "SFX Trigger: " << pt.sfxTrigger << "\n"
        << "SFX Hit: " << pt.sfxHit << "\n"
        << "SFX Block: " << pt.sfxBlock << "\n"
        << "Power Group: " << pt.powerGroup << "\n"
        << "Weapon Group: " << pt.weaponGroup << "\n"
        << "Parent Power: " << pt.parentPower << "\n";
}

int main() {
    std::string filename = "powerTypes.csv";
    std::vector<PowerType> powerTypes = readPowerTypes(filename);

    std::cout << "Parsed " << powerTypes.size() << " power types." << std::endl;
   std::cout << "\nFirst entry:" << std::endl;
    for (size_t i = 0; i < std::min(powerTypes.size(), size_t(1)); ++i) {
        printPowerType(powerTypes[i]);
    }

    std::string searchName;
    while (true) {
        std::cout << "\nEnter a power type name to search (or 'quit' to exit): ";
        std::getline(std::cin, searchName);

        if (searchName == "quit") break;

        auto it = std::find_if(powerTypes.begin(), powerTypes.end(),
            [&searchName](const PowerType& pt) {
                return pt.name == searchName;
            });

        if (it != powerTypes.end()) {
            std::cout << "\nFound power type:\n";
            printPowerType(*it);
        }
        else {
            std::cout << "Power type not found.\n";
        }
    }

    return 0;
}