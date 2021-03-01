#include <vector>
#include <stack>

class Solution {
public:
    std::vector<double> getCollisionTimes(std::vector<std::vector<int>>& cars) {
        if (cars.size() == 1) return {-1};
        
        std::vector<double> res(cars.size(), -1);
        std::stack<int> s;
        s.push(cars.size() - 1);
        for (int n = cars.size(), i = n - 2; i >= 0; --i)
        {
            while (!s.empty())
            {
                if (cars[i][1] <= cars[s.top()][1] || (res[s.top()] > 0 && (double)(cars[s.top()][0] - cars[i][0]) / (cars[i][1] - cars[s.top()][1]) > res[s.top()]))
                {
                    s.pop();
                }
                else
                {
                    break;
                }
            }
            res[i] = s.empty() ? -1 : (double)(cars[s.top()][0] - cars[i][0]) / (cars[i][1] - cars[s.top()][1]);

            s.push(i);
        }

        return res;
    }
};