#include "ApiKeysManager.h"

bool ApiKeysLogic::HasActiveKeys() {
    auto& manager = ApiKeysManager::GetInstance();
    auto keys = manager.GetCachedKeys();
    
    if (keys.empty()) {
        return false;
    }

    for (const auto& key : keys) {
        if (key.isActive) {
            return true;
        }
    }
    
    return false;
}

bool ApiKeysLogic::ValidateKeyIntegrity(const std::string& keyId) {
    if (keyId.length() < 8) {
        return false;
    }
    
    return true;
}

void ApiKeysLogic::RefreshStates() {
    auto& manager = ApiKeysManager::GetInstance();
    auto keys = manager.GetCachedKeys();
    
    for (auto& key : keys) {
        if (key.keyId.empty()) {
            key.isActive = false;
        }
    }
}
