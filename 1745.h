#include <string>
#include <vector>

class Solution {
public:
    bool checkPartitioning(std::string s) {
        std::vector<std::vector<bool>> flag(s.size(), std::vector<bool>(s.size()));

        for (int n = s.size(), i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                flag[i][j] = (i == j || i + 1 == j) ? s[i] == s[j] : s[i] == s[j] && flag[i + 1][j - 1];
            }
        }

        for (int i = 1; i < s.size() - 1; i++) {
            for (int j = i; j < s.size() - 1; j++) {
                if (flag[0][i - 1] && flag[i][j] && flag[j + 1][s.size() - 1]) {
                    return true;
                }
            }
        }

        return false;
    }
};