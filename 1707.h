#include <vector>
#include <algorithm>

class Trie {
public:
    const int L = 31;

    Trie* children[2] = {};

    void insert(int val)
    {
        Trie *node = this;

        for (int i = L - 1; i >= 0; --i)
        {
            int bit = (val >> i) & 1;
            if (node->children[bit] == nullptr)
            {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
        }
    }

    int getMaxXor(int val)
    {
        int res = 0;

        Trie *node = this;

        for (int i = L - 1; i >= 0; --i)
        {
            int bit = (val >> i) & 1;
            if (node->children[bit ^ 1] != nullptr)
            {
                res |= 1 << i;
                bit ^= 1;
            }
            node = node->children[bit];
        }
        return res;
    }
};

class Solution {
public:
    std::vector<int> maximizeXor(std::vector<int> &nums, std::vector<std::vector<int>> &queries) {
        std::vector<int> res(queries.size());

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < queries.size(); ++i)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](auto &x, auto &y) { return x[1] < y[1]; });

        Trie *trie = new Trie();
        
        int idx = 0;
        for (auto &q : queries)
        {
            int x = q[0];
            int m = q[1];
            int qid = q[2];

            while (idx < nums.size() && nums[idx] <= m)
            {
                trie->insert(nums[idx]);
                ++idx;
            }

            res[qid] = idx == 0 ? -1 : trie->getMaxXor(x);
        }

        return res;
    }
};