#include "swaggy/PowerType.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

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
