#include <string>
#include <unordered_map>

class Solution {
  public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> dict;

        for (const auto c : magazine) {
            dict[c]++;
        }
        for (const auto c : ransomNote) {
            if (dict[c] == 0) {
                return false;
            }
            dict[c]--;
        }

        return true;
    }
};