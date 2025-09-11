#include <string>
#include <unordered_set>

class Solution {
  public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty())
            return false;

        int res = 1;
        int left = 0;
        int right = 1;
        std::unordered_set<char> dict = {s[0]};

        while (right < s.size()) {
            while (dict.count(s[right])) {
                dict.erase(s[left]);
                left++;
            }
            res = std::max(res, right - left + 1);
            dict.insert(s[right]);
            right++;
        }

        return res;
    }
};