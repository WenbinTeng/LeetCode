#include <set>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::set<long long> s;
        s.insert(1);

        long long res = 1;
        for (int i = 0; i < n; ++i)
        {
            res = *s.begin();
            s.erase(s.begin());
            s.insert(res * 2);
            s.insert(res * 3);
            s.insert(res * 5);
        }

        return res;
    }
};