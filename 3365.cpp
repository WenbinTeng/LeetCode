#include <algorithm>
#include <string>
#include <vector>

class Solution {
  public:
    bool isPossibleToRearrange(std::string s, std::string t, int k) {
        auto a = split(s, k);
        auto b = split(t, k);

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                return false;
        }

        return true;
    }

  private:
    std::vector<std::string> split(std::string &s, int k) {
        int len = s.size() / k;
        std::vector<std::string> res;

        for (int i = 0; i < s.size(); i += len) {
            res.push_back(s.substr(i, len));
        }

        return res;
    }
};