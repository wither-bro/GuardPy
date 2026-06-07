#include "ApiKeysManager.h"
#include <random>
#include <string>

class CreateNewApiKey {
private:
    std::string GenerateRandomString(size_t length = 16) {
        const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<> distribution(0, characters.size() - 1);

        std::string random_string;
        for (size_t i = 0; i < length; ++i) {
            random_string += characters[distribution(generator)];
        }
        return random_string;
    }

public:
    void Execute() {
        std::string newKeyId = GenerateRandomString(24);
        
        ApiKeyInfo newKey;
        newKey.keyName = "Generated Key " + std::to_string(ApiKeysManager::GetInstance().GetCachedKeys().size() + 1);
        newKey.keyId = Encryption::Encrypt(newKeyId);
        newKey.isActive = true;
        newKey.expirationTimestamp = 0; 

        ApiKeysManager::GetInstance().AddKey(newKey);
    }
};
