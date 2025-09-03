#include <string>
#include <unordered_map>

class Solution {
  public:
    int lengthOfLongestSubstring(std::string s) {
        int res = 0;
        int left = 0;
        int right = 0;
        std::unordered_map<char, int> dict;

        while (right < s.size()) {
            while (dict[s[right]] == 1) {
                dict[s[left]] = 0;
                left++;
            }
            res = std::max(res, right - left + 1);
            dict[s[right]] = 1;
            right++;
        }

        return res;
    }
};