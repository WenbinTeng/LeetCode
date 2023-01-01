#include <algorithm>
#include <string>

class Solution {
public:
    int minSwaps(std::string s) {
        int res = INT_MAX;
        int cnt = 0;
        int zero = std::count(s.begin(), s.end(), '0');
        int ones = std::count(s.begin(), s.end(), '1');
        bool flag;

        if (std::abs(zero - ones) > 1 || s.size() % 2 == 0 && zero != ones)
            return -1;

        auto helper = [&]() {
            if (s.size() % 2 == 1 && zero > ones && flag)
                return;
            if (s.size() % 2 == 1 && ones > zero && !flag)
                return;

            for (const auto &c : s) {
                if (!flag && c == '1')
                    ++cnt;
                flag = !flag;
            }

            res = std::min(res, cnt);
            cnt = 0;
        };

        flag = 0;
        helper();
        flag = 1;
        helper();

        return res == INT_MAX ? -1 : res;
    }
};