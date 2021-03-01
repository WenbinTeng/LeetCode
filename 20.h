#include <string>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.size() == 0) return true;

        std::vector<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
            case '[':
            case '{':
                stack.push_back(s[i]);
                break;
            case ')': if (!stack.empty() && stack.back() == '(') {stack.pop_back(); break;} else return false;
            case ']': if (!stack.empty() && stack.back() == '[') {stack.pop_back(); break;} else return false;
            case '}': if (!stack.empty() && stack.back() == '{') {stack.pop_back(); break;} else return false;
            }
        }

        return stack.empty();
    }
};