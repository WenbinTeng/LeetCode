#include <vector>
#include <numeric>

class NumArray {
public:
    NumArray(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) sums.push_back(i == 0 ? nums[0] : sums[i - 1] + nums[i]);
    }
    
    int sumRange(int i, int j) {
        return i == 0 ? sums[j] : sums[j] - sums[i - 1];
    }

private:
    std::vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */