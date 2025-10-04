#include <vector>

class Solution {
  public:
    int findKthLargest(std::vector<int> &nums, int k) {
        const int n = nums.size();

        auto partition = [&](auto &&self, int left, int right, int k) -> int {
            if (left == right)
                return nums[k];

            int pivot = nums[left];
            int i = left - 1;
            int j = right + 1;

            while (i < j) {
                do
                    i++;
                while (nums[i] < pivot);
                do
                    j--;
                while (nums[j] > pivot);
                if (i < j)
                    std::swap(nums[i], nums[j]);
            }

            if (k <= j)
                return self(self, left, j, k);
            else
                return self(self, j + 1, right, k);
        };

        return partition(partition, 0, n - 1, n - k);
    }
};