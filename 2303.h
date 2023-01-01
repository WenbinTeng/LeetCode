#include <vector>

class Solution {
public:
    double calculateTax(std::vector<std::vector<int>> &brackets, int income) {
        double res = 0;

        if (income <= brackets[0][0]) {
            return (double)income * brackets[0][1] / 100.0;
        } else {
            res += (double)brackets[0][0] * brackets[0][1] / 100.0;
        }

        for (int i = 1; i < brackets.size(); ++i) {
            if (income > brackets[i][0]) {
                res += (double)(brackets[i][0] - brackets[i - 1][0]) * brackets[i][1] / 100.0;
            } else {
                res += (double)(income - brackets[i - 1][0]) * brackets[i][1] / 100.0;
                break;
            }
        }

        return res;
    }
};