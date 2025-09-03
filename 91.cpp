#include <string>
#include <vector>

class Solution {
  public:
    int numDecodings(std::string s) {
        std::vector<int> mem(s.size() + 1, -1);
        return dfs(s, mem, 0);
    }

  private:
    int dfs(std::string &s, std::vector<int> &mem, int index) {
        if (index == s.size())
            return 1;
        if (index + 1 == s.size())
            return mem[index] = s[index] == '0' ? 0 : 1;

        int res = 0;
        int num1 = s[index] - '0';
        int num2 = s[index] - '0' == 0
                       ? INT_MAX
                       : (s[index] - '0') * 10 + s[index + 1] - '0';

        if (num1 != 0)
            res +=
                mem[index + 1] == -1 ? dfs(s, mem, index + 1) : mem[index + 1];
        if (num2 <= 26)
            res +=
                mem[index + 2] == -1 ? dfs(s, mem, index + 2) : mem[index + 2];

        return mem[index] = res;
    }
};