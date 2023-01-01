#include <vector>

class Solution {
public:
    int reinitializePermutation(int n) {
        nums.resize(n);
        perm.resize(n);
        for (int i = 0; i < n; ++i)
            perm.push_back(i);

        int res = 1;

        while (!foo())
            ++res;

        return res;
    }

private:
    std::vector<int> perm;
    std::vector<int> nums;

    bool foo() {
        for (int i = 0, n = perm.size(); i < n; ++i) {
            nums[i] = i & 1 ? nums[i] = perm[n / 2 + (i - 1) / 2] : nums[i] = perm[i / 2];
        }

        perm = nums;

        for (int i = 1, n = perm.size(); i < n; ++i) {
            if (nums[i] < nums[i - 1])
                return false;
        }

        return true;
    }
};