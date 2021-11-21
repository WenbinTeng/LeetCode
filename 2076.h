#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    std::vector<bool> friendRequests(int n, std::vector<std::vector<int>>& restrictions, std::vector<std::vector<int>>& requests) {
        std::vector<bool> res(requests.size());
        
        parent = std::vector<int>(n);

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }

        for (int i = 0; i < requests.size(); ++i)
        {
            int x = find(requests[i][0]);
            int y = find(requests[i][1]);
            std::vector<int> temp = parent;
            merge(x, y);
            bool flag = false;
            for (int j = 0; j < restrictions.size(); ++j)
            {
                int u = find(restrictions[j][0]);
                int v = find(restrictions[j][1]);
                if (u == v)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                parent = temp;
                res[i] = false;
            }
            else
            {
                res[i] = true;
            }
        }

        return res;
    }

private:
    std::vector<int> parent;

    int find(int x)
    {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    void merge(int i, int j)
    {
        parent[find(i)] = find(j);
    }
};