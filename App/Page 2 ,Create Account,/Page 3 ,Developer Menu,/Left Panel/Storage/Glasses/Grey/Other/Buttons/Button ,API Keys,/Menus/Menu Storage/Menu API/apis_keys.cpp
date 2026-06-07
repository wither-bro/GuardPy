#include "ApiKeysManager.h"
#include <algorithm>

void ApiKeysMenu::OnRender() {
    DrawBackgroundPanel(); 

    DrawHeader("API KEYS MANAGER");
    
    if (Button("Add New Key")) {
        HandleAddNewKey();
    }

    RenderKeyList();

    RenderStatusFooter();
}

void ApiKeysMenu::RenderKeyList() {
    auto& manager = ApiKeysManager::GetInstance();
    auto keys = manager.GetCachedKeys();

    for (const auto& keyInfo : keys) {
        DrawRow(
            keyInfo.keyName,
            "****" + keyInfo.keyId.substr(keyInfo.keyId.length() - 4),
            keyInfo.isActive ? "ACTIVE" : "INACTIVE",
            ActionButtons(keyInfo)
        );
    }
}

void ApiKeysMenu::HandleAddNewKey() {
    std::string newKey = GenerateSecureToken();
    std::string encrypted = Encryption::Encrypt(newKey);
    
    ApiKeysManager::GetInstance().SaveKey(encrypted);
}
