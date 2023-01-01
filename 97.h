#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        mem = std::vector<std::vector<int>>(s1.size() + 1, std::vector<int>(s2.size() + 1, -1));
        return s1.size() + s2.size() == s3.size() ? dfs(s1, s2, s3, 0, 0, 0) : false;
    }

private:
    std::vector<std::vector<int>> mem;

    int dfs(std::string &s1, std::string &s2, std::string &s3, int i1, int i2, int i3) {
        if (i3 == s3.size())
            return mem[i1][i2] = 1;

        if (mem[i1][i2] != -1)
            return mem[i1][i2];

        if (i1 != s1.size() && s1[i1] == s3[i3] && dfs(s1, s2, s3, i1 + 1, i2, i3 + 1))
            return mem[i1][i2] = 1;
        if (i2 != s2.size() && s2[i2] == s3[i3] && dfs(s1, s2, s3, i1, i2 + 1, i3 + 1))
            return mem[i1][i2] = 1;

        return mem[i1][i2] = 0;
    }
};