#include <queue>
#include <string>
#include <vector>

class BinaryIndexedTree {
  public:
    BinaryIndexedTree(int n) { tree.resize(n + 1, 0); }

    void update(int index, int delta) {
        while (index <= tree.size()) {
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
    std::string minInteger(std::string num, int k) {
        int n = num.size();
        std::string res;
        std::vector<std::queue<int>> digitPos(10);

        for (int i = 0; i < n; i++) {
            digitPos[num[i] - '0'].push(i + 1);
        }

        BinaryIndexedTree Bitree(n);

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                if (!digitPos[j].empty()) {
                    int behind = Bitree.rangeQuery(digitPos[j].front() + 1, n);
                    int d = digitPos[j].front() + behind - i;
                    if (d <= k) {
                        Bitree.update(digitPos[j].front(), 1);
                        digitPos[j].pop();
                        res.push_back(j + '0');
                        k -= d;
                        break;
                    }
                }
            }
        }

        return res;
    }
};