#include <vector>

class Solution {
public:
    int numberOfAlternatingGroups(std::vector<int>& colors) {
        int res = 0;
        int n = colors.size();

        for (int i = 0; i < colors.size(); i++) {
            int l = (i - 1 + n) % n;
            int r = (i + 1) % n;

            if (colors[l] != colors[i] && colors[i] != colors[r])
                res++;
        }

        return res;
    }
};