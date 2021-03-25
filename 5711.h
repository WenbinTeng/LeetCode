#include <vector>

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int res = 0;

        int l = 1;
        int r = maxSum;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            long long lSum = calSum(index,         mid - 1);
            long long rSum = calSum(n - 1 - index, mid - 1);

            if (lSum + rSum + mid <= maxSum) {l = mid + 1; res = mid;}
            if (lSum + rSum + mid >  maxSum) {r = mid - 1;}
        }

        return res;
    }

private:
    long long calSum(long long len, long long num)
    {
        return len > num ? (num + 1) * num / 2 + (len - num) : (num - len + 1 + num) * len / 2;
    }
};