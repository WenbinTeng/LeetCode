#include <memory.h>

#include <string>
#include <vector>

class Solution {
  public:
    int longestValidParentheses(std::string s) {
        if (s.size() <= 1)
            return 0;

        int cnt = 0;
        int res = 0;
        const unsigned int n = s.size();
        bool validMatchArray[n];
        memset(validMatchArray, 0, sizeof(bool) * n);
        std::vector<int> parentheseStack;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                parentheseStack.push_back(i);
            if (s[i] == ')') {
                if (!parentheseStack.empty()) {
                    validMatchArray[i] = true;
                    validMatchArray[parentheseStack.back()] = true;
                    parentheseStack.pop_back();
                }
            }
        }

        for (auto &iter : parentheseStack) {
            validMatchArray[iter] = false;
        }
        for (int i = 0; i < n; i++) {
            if (validMatchArray[i]) {
                cnt++;
            } else if (cnt) {
                res = res < cnt ? cnt : res;
                cnt = 0;
            }
        }

        return std::max(cnt, res);
    }
};