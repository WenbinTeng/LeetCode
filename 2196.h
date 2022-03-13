#include <vector>
#include <unordered_map>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions) {
        std::unordered_map<int, TreeNode*> umt;
        std::unordered_map<int, int> ump;

        for (const auto& description : descriptions)
        {
            int p = description[0];
            int c = description[1];
            int l = description[2];

            if (!umt.count(c))
            {
                umt[c] = new TreeNode(c);
            }
            if (!umt.count(p))
            {
                umt[p] = new TreeNode(p);
            }

            if (l)
            {
                umt[p]->left = umt[c];
            }
            else
            {
                umt[p]->right = umt[c];
            }

            ump[c] = p;
        }

        int root = descriptions[0][0];

        while (ump.count(root))
        {
            root = ump[root];
        }

        return umt[root];
    }
};