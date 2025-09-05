#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        if (nums.size() < 3)
            return std::vector<std::vector<int>>();

        std::vector<std::vector<int>> res;

        std::sort(nums.begin(), nums.end());

        for (int i = 0, n = nums.size(); i < n - 1; i++) {
            if (nums[i] > 0)
                break;

            int head = i + 1;
            int tail = n - 1;

            while (head < tail) {
                int head_num = nums[head];
                int tail_num = nums[tail];
                int sum = nums[i] + head_num + tail_num;

                if (sum == 0) {
                    res.push_back(
                        std::vector<int>({nums[i], nums[head], nums[tail]}));
                    while (head < tail && nums[++head] == head_num)
                        ;
                    while (tail > head && nums[--tail] == tail_num)
                        ;
                } else if (sum < 0)
                    while (head < tail && nums[++head] == head_num)
                        ;
                else if (sum > 0)
                    while (tail > head && nums[--tail] == tail_num)
                        ;
                else
                    ;
            }

            while (i < n - 1 && nums[i + 1] == nums[i])
                i++;
        }

        return res;
    }
};