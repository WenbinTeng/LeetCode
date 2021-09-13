#include <string>

class Solution {
public:
    int maxProduct(std::string s) {
        dfs(s, 0);
        return res;
    }

private:
    int res = 1;
    std::string s1;
    std::string s2;

    void dfs(std::string s, int index)
    {
        if (index == s.size())
        {
            if (checkShrink(s1, 0, s1.size() - 1) && checkShrink(s2, 0, s2.size() - 1))
            {
                res = std::max(res, (int)s1.size() * (int)s2.size());
            }
            return;
        }

        s1.push_back(s[index]);
        dfs(s, index + 1);
        s1.pop_back();

        s2.push_back(s[index]);
        dfs(s, index + 1);
        s2.pop_back();

        dfs(s, index + 1);
    }

    bool checkShrink(std::string& s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i++] != s[j--]) return false;
        }
        
        return true;
    }
};