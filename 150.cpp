#include <string>
#include <vector>

class Solution {
  public:
    int evalRPN(std::vector<std::string> &tokens) {
        std::vector<long long> nums;

        for (const auto &token : tokens) {
            if (token.size() > 1 || token[0] >= '0' && token[0] <= '9') {
                nums.push_back(std::stoi(token));
            } else {
                long long b = nums.back();
                nums.pop_back();
                long long a = nums.back();
                nums.pop_back();

                nums.push_back(token[0] == '+'   ? a + b
                               : token[0] == '-' ? a - b
                               : token[0] == '*' ? a * b
                               : token[0] == '/' ? a / b
                                                 : 0);
            }
        }

        return nums.back();
    }
};