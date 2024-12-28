#include <vector>

class Solution {
public:
    int numberOfGoodSubarraySplits(std::vector<int>& nums) {
        const int mod = 1e+9+7;
        int res = 1;
        int prevOne = -1;
        int currOne = -1;
        std::vector<int> splitCnt;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currOne = i;
                break;
            }
        }
        if (currOne == -1) {
            return 0;
        }

        for (int i = currOne + 1; i < nums.size(); i++) {
            if (nums[i] == 1) {
                prevOne = currOne;
                currOne = i;
                splitCnt.push_back(currOne - prevOne);
            }
        }

        for (auto split : splitCnt) {
            res = ((long long)res * split) % mod;
        }

        return res;
    }
};