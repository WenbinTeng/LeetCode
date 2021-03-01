#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        int res = 0;
        int index = 0;
        int range = 0;
        bool posFlag = false;
        bool negFlag = false;

        while (s[index] == ' ') s.erase(index, 1);

        if (s[index] == '+') { posFlag = true; s.erase(index, 1); }
        if (s[index] == '-') { negFlag = true; s.erase(index, 1); }
        if (posFlag && negFlag) return 0;

        while (s[index] == '0') s.erase(index, 1);
        while (s[index] >= '0' && s[index] <= '9')
        {
            index++;
            range++;
        }
        index -= range;

        if (range == 0) return 0;

        if (range > 11) { if (negFlag) return INT_MIN; return INT_MAX; }
        
        for (int i = 0; i < range; i++)
        {
            int pop = negFlag ? '0' - s[index + i] : s[index + i] - '0';
            if (res > INT_MAX / 10 || res == INT_MAX / 10 && pop > INT_MAX % 10) return INT_MAX;
            if (res < INT_MIN / 10 || res == INT_MIN / 10 && pop < INT_MIN % 10) return INT_MIN;
            else res = res * 10 + pop;
        }

        return res;
    }
};