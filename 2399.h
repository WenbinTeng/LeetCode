#include <string>
#include <vector>

class Solution {
public:
    bool checkDistances(std::string s, std::vector<int> &distance) {
        std::vector<int> pos(26, -1);

        for (int i = 0; i < s.size(); ++i) {
            if (pos[s[i] - 'a'] == -1) {
                pos[s[i] - 'a'] = i;
            } else {
                if (i - pos[s[i] - 'a'] - 1 != distance[s[i] - 'a'])
                    return false;
            }
        }

        return true;
    }
};