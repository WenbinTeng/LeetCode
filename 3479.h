#include <vector>

class SegmentTree {
private:
    std::vector<int> tree;
    int size;

public:
    SegmentTree(std::vector<int>& baskets) {
        int n = baskets.size();
        size = 1;

        while (size < n) {
            size *= 2;
        }

        tree.assign(2 * size, -1);

        for (int i = 0; i < n; i++) {
            tree[size + i] = baskets[i];
        }
        
        for (int i = size - 1; i > 0; i--) {
            tree[i] = std::max(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int query(int x) {
        if (tree[1] < x)
            return -1;
        int index = 1;
        while (index < size) {
            if (tree[2 * index] >= x) {
                index = 2 * index;
            } else {
                index = 2 * index + 1;
            }
        }
        return index - size;
    }

    void update(int index) {
        index += size;
        tree[index] = -1;
        while (index > 1) {
            index /= 2;
            tree[index] = std::max(tree[2 * index], tree[2 * index + 1]);
        }
    }
};

class Solution {
public:
    int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
        int res = 0;
        SegmentTree st(baskets);

        for (int i = 0; i < fruits.size(); i++) {
            int index = st.query(fruits[i]);
            if (index == -1) {
                res++;
            } else {
                st.update(index);
            }
        }

        return res;
    }
};
