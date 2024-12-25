#include <vector>

class Solution {
public:
    int countPairs(std::vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (diffDigits(nums[i], nums[j]))
                    res++;
            }
        }

        return res;
    }

private:
    bool diffDigits(int x, int y) {
        std::vector<int> xDigits = std::move(getDigits(x));
        std::vector<int> yDigits = std::move(getDigits(y));
        std::vector<int> diff;
        for (int i = 0; i < 7; i++) {
            if (xDigits[i] != yDigits[i]) {
                diff.push_back(i);
            }
        }
        if (diff.size() == 0)
            return true;
        else if (diff.size() != 2)
            return false;
        int di = diff[0];
        int dj = diff[1];
        if (xDigits[di] == yDigits[dj] && xDigits[dj] == yDigits[di])
            return true;
        return false;
    }

    std::vector<int> getDigits(int n) {
        std::vector<int> digits(7, 0);
        for (int i = 0; i < 7; i++) {
            digits[i] = n % 10;
            n /= 10;
        }
        return digits;
    }
};