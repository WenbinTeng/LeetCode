#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    std::string getDirections(TreeNode *root, int startValue, int destValue) {
        dfs(root, startValue, destValue);
        int sameCnt = 0;
        while (startPath[sameCnt] == destPath[sameCnt])
            ++sameCnt;
        return std::string(startPath.size() - sameCnt, 'U') + destPath.substr(sameCnt);
    }

private:
    std::string path;
    std::string startPath;
    std::string destPath;

    void dfs(TreeNode *node, int startValue, int destValue) {
        if (node->val == startValue)
            startPath = path;
        if (node->val == destValue)
            destPath = path;

        if (node->left) {
            path.push_back('L');
            dfs(node->left, startValue, destValue);
            path.pop_back();
        }
        if (node->right) {
            path.push_back('R');
            dfs(node->right, startValue, destValue);
            path.pop_back();
        }
    }
};