#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        for (const auto& iter : t) ++rec[iter];

        int len = INT_MAX;
        int index = -1;
        int l = 0;
        int r = 0;

        while (r < s.size() && rec.find(s[r]) == rec.end()) ++r; l = r;

        while (r < s.size())
        {
            if (rec.find(s[r]) != rec.end()) ++win[s[r]];
            while (l <= r && check())
            {
                if (rec.find(s[l]) != rec.end()) --win[s[l]];
                if (len > r - l + 1)
                {
                    len = r - l + 1; index = l;
                }
                ++l;
            }
            ++r;
        }

        return index == -1 ? "" : s.substr(index, len);
    }

private:
    std::unordered_map<char, int> rec;
    std::unordered_map<char, int> win;

    bool check()
    {
        for (const auto& [c, n] : rec) if (win[c] < n) return false; return true;
    }
};