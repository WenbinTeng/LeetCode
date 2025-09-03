#include <string>
#include <vector>

class Solution {
  public:
    std::string minimizeResult(std::string expression) {
        int min = INT_MAX;
        int minI = 0;
        int minJ = 0;
        std::string num1;
        std::string num2;
        std::vector<int> prev1;
        std::vector<int> back1;
        std::vector<int> prev2;
        std::vector<int> back2;
        bool isAdd = false;
        int addIndex = 0;

        for (int i = 0; i < expression.size(); ++i) {
            if (isAdd) {
                num2.push_back(expression[i]);
            } else {
                num1.push_back(expression[i]);
            }

            if (expression[i] == '+') {
                isAdd = true;
                addIndex = i + 1;
            }
        }

        num1.pop_back();

        prev1.push_back(1);
        back1.push_back(std::stoi(num1));
        for (int i = 1; i < num1.size(); ++i) {
            prev1.push_back(std::stoi(num1.substr(0, i)));
            back1.push_back(std::stoi(num1.substr(i)));
        }
        for (int j = 1; j < num2.size(); ++j) {
            prev2.push_back(std::stoi(num2.substr(0, j)));
            back2.push_back(std::stoi(num2.substr(j)));
        }
        prev2.push_back(std::stoi(num2));
        back2.push_back(1);

        for (int i = 0; i < prev1.size(); ++i) {
            for (int j = 0; j < prev2.size(); ++j) {
                int num = prev1[i] * (back1[i] + prev2[j]) * back2[j];

                if (min > num) {
                    min = num;
                    minI = i;
                    minJ = j;
                }
            }
        }

        expression.insert(minI, "(");
        expression.insert(addIndex + minJ + 1 + 1, ")");

        return expression;
    }
};