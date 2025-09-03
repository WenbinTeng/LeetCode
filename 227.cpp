#include <stack>
#include <string>

class Solution {
  public:
    int calculate(std::string s) {
        std::stack<int> nums;
        std::stack<char> sign;
        std::string n;

        nums.push(0);
        sign.push('+');

        auto calTop = [&]() {
            int b = nums.top();
            nums.pop();
            int a = nums.top();
            nums.pop();

            nums.push(sign.top() == '+'   ? a + b
                      : sign.top() == '-' ? a - b
                      : sign.top() == '*' ? a * b
                      : sign.top() == '/' ? a / b
                                          : 0);
            sign.pop();
        };

        for (const auto &c : s) {
            if (c == ' ') {
                continue;
            }
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                nums.push(n.empty() ? 0 : std::stoi(n));
                n = "";
                if (sign.top() == '*' || sign.top() == '/')
                    calTop();
                sign.push(c);
                continue;
            }
            if (c >= '0' && c <= '9') {
                n.push_back(c);
            }
        }

        if (!n.empty()) {
            nums.push(std::stoi(n));

            if (sign.top() == '*' || sign.top() == '/') {
                calTop();
            }
        }

        int sum = 0;
        while (!sign.empty()) {
            sum += sign.top() == '-' ? -nums.top() : nums.top();
            nums.pop();
            sign.pop();
        }

        return sum + nums.top();
    }
};