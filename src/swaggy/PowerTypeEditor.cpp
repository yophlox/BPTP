#include "PowerTypeEditor.h"
#include <iostream>
#include <fstream>
#include <sstream>

PowerTypeEditor::PowerTypeEditor(const std::string& filename) {
    editBuffers = std::make_unique<EditBuffers>();
    loadPowerTypes(filename);
}

void PowerTypeEditor::loadPowerTypes(const std::string& filename) {
    powerTypes = readPowerTypes(filename);
}

void PowerTypeEditor::render() {
    ImGui::Begin("Power Type Editor");

    if (ImGui::InputText("Search", searchBuffer, sizeof(searchBuffer))) {
        for (size_t i = 0; i < powerTypes.size(); i++) {
            if (powerTypes[i].powerName.find(searchBuffer) != std::string::npos) {
                selectedIndex = i;
                break;
            }
        }
    }

    ImGui::BeginChild("left_panel", ImVec2(200, 0), true);
    for (size_t i = 0; i < powerTypes.size(); i++) {
        if (strlen(searchBuffer) == 0 || 
            powerTypes[i].powerName.find(searchBuffer) != std::string::npos) {
            
            if (ImGui::Selectable(powerTypes[i].powerName.c_str(), selectedIndex == i)) {
                selectedIndex = i;
                copyToEditBuffers(i);
                showEditor = true;
            }
        }
    }
    ImGui::EndChild();

    ImGui::SameLine();

    if (showEditor) {
        ImGui::BeginChild("right_panel", ImVec2(0, 0), true);
        renderEditor();
        ImGui::EndChild();
    }

    ImGui::End();
}

void PowerTypeEditor::copyToEditBuffers(int index) {
    const auto& pt = powerTypes[index];
    strncpy(editBuffers->powerName, pt.powerName.c_str(), sizeof(editBuffers->powerName) - 1);
    strncpy(editBuffers->powerID, std::to_string(pt.powerID).c_str(), sizeof(editBuffers->powerID) - 1);
    strncpy(editBuffers->orderID, std::to_string(pt.orderID).c_str(), sizeof(editBuffers->orderID) - 1);
    strncpy(editBuffers->devNotes, pt.devNotes.c_str(), sizeof(editBuffers->devNotes) - 1);
    strncpy(editBuffers->missionTags, pt.missionTags.c_str(), sizeof(editBuffers->missionTags) - 1);
    strncpy(editBuffers->priority, std::to_string(pt.priority).c_str(), sizeof(editBuffers->priority) - 1);
    strncpy(editBuffers->castSoundEvent, pt.castSoundEvent.c_str(), sizeof(editBuffers->castSoundEvent) - 1);
    strncpy(editBuffers->hitSoundEvent, pt.hitSoundEvent.c_str(), sizeof(editBuffers->hitSoundEvent) - 1);
    strncpy(editBuffers->itemHitSoundEvent, pt.itemHitSoundEvent.c_str(), sizeof(editBuffers->itemHitSoundEvent) - 1);
    strncpy(editBuffers->targetMethod, pt.targetMethod.c_str(), sizeof(editBuffers->targetMethod) - 1);
    strncpy(editBuffers->parentItem, pt.parentItem.c_str(), sizeof(editBuffers->parentItem) - 1);
    strncpy(editBuffers->originPower, pt.originPower.c_str(), sizeof(editBuffers->originPower) - 1);
    strncpy_s(editBuffers->castTime, sizeof(editBuffers->castTime), pt.castTime.c_str(), _TRUNCATE);
    editBuffers->fixedRecoverTime = pt.fixedRecoverTime;
    editBuffers->recoverTime = pt.recoverTime;
    editBuffers->antigravTime = pt.antigravTime;
    editBuffers->gCancelTime = pt.gCancelTime;
    editBuffers->ignoreForcedFallTime = pt.ignoreForcedFallTime;
    editBuffers->showCloudTime = pt.showCloudTime;
    editBuffers->cooldownTime = pt.cooldownTime;
    editBuffers->baseDamage = pt.baseDamage;
    editBuffers->variableImpulse = pt.variableImpulse;
    editBuffers->fixedImpulse = pt.fixedImpulse;
    editBuffers->minimumImpulse = pt.minimumImpulse;
    editBuffers->postHitDamageMultiplier = pt.postHitDamageMultiplier;
    editBuffers->postHitImpulseMultiplier = pt.postHitImpulseMultiplier;
    strncpy_s(editBuffers->impactOffsetX, sizeof(editBuffers->impactOffsetX), pt.impactOffsetX.c_str(), _TRUNCATE);
    strncpy_s(editBuffers->impactOffsetY, sizeof(editBuffers->impactOffsetY), pt.impactOffsetY.c_str(), _TRUNCATE);
    strncpy_s(editBuffers->impactOffsetMaxX, sizeof(editBuffers->impactOffsetMaxX), pt.impactOffsetMaxX.c_str(), _TRUNCATE);
}

void PowerTypeEditor::copyFromEditBuffers(int index) {
    auto& pt = powerTypes[index];
    pt.powerName = editBuffers->powerName;
    pt.powerID = std::stoi(editBuffers->powerID);
    pt.orderID = std::stoi(editBuffers->orderID);
    pt.devNotes = editBuffers->devNotes;
    pt.missionTags = editBuffers->missionTags;
    pt.priority = std::stoi(editBuffers->priority);
    pt.castSoundEvent = editBuffers->castSoundEvent;
    pt.hitSoundEvent = editBuffers->hitSoundEvent;
    pt.itemHitSoundEvent = editBuffers->itemHitSoundEvent;
    pt.targetMethod = editBuffers->targetMethod;
    pt.parentItem = editBuffers->parentItem;
    pt.originPower = editBuffers->originPower;
    pt.castTime = editBuffers->castTime;
    pt.fixedRecoverTime = editBuffers->fixedRecoverTime;
    pt.recoverTime = editBuffers->recoverTime;
    pt.antigravTime = editBuffers->antigravTime;
    pt.gCancelTime = editBuffers->gCancelTime;
    pt.ignoreForcedFallTime = editBuffers->ignoreForcedFallTime;
    pt.showCloudTime = editBuffers->showCloudTime;
    pt.cooldownTime = editBuffers->cooldownTime;
    pt.baseDamage = editBuffers->baseDamage;
    pt.variableImpulse = editBuffers->variableImpulse;
    pt.fixedImpulse = editBuffers->fixedImpulse;
    pt.minimumImpulse = editBuffers->minimumImpulse;
    pt.postHitDamageMultiplier = editBuffers->postHitDamageMultiplier;
    pt.postHitImpulseMultiplier = editBuffers->postHitImpulseMultiplier;
    pt.impactOffsetX = editBuffers->impactOffsetX;
    pt.impactOffsetY = editBuffers->impactOffsetY;
    pt.impactOffsetMaxX = editBuffers->impactOffsetMaxX;
}

void PowerTypeEditor::renderEditor() {
    if (selectedIndex < 0 || selectedIndex >= powerTypes.size()) return;

    ImGui::Text("Editing: %s", powerTypes[selectedIndex].powerName.c_str());
    ImGui::Separator();

    bool modified = false;
    
    modified |= ImGui::InputText("Power Name", editBuffers->powerName, sizeof(editBuffers->powerName));
    modified |= ImGui::InputText("Power ID", editBuffers->powerID, sizeof(editBuffers->powerID));
    modified |= ImGui::InputText("Order ID", editBuffers->orderID, sizeof(editBuffers->orderID));
    modified |= ImGui::InputTextMultiline("Dev Notes", editBuffers->devNotes, sizeof(editBuffers->devNotes));
    modified |= ImGui::InputText("Mission Tags", editBuffers->missionTags, sizeof(editBuffers->missionTags));
    modified |= ImGui::InputText("Priority", editBuffers->priority, sizeof(editBuffers->priority));
    modified |= ImGui::InputText("Cast Sound Event", editBuffers->castSoundEvent, sizeof(editBuffers->castSoundEvent));
    modified |= ImGui::InputText("Hit Sound Event", editBuffers->hitSoundEvent, sizeof(editBuffers->hitSoundEvent));
    modified |= ImGui::InputText("Item Hit Sound Event", editBuffers->itemHitSoundEvent, sizeof(editBuffers->itemHitSoundEvent));
    modified |= ImGui::InputText("Target Method", editBuffers->targetMethod, sizeof(editBuffers->targetMethod));
    modified |= ImGui::InputText("Parent Item", editBuffers->parentItem, sizeof(editBuffers->parentItem));
    modified |= ImGui::InputText("Origin Power", editBuffers->originPower, sizeof(editBuffers->originPower));

    ImGui::Separator();
    ImGui::Text("Attack Timing");
    
    modified |= ImGui::InputText("Cast Time", editBuffers->castTime, sizeof(editBuffers->castTime));
    modified |= ImGui::InputFloat("Fixed Recover Time", &editBuffers->fixedRecoverTime, 0.1f);
    modified |= ImGui::InputFloat("Recover Time", &editBuffers->recoverTime, 0.1f);
    modified |= ImGui::InputFloat("Antigrav Time", &editBuffers->antigravTime, 0.1f);
    modified |= ImGui::InputFloat("GCancel Time", &editBuffers->gCancelTime, 0.1f);
    modified |= ImGui::InputFloat("Ignore Forced Fall Time", &editBuffers->ignoreForcedFallTime, 0.1f);
    modified |= ImGui::InputFloat("Show Cloud Time", &editBuffers->showCloudTime, 0.1f);
    modified |= ImGui::InputFloat("Cooldown Time", &editBuffers->cooldownTime, 0.1f);

    ImGui::Separator();
    ImGui::Text("Damage & Impact");
    
    modified |= ImGui::InputFloat("Base Damage", &editBuffers->baseDamage, 0.5f);
    modified |= ImGui::InputFloat("Variable Impulse", &editBuffers->variableImpulse, 0.5f);
    modified |= ImGui::InputFloat("Fixed Impulse", &editBuffers->fixedImpulse, 0.5f);
    modified |= ImGui::InputFloat("Minimum Impulse", &editBuffers->minimumImpulse, 0.5f);
    modified |= ImGui::InputFloat("Post-Hit Damage Multiplier", &editBuffers->postHitDamageMultiplier, 0.1f);
    modified |= ImGui::InputFloat("Post-Hit Impulse Multiplier", &editBuffers->postHitImpulseMultiplier, 0.1f);
    modified |= ImGui::InputText("Impact Offset X", editBuffers->impactOffsetX, sizeof(editBuffers->impactOffsetX));
    modified |= ImGui::InputText("Impact Offset Y", editBuffers->impactOffsetY, sizeof(editBuffers->impactOffsetY));
    modified |= ImGui::InputText("Impact Offset Max X", editBuffers->impactOffsetMaxX, sizeof(editBuffers->impactOffsetMaxX));

    if (modified) {
        copyFromEditBuffers(selectedIndex);
    }

    if (ImGui::Button("Save Changes")) {
        savePowerTypes("powerTypes.csv");
    }
}

bool PowerTypeEditor::savePowerTypes(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return false;
    }

    file << "powerTypes\n";
    file << "PowerName,PowerID,OrderID,DevNotes,MissionTags,Priority,CastSoundEvent,HitSoundEvent,"
         << "ItemHitSoundEvent,TargetMethod,ParentItem,OriginPower\n";

    for (const auto& pt : powerTypes) {
        file << pt.powerName << ","
             << pt.powerID << ","
             << pt.orderID << ","
             << pt.devNotes << ","
             << pt.missionTags << ","
             << pt.priority << ","
             << pt.castSoundEvent << ","
             << pt.hitSoundEvent << ","
             << pt.itemHitSoundEvent << ","
             << pt.targetMethod << ","
             << pt.parentItem << ","
             << pt.originPower << "\n";
    }

    return true;
} 