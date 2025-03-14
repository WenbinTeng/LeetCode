#include <string>

class Solution {
public:
    bool isBalanced(std::string num) {
        int evenSum = 0;
        int oddSum = 0;

        for (int i = 0; i < num.size(); i += 2) {
            evenSum += (num[i] - '0');
        }

        for (int i = 1; i < num.size(); i += 2) {
            oddSum += (num[i] - '0');
        }

        return evenSum == oddSum;
    }
};