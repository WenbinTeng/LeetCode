#include <string>
#include <unordered_set>

class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        int res = 0;
        std::unordered_set<char> us;

        for (const auto jewel : jewels) {
            us.insert(jewel);
        }

        for (const auto stone : stones) {
            if (us.count(stone)) {
                res++;
            }
        }

        return res;
    }
};