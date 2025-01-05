#include <vector>
#include <string>
#include <set>

class Solution {
public:
    long long calculateScore(std::string s) {
        const int alpha = (int)'a' + (int)'z';
        int n = s.size();
        long long res = 0;
        std::vector<int> pos[26];

        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'].push_back(i);
            int mirror = alpha - s[i] - 'a';
            if (!pos[mirror].empty()) {
                int j = pos[mirror].back();
                res += (i - j);
                pos[mirror].pop_back();
                pos[s[i] - 'a'].pop_back();
            }
        }

        return res;
    }
};