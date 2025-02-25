#include <vector>
#include <algorithm>

class Solution {
public:
    long long minCost(std::vector<int>& arr, std::vector<int>& brr, long long k) {
        int n = arr.size();
        long long res = 0;
        long long cost = k;

        for (int i = 0; i < n; i++)
            res += std::abs(arr[i] - brr[i]);
        
        std::sort(arr.begin(), arr.end());
        std::sort(brr.begin(), brr.end());

        for (int i = 0; i < n; i++)
            cost += std::abs(arr[i] - brr[i]);

        return std::min(res, cost);
    }
};