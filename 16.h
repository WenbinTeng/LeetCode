#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int res = nums[1] + nums[2] + nums[3];
        std::sort(nums.begin(), nums.end());
        for (int i = 0, n = nums.size(); i < n - 1; i++)
        {
            int head = i + 1;
            int tail = n - 1;
            while (head < tail)
            {
                int head_num = nums[head];
                int tail_num = nums[tail];
                int sum = nums[i] + head_num + tail_num;
                if (sum == target) return target;
                else if (sum < target) while (head < tail && nums[++head] == head_num);
                else if (sum > target) while (tail > head && nums[--tail] == tail_num);
                else ;

                if (std::abs(res - target) > std::abs(sum - target)) res = sum;
            }
            while (i < n - 1 && nums[i + 1] == nums[i]) i++;
        }

        return res;
    }
};