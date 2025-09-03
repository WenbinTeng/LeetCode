#include <algorithm>
#include <functional>
#include <vector>

class Solution {
  public:
    bool canMakeArithmeticProgression(std::vector<int> &arr) {
        int diff;
        std::sort(arr.begin(), arr.end(), std::less<int>());
        diff = arr[0] - arr[1];
        for (int i = 2; i < arr.size(); i++)
            if (arr[i - 1] - arr[i] != diff)
                return false;
        return true;
    }
};