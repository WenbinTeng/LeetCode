#include <vector>

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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return nums.empty() ? nullptr : build(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* build(std::vector<int>& nums, int begin, int end)
    {
        return begin > end ? nullptr : new TreeNode(nums[(begin + end) / 2], build(nums, begin, (begin + end) / 2 - 1), build(nums, (begin + end) / 2 + 1, end));
    }
};