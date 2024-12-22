#include <vector>
#include <unordered_set>

class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        int n = nums.size();
        int rest = n % 3;
        int op = n / 3;
        std::unordered_set<int> dict;

        for (int i = 0; i < rest; i++) {
            int num = nums[n - 1 - i];
            if (dict.count(num))
                return op + 1;
            dict.insert(num);
        }

        for (int i = 0; i < n - rest; i += 3) {
            for (int j = 0; j < 3; j++) {
                int num = nums[n - 1 - rest - i - j];
                if (dict.count(num))
                    return op;
                dict.insert(num);
            }
            op--;
        }

        return op;
    }
};