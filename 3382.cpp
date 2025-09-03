#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>

class BinaryIndexedTree {
  public:
    BinaryIndexedTree(int n) { tree.resize(n + 1, 0); }

    void update(int index, int delta) {
        while (index < tree.size()) {
            tree[index] += delta;
            index += lowbit(index);
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= lowbit(index);
        }
        return sum;
    }

    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }

  private:
    std::vector<int> tree;

    int lowbit(int x) { return x & (-x); }
};

class Solution {
  public:
    long long maxRectangleArea(std::vector<int> &xCoord,
                               std::vector<int> &yCoord) {
        int n = xCoord.size();
        int m = 0;
        std::map<int, int> yMap;
        for (auto y : yCoord) {
            yMap[y] = 1;
        }
        for (auto &p : yMap) {
            p.second = ++m;
        }

        std::map<int, std::vector<std::pair<int, int>>> xLine;
        for (int i = 0; i < n; i++) {
            int x = xCoord[i];
            int y = yCoord[i];
            xLine[x].push_back({yMap[y], i});
        }
        for (auto &[x, vec] : xLine) {
            std::sort(vec.begin(), vec.end());
        }

        BinaryIndexedTree bTree(m);

        long long res = -1;
        std::unordered_map<long long, std::pair<int, int>> last;

        for (auto &[x, vec] : xLine) {
            for (int i = 0; i < vec.size(); i++) {
                bTree.update(vec[i].first, 1);
                if (i == 0)
                    continue;

                int ya = yCoord[vec[i - 1].second];
                int yb = yCoord[vec[i].second];
                long long key = ya * ((long long)1e9) + yb;
                int cnt = bTree.rangeQuery(vec[i - 1].first, vec[i].first);
                if (last.count(key)) {
                    auto &[oldCnt, oldX] = last[key];
                    if (cnt - oldCnt == 2)
                        res = std::max(res, 1LL * (x - oldX) * (yb - ya));
                }
                last[key] = {cnt, x};
            }
        }

        return res;
    }
};