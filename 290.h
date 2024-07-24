#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::vector<std::string> words;
        std::stringstream ss(s);
        std::string token;
        std::unordered_map<char, std::string> p2s;
        std::unordered_map<std::string, char> s2p;

        while (ss >> token) {
            words.emplace_back(token);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++) {
            if ((p2s.count(pattern[i]) && p2s[pattern[i]] != words[i]) || (s2p.count(words[i]) && s2p[words[i]] != pattern[i])) {
                return false;
            }
            p2s[pattern[i]] = words[i];
            s2p[words[i]] = pattern[i];
        }
        
        return true;
    }
};