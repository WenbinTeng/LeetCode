#include <vector>

class TreeAncestor {
  public:
    TreeAncestor(int n, std::vector<int> &parent) {
        ancestor = std::vector<std::vector<int>>(n, std::vector<int>(16, -1));
        for (int i = 0; i < parent.size(); i++)
            ancestor[i][0] = parent[i];
        for (int j = 1; j < 16; j++)
            for (int i = 0; i < n; i++)
                if (ancestor[i][j - 1] != -1)
                    ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < 16; j++) {
            if ((k >> j) % 2 == 1) {
                node = ancestor[node][j];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }

  private:
    std::vector<std::vector<int>> ancestor;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */