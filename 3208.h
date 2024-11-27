#include <vector>

class Solution {
public:
    int numberOfAlternatingGroups(std::vector<int>& colors, int k) {
        int res = 0;
        int n = colors.size();
        int pos = 1;
        int len = 1;

        while (pos < n + k - 1) {
            if (colors[(pos - 1) % n] != colors[pos % n]) {
                len++;
            } else {
                if (len >= k) {
                    res += len - k + 1;
                }
                len = 1;
            }
            pos++;
        }

        if (len >= k) {
            res += len - k + 1;
        }

        return res;
    }
};