#include <string>
#include <vector>

class Trie {
  public:
    bool isEnd;
    std::vector<Trie *> child = std::vector<Trie *>(26);

    /** Initialize your data structure here. */
    Trie(bool isEnd) : isEnd(isEnd) {}
    Trie() : isEnd(false) {}

    /** Inserts a word into the trie. */
    void insert(std::string word) {
        auto node = this;

        for (const auto &c : word) {
            if (node->child[c - 'a'] == nullptr) {
                node->child[c - 'a'] = new Trie();
            }
            node = node->child[c - 'a'];
        }

        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        auto node = this;

        for (const auto &c : word) {
            if (node->child[c - 'a'] == nullptr) {
                return false;
            }
            node = node->child[c - 'a'];
        }

        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(std::string prefix) {
        auto node = this;

        for (const auto &c : prefix) {
            if (node->child[c - 'a'] == nullptr) {
                return false;
            }
            node = node->child[c - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */