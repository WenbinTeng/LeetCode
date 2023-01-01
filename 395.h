#include <string>
#include <unordered_map>

class Solution {
public:
    int longestSubstring(std::string s, int k) {
        return dfs(s, k, 0, s.size() - 1);
    }

private:
    int dfs(std::string &s, int k, int begin, int end) {
        if (end - begin + 1 < k)
            return 0;

        std::unordered_map<char, int> um;

        for (int i = begin; i <= end; ++i)
            ++um[s[i]];

        while (end - begin + 1 >= k && um[s[begin]] < k)
            ++begin;
        while (end - begin + 1 >= k && um[s[end]] < k)
            --end;

        if (end - begin + 1 < k)
            return 0;

        for (int i = begin; i <= end; ++i) {
            if (um[s[i]] < k)
                return std::max(dfs(s, k, begin, i - 1), dfs(s, k, i + 1, end));
        }

        return end - begin + 1;
    }
};