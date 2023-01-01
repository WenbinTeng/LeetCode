#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
        if (nums.size() < 4)
            return std::vector<std::vector<int>>();

        std::sort(nums.begin(), nums.end());

        return nSum(nums, 0, target, 4);
    }

private:
    std::vector<std::vector<int>> nSum(std::vector<int> &nums, int index, int target, int n) {
        if (nums.size() < n)
            return std::vector<std::vector<int>>();

        std::vector<std::vector<int>> res;

        if (n == 2) {
            return towSum(nums, index, target);
        } else {
            for (int i = index; i <= nums.size() - n; i++) {
                if (i > index && nums[i] == nums[i - 1])
                    continue;
                std::vector<std::vector<int>> subres = nSum(nums, i + 1, target - nums[i], n - 1);
                for (auto &iter : subres) {
                    iter.push_back(nums[i]);
                    res.push_back(iter);
                    iter.pop_back();
                }
            }
        }

        return res;
    }

    std::vector<std::vector<int>> towSum(std::vector<int> &nums, int index, int target) {
        std::vector<std::vector<int>> res;
        int head = index;
        int tail = nums.size() - 1;

        while (head < tail) {
            int head_num = nums[head];
            int tail_num = nums[tail];
            int sum = head_num + tail_num;
            if (sum == target) {
                res.push_back({head_num, tail_num});
                while (head < tail && nums[++head] == head_num)
                    ;
                while (tail > head && nums[--tail] == tail_num)
                    ;
            } else if (sum < target)
                while (head < tail && nums[++head] == head_num)
                    ;
            else if (sum > target)
                while (tail > head && nums[--tail] == tail_num)
                    ;
            else
                ;
        }

        return res;
    }
};