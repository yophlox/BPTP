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
            pt.powerName = tokens[0];
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
            
            powerTypes.push_back(pt);
        }
        catch (const std::exception& e) {
            std::cerr << "Error parsing line " << lineCount << ": " << e.what() << std::endl;
            continue;
        }
    }

    std::cout << "Total lines processed: " << lineCount << std::endl;
    std::cout << "Total powers loaded: " << powerTypes.size() << std::endl;

    return powerTypes;
} 