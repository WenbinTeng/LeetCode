#include <deque>
#include <vector>

class Solution {
  public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
        std::vector<int> res;
        std::deque<int> monoQueue;

        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                res.push_back(nums[monoQueue.front()]);
            }
            while (!monoQueue.empty() && (monoQueue.front() <= i - k)) {
                monoQueue.pop_front();
            }
            while (!monoQueue.empty() && (nums[monoQueue.back()] < nums[i])) {
                monoQueue.pop_back();
            }
            monoQueue.push_back(i);
        }
        res.push_back(nums[monoQueue.front()]);

        return res;
    }
};