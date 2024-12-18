#include <vector>
#include <algorithm>

class Solution {
public:
    int miceAndCheese(std::vector<int>& reward1, std::vector<int>& reward2, int k) {
        int res = 0;
        int n = reward1.size();
        std::vector<int> diff(n);

        for (int i = 0; i < n; i++) {
            res += reward2[i];
            diff[i] = reward1[i] - reward2[i];
        }

        std::sort(diff.begin(), diff.end(), std::greater<int>());

        for (int i = 0; i < k; i++) {
            res += diff[i];
        }

        return res;
    }
};