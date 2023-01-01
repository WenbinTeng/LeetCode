#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int getMinSwaps(std::string num, int k) {
        int res = 0;
        std::string target = num;

        for (int i = 0; i < k; ++i)
            nextPermutation(target);

        for (int i = 0; i < num.size(); ++i) {
            if (num[i] != target[i]) {
                int j = i + 1;

                while (num[j] != target[i]) {
                    ++j;
                }

                while (j > i) {
                    std::swap(num[j - 1], num[j]);
                    ++res;
                    --j;
                }
            }
        }

        return res;
    }

private:
    void nextPermutation(std::string &num) {
        if (num.size() <= 1)
            return;

        int large = -1;
        int small = -1;
        int n = num.size();

        for (int i = n - 2; i >= 0; i--) {
            if (num[i] < num[i + 1]) {
                small = i;
                break;
            }
        }

        if (small == -1) {
            std::reverse(num.begin(), num.end());
            return;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (num[small] < num[i]) {
                large = i;
                break;
            }
        }

        std::swap(num[small], num[large]);
        std::reverse(num.begin() + small + 1, num.end());
    }
};