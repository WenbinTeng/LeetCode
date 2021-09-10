#include <vector>

class Solution {
public:
    int chalkReplacer(std::vector<int>& chalk, int k) {
        long long sum_chalk = 0;

        for (auto c : chalk) {
            sum_chalk += c;
        }

        k = k % sum_chalk;

        for (int i = 0; i < chalk.size(); ++i) {
            if (k < 0) return i - 1; else k -= chalk[i]; 
        }

        return chalk.size() - 1;
    }
};