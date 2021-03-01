#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int carry = 1;

        for (auto iter = digits.rbegin(); iter != digits.rend() && carry; ++iter)
        {
            carry = (*iter + 1) / 10;
            *iter = (*iter + 1) % 10;
        }

        if (carry) digits.insert(digits.begin(), 1);

        return digits;
    }
};