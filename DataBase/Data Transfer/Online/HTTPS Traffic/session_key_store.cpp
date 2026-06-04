#ifndef SESSION_KEY_STORE_H
#define SESSION_KEY_STORE_H

#include <string>
#include <vector>

class SessionKeyStore {
private:
    std::vector<unsigned char> current_session_key;

public:
    void update_key(const std::vector<unsigned char>& new_key) {
        current_session_key = new_key;
    }

    const std::vector<unsigned char>& get_key() const {
        return current_session_key;
    }

    void clear_keys() {
        current_session_key.clear();
    }
};

#endif
