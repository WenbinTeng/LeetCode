#include <set>
#include <vector>

class UnionFind {
  public:
    void init(int n) {
        parent = std::vector<int>(n);
        rank = std::vector<int>(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot != yRoot) {
            if (rank[xRoot] > rank[yRoot])
                parent[yRoot] = xRoot;
            else {
                parent[xRoot] = yRoot;
                if (rank[xRoot] == rank[yRoot])
                    rank[yRoot]++;
            }
        }
    }

  private:
    std::vector<int> parent;
    std::vector<int> rank;
};

class Solution {
  public:
    std::vector<int> processQueries(int c,
                                    std::vector<std::vector<int>> &connections,
                                    std::vector<std::vector<int>> &queries) {
        std::vector<int> res;
        std::vector<bool> online(c + 1, true);
        std::vector<std::set<int>> onlineSet(c + 1);

        UnionFind uf;
        uf.init(c + 1);

        for (auto &connection : connections) {
            int u = connection[0];
            int v = connection[1];
            uf.merge(u, v);
        }

        for (int i = 1; i <= c; i++) {
            onlineSet[uf.find(i)].insert(i);
        }

        for (auto &query : queries) {
            int type = query[0];
            int x = query[1];
            if (type == 1) {
                if (online[x]) {
                    res.push_back(x);
                } else {
                    int root = uf.find(x);
                    if (onlineSet[root].empty())
                        res.push_back(-1);
                    else
                        res.push_back(*onlineSet[root].begin());
                }
            } else if (type == 2) {
                if (online[x]) {
                    online[x] = false;
                    int root = uf.find(x);
                    onlineSet[root].erase(x);
                }
            }
        }

        return res;
    }
};