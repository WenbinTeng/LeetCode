#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int countBeautifulPairs(std::vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (std::__gcd(getFirstDigit(nums[i]), getLastDigit(nums[j])) == 1)
                    res++;

        return res;
    }

private:
    int getFirstDigit(int num) {
        std::string s = std::to_string(num);
        return (int)(s[0] - '0');
    }

    int getLastDigit(int num) {
        std::string s = std::to_string(num);
        return (int)(s.back() - '0');
    }
};