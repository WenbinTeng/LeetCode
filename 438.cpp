#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        if (s.size() < p.size())
            return {};

        const int len = p.size();
        std::vector<int> res;
        std::unordered_map<char, int> dict;

        for (int i = 0; i < len; i++) {
            dict[p[i]]++;
        }

        for (int i = 0; i < len; i++) {
            dict[s[i]]--;
            if (dict[s[i]] == 0)
                dict.erase(s[i]);
        }

        if (dict.size() == 0)
            res.push_back(0);

        for (int i = len; i < s.size(); i++) {
            dict[s[i - len]]++;
            if (dict[s[i - len]] == 0)
                dict.erase(s[i - len]);
            dict[s[i]]--;
            if (dict[s[i]] == 0)
                dict.erase(s[i]);
            if (dict.size() == 0)
                res.push_back(i - len + 1);
        }

        return res;
    }
};