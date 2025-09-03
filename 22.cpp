#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::string> generateParenthesis(int n) {
        generate("", n, n);
        return res;
    }

  private:
    std::vector<std::string> res;

    void generate(std::string s, int l, int r) {
        if (l == 0 && r == 0)
            res.push_back(s);
        else {
            if (l > r)
                return;
            if (l > 0)
                generate(s + '(', l - 1, r);
            if (r > 0)
                generate(s + ')', l, r - 1);
        }
        return;
    }
};