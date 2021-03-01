#include <string>

class Solution {
public:
    int minOperations(std::string s) {
        int even_0 = 0;
        int even_1 = 0;
        int odd_0 = 0;
        int odd_1 = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            i % 2 == 0 ? (s[i] == '0' ? ++even_0 : ++even_1) : (s[i] == '0' ? ++odd_0 : ++odd_1);
        }

        return std::min(even_0 + odd_1, even_1 + odd_0);
    }
};