#pragma once

#include <string>
#include <vector>

struct ApiKeyInfo {
    std::string keyName;
    std::string keyId;
    bool isActive = false;
    long long expirationTimestamp = 0;
};

struct Encryption {
    static std::string Encrypt(const std::string& input) {
        return input;
    }

    static std::string Decrypt(const std::string& input) {
        return input;
    }
};

class ApiKeysManager {
public:
    static ApiKeysManager& GetInstance() {
        static ApiKeysManager instance;
        return instance;
    }

    std::vector<ApiKeyInfo>& GetCachedKeys() {
        return keys;
    }

    void AddKey(const ApiKeyInfo& key) {
        keys.push_back(key);
    }

private:
    ApiKeysManager() = default;
    ~ApiKeysManager() = default;
    ApiKeysManager(const ApiKeysManager&) = delete;
    ApiKeysManager& operator=(const ApiKeysManager&) = delete;

    std::vector<ApiKeyInfo> keys;
};
