#include <vector>
#include <string>

class Solution {
public:
    bool parseBoolExpr(std::string expression) {
        if (expression.size() == 1) {
            return expression == "t";
        }

        char operation = expression[0];
        bool res = false;
        std::vector<int> commaIndex;
        std::vector<int> bracketStack;
        std::vector<std::string> subexpressions;

        for (int i = 2; i < expression.size(); i++) {
            char t = expression[i];
            if (t == '(') {
                bracketStack.push_back(1);
            } else if (t == ')') {
                if (bracketStack.empty()) {
                    commaIndex.push_back(i);
                    break;
                } else {
                    bracketStack.pop_back();
                }
            } else if (t == ',' && bracketStack.empty()) {
                commaIndex.push_back(i);
            }
        }

        subexpressions.push_back(expression.substr(2, commaIndex[0] - 2));
        for (int i = 1; i < commaIndex.size(); i++) {
            subexpressions.push_back(expression.substr(commaIndex[i - 1] + 1, commaIndex[i] - (commaIndex[i - 1] + 1)));
        }

        if (operation == '!') {
            auto e = subexpressions.back();
            res = !parseBoolExpr(e);
        } else if (operation == '&') {
            res = true;
            for (auto e : subexpressions) {
                res &= parseBoolExpr(e);
            }
        } else if (operation == '|') {
            res = false;
            for (auto e : subexpressions) {
                res |= parseBoolExpr(e);
            }
        }

        return res;
    }
};