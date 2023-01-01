#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int> &nums) {
        binSearch(nums, 0, nums.size() - 1);
        return res;
    }

private:
    int res = -1;

    void binSearch(std::vector<int> &nums, int l, int r) {
        if (res != -1 || l > r)
            return;

        int mid = (l + r) / 2;
        int lv = mid - 1 >= 0 ? nums[mid - 1] : -INT_MAX - 1;
        int rv = mid + 1 < nums.size() ? nums[mid + 1] : -INT_MAX - 1;

        if (nums[mid] >= lv && nums[mid] >= rv) {
            res = mid;
        } else {
            if (nums[mid] <= lv)
                binSearch(nums, l, mid - 1);
            if (nums[mid] <= rv)
                binSearch(nums, mid + 1, r);
        }
    }
};