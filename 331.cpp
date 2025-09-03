#include <string>

class Solution {
  public:
    bool isValidSerialization(std::string preorder) {
        return dfs(preorder) && index == preorder.size() + 1;
    }

  private:
    int index = 0;

    bool dfs(std::string &s) {
        if (index >= s.size())
            return false;

        if (s[index] == '#') {
            index += 2;
            return true;
        }

        index = s.find_first_of(',', index) + 1;

        return index != 0 && dfs(s) && dfs(s);
    }
};