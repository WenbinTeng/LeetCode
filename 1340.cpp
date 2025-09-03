#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxJumps(std::vector<int> &arr, int d) {
        mem = std::vector<int>(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++) {
            dfs(arr, d, i);
        }
        return *std::max_element(mem.begin(), mem.end());
    }

  private:
    std::vector<int> mem;

    void dfs(std::vector<int> &arr, int d, int index) {
        if (mem[index] != -1)
            return;
        mem[index] = 1;
        for (int j = index - 1; j >= 0 && j >= index - d && arr[index] > arr[j];
             j--) {
            dfs(arr, d, j);
            mem[index] = std::max(mem[index], mem[j] + 1);
        }
        for (int j = index + 1;
             j < arr.size() && j <= index + d && arr[index] > arr[j]; j++) {
            dfs(arr, d, j);
            mem[index] = std::max(mem[index], mem[j] + 1);
        }
    }
};