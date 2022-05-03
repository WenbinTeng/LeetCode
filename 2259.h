#include <string>

class Solution {
public:
    std::string removeDigit(std::string number, char digit) {
        std::string res = number;
        int idx = 0;

        for (int i = 0; i < number.size(); ++i)
        {
            if (number[i] == digit)
            {
                idx = i;
                
                if (i + 1 < number.size() && number[i] < number[i + 1])
                {
                    res.erase(i, 1);
                    return res;
                }
            }
        }

        res.erase(idx, 1);
        return res;
    }
};