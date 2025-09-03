#include <queue>
#include <vector>

class Solution {
  public:
    int fillCups(std::vector<int> &amount) {
        int res = 0;
        std::priority_queue<int> q;

        if (amount[0] > 0)
            q.push(amount[0]);
        if (amount[1] > 0)
            q.push(amount[1]);
        if (amount[2] > 0)
            q.push(amount[2]);

        while (!q.empty()) {
            if (q.size() >= 2) {
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();

                if (--a > 0)
                    q.push(a);
                if (--b > 0)
                    q.push(b);

                ++res;
            } else {
                res += q.top();
                break;
            }
        }

        return res;
    }
};
