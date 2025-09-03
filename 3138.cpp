#include <string>
#include <vector>

class Solution {
  public:
    int minAnagramLength(std::string s) {
        int n = s.size();

        auto check = [&](int len) -> bool {
            std::vector<int> cnt0(26);
            for (int i = 0; i < n; i += len) {
                std::vector<int> cnt1(26);
                for (int j = i; j < i + len; j++) {
                    cnt1[s[j] - 'a']++;
                }
                if (i > 0 && cnt0 != cnt1) {
                    return false;
                }
                cnt0.swap(cnt1);
            }
            return true;
        };

        for (int len = 1; len < n; len++) {
            if (n % len != 0)
                continue;
            if (check(len))
                return len;
        }

        return n;
    }
};