#include <algorithm>
#include <string>

class Solution {
public:
    std::string digitSum(std::string s, int k) {
        if (s.size() <= k)
            return s;

        std::string res;
        int num = 0;
        int cnt = 0;

        for (int i = 0; i < s.size(); ++i) {
            num += s[i] - '0';
            cnt += 1;
            if (cnt == k) {
                res = res + itos(num);
                num = 0;
                cnt = 0;
            }
        }

        if (cnt) {
            res = res + itos(num);
        }

        return digitSum(res, k);
    }

private:
    std::string itos(int num) {
        if (num == 0)
            return "0";

        std::string res;

        while (num) {
            res.push_back((num % 10) + '0');
            num /= 10;
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};