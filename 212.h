#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

struct TrieNode {
public:
    std::string word = "";
    std::unordered_map<char,TrieNode *> children;
};

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> & board, std::vector<std::string> & words) {
        TrieNode * root = new TrieNode();
        std::unordered_set<std::string> res;
        std::vector<std::string> ret;

        for (auto word: words){
            insertTrie(root,word);
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, res);
            }
        }

        for (auto word: res) {
            ret.push_back(word);
        }

        return ret;        
    }

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(std::vector<std::vector<char>>& board, int x, int y, TrieNode* root, std::unordered_set<std::string>& res) {
        char ch = board[x][y];
        if (!root->children.count(ch)) {
            return false;
        }
        
        root = root->children[ch];
        if (root->word.size() > 0) {
            res.insert(root->word);
        }

        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if (board[nx][ny] != '#') {
                    dfs(board, nx, ny, root, res);
                }
            }
        }
        board[x][y] = ch;

        return true;      
    }

    void insertTrie(TrieNode * root,const std::string & word)
    {
        TrieNode * node = root;

        for (auto c : word){
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }

        node->word = word;
    }

};