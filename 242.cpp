#include <string>
#include <unordered_map>

class Solution {
  public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::unordered_map<char, int> dict;

        for (int i = 0; i < s.size(); i++) {
            dict[s[i]]++;
            dict[t[i]]--;
        }

        for (const auto [_, v] : dict) {
            if (v != 0) {
                return false;
            }
        }

        return true;
    }
};