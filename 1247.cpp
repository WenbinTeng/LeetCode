#include <string>

class Solution {
  public:
    int minimumSwap(std::string s1, std::string s2) {
        int xy = 0;
        int yx = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == 'x' and s2[i] == 'y')
                xy++;
            if (s1[i] == 'y' and s2[i] == 'x')
                yx++;
        }

        if ((xy + yx) & 1 == 1) {
            return -1;
        }

        return xy / 2 + yx / 2 + xy % 2 + yx % 2;
    }
};