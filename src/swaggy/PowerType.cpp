#include "PowerType.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string stripQuotes(const std::string& str) {
    std::string result = str;
    result.erase(std::remove(result.begin(), result.end(), '"'), result.end());
    return result;
}

std::vector<std::string> splitCSV(const std::string& line) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string cell;
    bool inQuotes = false;
    std::string currentToken;

    for (char ch : line) {
        if (ch == '"') {
            inQuotes = !inQuotes;
        }
        else if (ch == ',' && !inQuotes) {
            result.push_back(stripQuotes(currentToken));
            currentToken.clear();
        }
        else {
            currentToken += ch;
        }
    }
    
    if (!currentToken.empty()) {
        result.push_back(stripQuotes(currentToken));
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
    
    std::getline(file, line);
    std::vector<std::string> headers = splitCSV(line);

    int lineCount = 0;
    while (std::getline(file, line)) {
        lineCount++;
        std::vector<std::string> tokens = splitCSV(line);
        PowerType pt;
        try {
            pt.powerName = tokens.size() > 0 ? tokens[0] : "";
            
            pt.powerID = tokens.size() > 1 && !tokens[1].empty() ? std::stoi(tokens[1]) : 0;
            pt.orderID = tokens.size() > 2 && !tokens[2].empty() ? std::stoi(tokens[2]) : 0;
            pt.devNotes = tokens.size() > 3 ? tokens[3] : "";
            pt.missionTags = tokens.size() > 4 ? tokens[4] : "";
            pt.priority = tokens.size() > 5 && !tokens[5].empty() ? std::stoi(tokens[5]) : 0;
            
            pt.castSoundEvent = tokens.size() > 6 ? tokens[6] : "";
            pt.hitSoundEvent = tokens.size() > 7 ? tokens[7] : "";
            pt.itemHitSoundEvent = tokens.size() > 8 ? tokens[8] : "";
            pt.targetMethod = tokens.size() > 9 ? tokens[9] : "";
            pt.parentItem = tokens.size() > 10 ? tokens[10] : "";
            pt.originPower = tokens.size() > 11 ? tokens[11] : "";
            
            pt.castTime = tokens.size() > 48 ? tokens[48] : "";
            pt.fixedRecoverTime = (tokens.size() > 49 && !tokens[49].empty()) ? std::stof(tokens[49]) : 0.0f;
            pt.recoverTime = (tokens.size() > 50 && !tokens[50].empty()) ? std::stof(tokens[50]) : 0.0f;
            pt.antigravTime = (tokens.size() > 51 && !tokens[51].empty()) ? std::stof(tokens[51]) : 0.0f;
            pt.gCancelTime = (tokens.size() > 52 && !tokens[52].empty()) ? std::stof(tokens[52]) : 0.0f;
            pt.ignoreForcedFallTime = (tokens.size() > 53 && !tokens[53].empty()) ? std::stof(tokens[53]) : 0.0f;
            pt.showCloudTime = (tokens.size() > 54 && !tokens[54].empty()) ? std::stof(tokens[54]) : 0.0f;
            pt.cooldownTime = (tokens.size() > 55 && !tokens[55].empty()) ? std::stof(tokens[55]) : 0.0f;
            
            pt.baseDamage = (tokens.size() > 68 && !tokens[68].empty()) ? std::stof(tokens[68]) : 0.0f;
            pt.variableImpulse = (tokens.size() > 69 && !tokens[69].empty()) ? std::stof(tokens[69]) : 0.0f;
            pt.fixedImpulse = (tokens.size() > 70 && !tokens[70].empty()) ? std::stof(tokens[70]) : 0.0f;
            pt.minimumImpulse = (tokens.size() > 71 && !tokens[71].empty()) ? std::stof(tokens[71]) : 0.0f;
            pt.postHitDamageMultiplier = (tokens.size() > 72 && !tokens[72].empty()) ? std::stof(tokens[72]) : 0.0f;
            pt.postHitImpulseMultiplier = (tokens.size() > 73 && !tokens[73].empty()) ? std::stof(tokens[73]) : 0.0f;
            pt.impactOffsetX = tokens.size() > 74 ? tokens[74] : "";
            pt.impactOffsetY = tokens.size() > 75 ? tokens[75] : "";
            pt.impactOffsetMaxX = tokens.size() > 76 ? tokens[76] : "";
            
            powerTypes.push_back(pt);
        }
        catch (const std::exception& e) {
            powerTypes.push_back(pt);
            std::cerr << "Warning on line " << lineCount << " (power: " << pt.powerName << "): " << e.what() << std::endl;
        }
    }

    std::cout << "Total lines processed: " << lineCount << std::endl;
    std::cout << "Total powers loaded: " << powerTypes.size() << std::endl;

    return powerTypes;
} 