#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysWithKDistinct(std::vector<int>& A, int K) {
        return atMostKDistinct(A, K) - atMostKDistinct(A, K - 1);
    }

private:
    int atMostKDistinct(std::vector<int>& A, int K)
    {
        if (A.empty()) return 0;

        int res = 0;
        std::unordered_map<int, int> um;

        for (int l = 0, r = 0; r < A.size();)
        {
            um[A[r]]++;
            while (um.size() > K)
            {
                um[A[l]]--;
                if (um[A[l]] == 0)
                {
                    um.erase(A[l]);
                }
                l++;
            }
            r++;

            res += r - l + 1;
        }

        return res;
    }
};