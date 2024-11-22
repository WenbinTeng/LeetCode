#include <vector>
#include <algorithm>

class Solution {
public:
    bool isZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        std::vector<int> l;
        std::vector<int> r;

        for (auto& q : queries) {
            l.push_back(q[0]);
            r.push_back(q[1]);
        }
        
        std::sort(l.begin(), l.end());
        std::sort(r.begin(), r.end());

        for (int i = 0; i < nums.size(); i++) {
            int lsum = std::upper_bound(l.begin(), l.end(), i) - l.begin();
            int rsum = std::lower_bound(r.begin(), r.end(), i) - r.begin();
            if (lsum - rsum < nums[i])
                return false;
        }

        return true;
    }
};