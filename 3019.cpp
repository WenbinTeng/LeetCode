#include <string>

class Solution {
  public:
    int countKeyChanges(std::string s) {
        int res = 0;

        for (auto &c : s)
            c = std::tolower(c);

        for (int i = 1; i < s.size(); i++)
            if (s[i] != s[i - 1])
                res++;

        return res;
    }
};