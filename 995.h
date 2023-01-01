#include <queue>
#include <vector>

class Solution {
public:
    int minKBitFlips(std::vector<int> &A, int K) {
        int res = 0;
        std::queue<int> q;
        for (int i = 0; i < A.size(); ++i) {
            while (!q.empty() && q.front() + K <= i)
                q.pop();
            if (q.size() % 2 == 1 && A[i] == 1 || q.size() % 2 == 0 && A[i] == 0) {
                if (i > A.size() - K)
                    return -1;
                q.push(i);
                ++res;
            }
        }

        return res;
    }
};