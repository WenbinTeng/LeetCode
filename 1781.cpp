#include <string>
#include <vector>

class Solution {
  public:
    int beautySum(std::string s) {
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            std::vector<int> cnt(26);
            int maxFreq = 0;
            for (int j = i; j < s.size(); j++) {
                cnt[s[j] - 'a']++;
                maxFreq = std::max(maxFreq, cnt[s[j] - 'a']);
                int minFreq = s.size();
                for (int k = 0; k < 26; k++) {
                    if (cnt[k] > 0) {
                        minFreq = std::min(minFreq, cnt[k]);
                    }
                }
                res += maxFreq - minFreq;
            }
        }

        return res;
    }
};