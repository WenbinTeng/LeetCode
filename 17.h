#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.size() == 0) return std::vector<std::string>();

        std::queue<std::string> res({""});
        std::unordered_map<char, std::string> alphabet;
        alphabet.insert(std::make_pair('2', "abc"));
        alphabet.insert(std::make_pair('3', "def"));
        alphabet.insert(std::make_pair('4', "ghi"));
        alphabet.insert(std::make_pair('5', "jkl"));
        alphabet.insert(std::make_pair('6', "mno"));
        alphabet.insert(std::make_pair('7', "pqrs"));
        alphabet.insert(std::make_pair('8', "tuv"));
        alphabet.insert(std::make_pair('9', "wxyz"));

        for (int i = 0; i < digits.size(); i++)
        {
            while (res.front().size() == i)
            {
                for (int j = 0; j < alphabet[digits[i]].size(); j++)
                {
                    res.push(res.front() + alphabet[digits[i]][j]);
                }
                res.pop();
            }
        }

        std::vector<std::string> ret;
        while (!res.empty())
        {
            ret.push_back(res.front()); res.pop();
        }
        return ret;
    }
};