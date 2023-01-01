#include <vector>

class Solution {
public:
    bool checkPossibility(std::vector<int> &nums) {
        auto isSorted = [&]() -> bool {
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1])
                    return false;
            }

            return true;
        };

        int prev;
        int next;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                prev = nums[i];
                next = nums[i + 1];

                nums[i] = nums[i + 1] = next;
                if (isSorted())
                    return true;
                nums[i] = nums[i + 1] = prev;
                if (isSorted())
                    return true;

                return false;
            }
        }

        return true;
    }
};