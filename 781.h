#include <unordered_map>
#include <vector>

class Solution {
public:
    int numRabbits(std::vector<int> &answers) {
        int res = 0;
        std::unordered_map<int, int> um;

        for (const auto &answer : answers) {
            if (um[answer] == answer + 1) {
                um[answer] = 1;
                res += answer + 1;
            } else {
                um[answer] += 1;
            }
        }

        for (const auto &[answer, count] : um) {
            res += answer + 1;
        }

        return res;
    }
};