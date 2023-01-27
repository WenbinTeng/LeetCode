#include <sstream>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root) {
        if (root == nullptr)
            return "#";
        else
            return std::to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data) {
        std::istringstream ss(data);
        return deserHelper(ss);
    }

private:
    TreeNode *deserHelper(std::istringstream &ss) {
        std::string s;
        ss >> s;

        if (s == "#") {
            return nullptr;
        }

        auto node = new TreeNode(std::stoi(s));
        node->left = deserHelper(ss);
        node->right = deserHelper(ss);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));