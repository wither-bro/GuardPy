#pragma once

#include <string>

class ApiKeysLogic {
public:
    static bool HasActiveKeys();
    static bool ValidateKeyIntegrity(const std::string& keyId);
    static void RefreshStates();
    static void CreateInitialKey(bool withChat);
};
