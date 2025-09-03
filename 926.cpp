#include <string>

class Solution {
  public:
    int minFlipsMonoIncr(std::string s) {
        int res = INT_MAX;
        int cntRear0 = 0;
        int cntHead1 = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                cntRear0++;
        }

        res = cntRear0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                cntHead1++;
            else
                cntRear0--;
            res = std::min(res, cntHead1 + cntRear0);
        }

        return res;
    }
};