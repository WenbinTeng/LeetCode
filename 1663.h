#include <string>

class Solution {
public:
    std::string getSmallestString(int n, int k) {
        int cnt = k - n;
        std::string res(n, 'a');

        for (int i = n - 1; i >= 0 && cnt > 0; --i) {
            res[i] += std::min(cnt, 'z' - 'a');
            cnt -= 'z' - 'a';
        }

        return res;
    }
};