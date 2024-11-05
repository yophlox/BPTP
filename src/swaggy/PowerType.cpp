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

    while (std::getline(file, line)) {
        std::vector<std::string> tokens = splitCSV(line);
        if (tokens.size() < 12) {
            std::cerr << "Warning: Skipping malformed line: " << line << std::endl;
            continue;
        }

        PowerType pt;
        try {
            pt.powerName = tokens[0];
            pt.powerID = std::stoi(tokens[1]);
            pt.orderID = std::stoi(tokens[2]);
            pt.devNotes = tokens[3];
            pt.missionTags = tokens[4];
            pt.priority = std::stoi(tokens[5]);
            pt.castSoundEvent = tokens[6];
            pt.hitSoundEvent = tokens[7];
            pt.itemHitSoundEvent = tokens[8];
            pt.targetMethod = tokens[9];
            pt.parentItem = tokens[10];
            pt.originPower = tokens[11];
            pt.castTime = tokens[48];
            pt.fixedRecoverTime = tokens[49].empty() ? 0.0f : std::stof(tokens[49]);
            pt.recoverTime = tokens[50].empty() ? 0.0f : std::stof(tokens[50]);
            pt.antigravTime = tokens[51].empty() ? 0.0f : std::stof(tokens[51]);
            pt.gCancelTime = tokens[52].empty() ? 0.0f : std::stof(tokens[52]);
            pt.ignoreForcedFallTime = tokens[53].empty() ? 0.0f : std::stof(tokens[53]);
            pt.showCloudTime = tokens[54].empty() ? 0.0f : std::stof(tokens[54]);
            pt.cooldownTime = tokens[55].empty() ? 0.0f : std::stof(tokens[55]);
            powerTypes.push_back(pt);
        }
        catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << "\nError: " << e.what() << std::endl;
            continue;
        }
    }

    return powerTypes;
} 