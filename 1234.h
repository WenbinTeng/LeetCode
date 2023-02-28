#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int balancedString(std::string s) {
        int res = s.size();
        int len = s.size() / 4;
        std::unordered_map<char, int> cnt;

        for (const auto c : s) {
            cnt[c]++;
        }

        if (cnt['Q'] == len && cnt['W'] == len && cnt['E'] == len && cnt['R'] == len)
            return 0;

        for (int l = 0, r = 0; r < s.size(); ++r) {
            cnt[s[r]]--;
            while (cnt['Q'] <= len && cnt['W'] <= len && cnt['E'] <= len && cnt['R'] <= len) {
                res = std::min(res, r - l + 1);
                cnt[s[l]]++;
                l++;
            }
        }

        return res;
    }
};