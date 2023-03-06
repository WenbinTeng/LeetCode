#include <string>

class Solution {
public:
    int minimumDeletions(std::string s) {
        int f = 0;
        int b = 0;

        for (char c : s)
            if (c == 'b')
                ++b;
            else
                f = std::min(f + 1, b);

        return f;
    }
};