#include <vector>

class Solution {
public:
    int getWinner(std::vector<int>& arr, int k) {
        int n = arr.size();
        int index = 0;
        bool firstPlay = true;

        k = std::min(k, n - 1);
        while (index < n) {
            bool win = true;
            for (int i = 1; i <= k; i++) {
                if (arr[index] < arr[(index + i) % n]) {
                    index = (index + i) % n;
                    win = false;
                    break;
                }
            }
            if (firstPlay) {
                k--;
                firstPlay = false;
            }
            if (win)
                return arr[index];
        }

        return -1;
    }
};