#pragma once
#include "PowerType.h"
#include "../../vendor/imgui/imgui.h"
#include <vector>
#include <string>
#include <memory>

class PowerTypeEditor {
private:
    std::vector<PowerType> powerTypes;
    char searchBuffer[256] = "";
    int selectedIndex = -1;
    bool showEditor = false;
    
    struct EditBuffers {
        char powerName[256];
        char powerID[32];
        char orderID[32];
        char devNotes[1024];
        char missionTags[256];
        char priority[32];
        char castSoundEvent[256];
        char hitSoundEvent[256];
        char itemHitSoundEvent[256];
        char targetMethod[256];
        char parentItem[256];
        char originPower[256];
    };
    
    std::unique_ptr<EditBuffers> editBuffers;
    void copyToEditBuffers(int index);
    void copyFromEditBuffers(int index);
    void renderEditor();

public:
    PowerTypeEditor(const std::string& filename);
    ~PowerTypeEditor() = default;

    void render();
    bool savePowerTypes(const std::string& filename);
    void loadPowerTypes(const std::string& filename);
}; 