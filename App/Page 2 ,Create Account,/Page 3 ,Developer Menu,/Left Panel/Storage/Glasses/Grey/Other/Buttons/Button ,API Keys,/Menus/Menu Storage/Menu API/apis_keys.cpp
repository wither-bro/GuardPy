#include "ApiKeysManager.h"
#include "create_new_api_key.cpp"
#include "copy_api_key.cpp"
#include <algorithm>

class ApiKeysMenu {
public:
    void OnRender(sf::RenderWindow& window);
    void RenderKeyList(sf::RenderWindow& window);
    void HandleAddNewKey();
};

static sf::Font g_apiKeysFont;
static CopyApiKey copier(g_apiKeysFont);

void DrawBackgroundPanel() {}
void DrawHeader(const std::string&) {}
bool Button(const std::string&) { return false; }
void RenderStatusFooter() {}
bool DrawRow(const std::string&, const std::string&, const std::string&, bool) { return false; }
bool ActionButtons(const ApiKeyInfo&) { return false; }
bool IsRowClicked(const ApiKeyInfo&) { return false; }

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
