#include <string>
#include <vector>

class Solution {
public:
    bool areAlmostEqual(std::string s1, std::string s2) {
        std::vector<int> rec;

        for (int i = 0; i < s1.size() && i < s2.size() && rec.size() <= 2; ++i) {
            if (s1[i] != s2[i]) {
                rec.push_back(i);
            }
        }

        return rec.empty() || rec.size() == 2 && s1[rec[0]] == s2[rec[1]] && s1[rec[1]] == s2[rec[0]];
    }
};