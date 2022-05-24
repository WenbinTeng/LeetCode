#include <vector>
#include <stack>

class Solution {
public:
    int totalStrength(std::vector<int>& strength) {
        int res = 0;
        int mod = 1e9+7;
        int n = strength.size();
        std::stack<int> s;
        std::vector<int> left(n, -1);
        std::vector<int> right(n, n);

        for (int i = 0; i < n; ++i)
        {
            while (!s.empty() && strength[s.top()] > strength[i])
            {
                right[s.top()] = i;
                s.pop();
            }
            if (!s.empty())
            {
                left[i] = s.top();
            }
            s.push(i);
        }

        std::vector<int> prevSum(n);
        prevSum[0] = strength[0];
        for (int i = 1; i < n; ++i)
        {
            prevSum[i] = (prevSum[i - 1] + strength[i]) % mod;
        }

        std::vector<int> prevPrevSum(n);
        prevPrevSum[0] = prevSum[0];
        for (int i = 1; i < n; ++i)
        {
            prevPrevSum[i] = (prevPrevSum[i - 1] + prevSum[i]) % mod;
        }

        auto f = [&](int l, int r) {
            if(r < 0) return 0;
            if(l < 0) return prevPrevSum[r];
            return (prevPrevSum[r] - prevPrevSum[l] + mod) % mod;
        };

        for (int i = 0; i < n; ++i)
        {
            int l = left[i] + 1;
            int r = right[i] - 1;
            int sleft = (long long)f(l - 2, i - 1) * (r - i + 1) % mod;
            int sright = (long long)f(i - 1, r) * (i - l + 1) % mod;
            res = (res + (long long)strength[i] * ((sright - sleft + mod) % mod)) % mod;
        }

        return res;
    }
};