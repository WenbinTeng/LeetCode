#include <string>
#include <unordered_map>

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }

    void generate(std::string tokenId, int currentTime) {
        um[tokenId] = currentTime + timeToLive;
    }

    void renew(std::string tokenId, int currentTime) {
        if (um.count(tokenId) && um[tokenId] > currentTime) {
            um[tokenId] = currentTime + timeToLive;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for (const auto &[_, t] : um)
            if (t > currentTime)
                ++cnt;
        return cnt;
    }

private:
    int timeToLive;
    std::unordered_map<std::string, int> um;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */