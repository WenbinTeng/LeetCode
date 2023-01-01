#include <string>
#include <unordered_map>

class Solution {
public:
    int rearrangeCharacters(std::string s, std::string target) {
        int res = 0;
        std::unordered_map<char, int> um1;
        std::unordered_map<char, int> um2;

        for (const auto c : s) {
            ++um1[c];
        }

        for (const auto c : target) {
            ++um2[c];
        }

        while (true) {
            for (auto [c, cnt] : um2) {
                if (um1[c] >= cnt) {
                    um1[c] -= cnt;
                } else {
                    return res;
                }
            }

            ++res;
        }

        return -1;
    }
};