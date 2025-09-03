#include <queue>
#include <string>
#include <vector>

class Solution {
  public:
    bool isTransformable(std::string s, std::string t) {
        int n = s.size();
        std::vector<std::queue<int>> pos(10);

        for (int i = 0; i < n; ++i) {
            pos[s[i] - '0'].push(i);
        }

        for (int i = 0; i < n; ++i) {
            int digit = t[i] - '0';
            if (pos[digit].empty()) {
                return false;
            }
            for (int j = 0; j < digit; ++j) {
                if (!pos[j].empty() && pos[j].front() < pos[digit].front()) {
                    return false;
                }
            }
            pos[digit].pop();
        }

        return true;
    }
};