#include <string>

class Solution {
  public:
    int minTimeToType(std::string word) {
        int res = 0;
        char prev = 'a';

        for (auto &c : word) {
            int dist = std::min((prev - c + 26) % 26, (c - prev + 26) % 26);
            res += dist + 1;
            prev = c;
        }

        return res;
    }
};