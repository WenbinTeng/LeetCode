#include <sstream>
#include <stack>
#include <string>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> nums;
        std::stack<int> sign;
        std::string n;

        nums.push(0);
        sign.push('(');
        sign.push('+');
        s.push_back(')');

        for (const auto &c : s) {
            if (c == ' ') {
                continue;
            }
            if (c == '(') {
                sign.push(c);
                sign.push('+');
                continue;
            }
            if (c == ')') {
                nums.push(n.empty() ? 0 : std::stoi(n));
                n = "";

                int sum = 0;
                while (sign.top() != '(') {
                    sum += sign.top() == '-' ? -nums.top() : nums.top();
                    nums.pop();
                    sign.pop();
                }
                sign.pop();

                std::stringstream ss;
                ss << sum;
                n = ss.str();

                continue;
            }
            if (c == '+' || c == '-') {
                nums.push(n.empty() ? 0 : std::stoi(n));
                sign.push(c);
                n = "";
                continue;
            }
            if (c >= '0' && c <= '9') {
                n.push_back(c);
            }
        }

        return std::stoi(n);
    }
};