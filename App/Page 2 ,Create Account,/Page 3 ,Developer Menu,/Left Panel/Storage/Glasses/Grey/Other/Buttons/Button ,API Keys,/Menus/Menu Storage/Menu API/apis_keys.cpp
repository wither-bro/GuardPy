#include "ApiKeysManager.h"
#include "CreateNewApiKey.cpp"
#include "CopyApiKey.cpp"
#include <algorithm>

void ApiKeysMenu::OnRender(sf::RenderWindow& window) {
    DrawBackgroundPanel(); 

    DrawHeader("API KEYS MANAGER");
    
    if (Button("Add New Key")) {
        CreateNewApiKey creator;
        creator.Execute();
    }

    RenderKeyList(window);

    copier.Update();
    copier.Draw(window);

    RenderStatusFooter();
}

void ApiKeysMenu::RenderKeyList(sf::RenderWindow& window) {
    auto& manager = ApiKeysManager::GetInstance();
    auto keys = manager.GetCachedKeys();

    for (const auto& keyInfo : keys) {
        if (DrawRow(keyInfo.keyName, 
                    "****" + keyInfo.keyId.substr(keyInfo.keyId.length() - 4), 
                    keyInfo.isActive ? "ACTIVE" : "INACTIVE", 
                    ActionButtons(keyInfo))) 
        {
            if (IsRowClicked(keyInfo)) {
                std::string decryptedKey = Encryption::Decrypt(keyInfo.keyId);
                copier.CopyToClipboard(decryptedKey);
            }
        }
    }
}

void ApiKeysMenu::HandleAddNewKey() {
    CreateNewApiKey creator;
    creator.Execute();
}
