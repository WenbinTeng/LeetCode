#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        mem = std::vector<int>(n + 1, -1);
        return dfs(n);
    }

private:
    std::vector<int> mem;

    int dfs(int n) {
        return mem[n] == -1 ? (mem[n] = n <= 1 ? 1 : dfs(n - 1) + dfs(n - 2)) : mem[n];
    }
};