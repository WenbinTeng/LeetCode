#include <vector>

class Solution {
  public:
    std::vector<int> resultArray(std::vector<int> &nums) {
        std::vector<int> arr1;
        std::vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        for (auto num : arr2) {
            arr1.push_back(num);
        }

        return arr1;
    }
};