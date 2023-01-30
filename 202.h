#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> visited;

        while (n) {
            int t = n;
            int s = 0;

            while (t) {
                int d = t % 10;
                s += d * d;
                t /= 10;
            }

            if (visited.count(s)) {
                return false;
            } else {
                visited.insert(s);
            }

            if (s == 1)
                return true;

            n = s;
        }

        return false;
    }
};