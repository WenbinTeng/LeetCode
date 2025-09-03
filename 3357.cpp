#include <algorithm>
#include <vector>

class Solution {
  public:
    int minDifference(std::vector<int> &nums) {
        int l = 0;
        int r = 1e9;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > 0 && nums[i] > 0) {
                l = std::max(l, std::abs(nums[i - 1] - nums[i]));
            }
        }

        while (l < r) {
            int mid = (l + r) / 2;
            if (check(nums, mid))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }

  private:
    bool check(std::vector<int> &nums, int k) {
        int n = nums.size();
        std::vector<std::pair<int, int>> interval;

        for (int i = 0; i < n; i++) {
            if (nums[i] == -1) {
                if (i > 0 && i + 1 < n && nums[i - 1] > 0 && nums[i + 1] > 0) {
                    int l = std::max(nums[i - 1] - k, nums[i + 1] - k);
                    int r = std::min(nums[i - 1] + k, nums[i + 1] + k);
                    interval.push_back({l, r});
                } else if (i > 0 && nums[i - 1] > 0) {
                    interval.push_back({nums[i - 1] - k, nums[i - 1] + k});
                } else if (i + 1 < n && nums[i + 1] > 0) {
                    interval.push_back({nums[i + 1] - k, nums[i + 1] + k});
                }
            }
        }
        if (interval.empty())
            return true;

        std::sort(interval.begin(), interval.end(),
                  [](std::pair<int, int> &a, std::pair<int, int> &b) {
                      return a.second < b.second;
                  });

        int X = interval[0].second;
        int Y = -1e9;

        for (auto &p : interval) {
            if (X < p.first)
                Y = std::max(Y, p.first);
        }

        for (auto &p : interval) {
            if ((X < p.first || X > p.second) && (Y < p.first || Y > p.second))
                return false;
        }

        for (int i = 0, j = -1; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                auto validate = [&]() {
                    if (j == -1 || j + 1 == i)
                        return true;
                    if ((std::abs(nums[j] - X) <= k &&
                         std::abs(nums[i] - X) <= k) ||
                        (std::abs(nums[j] - Y) <= k &&
                         std::abs(nums[i] - Y) <= k))
                        return true;
                    if (Y - X > k)
                        return false;
                    return true;
                };
                if (!validate())
                    return false;
                j = i;
            }
        }

        return true;
    }
};