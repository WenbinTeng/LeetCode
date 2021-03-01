#include <string>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        std::unordered_map<char, int> um;

        if (n1 > n2) return false;

        for (int i = 0; i < n1; i++)
        {
            if (++um[s1[i]] == 0) um.erase(s1[i]);
            if (--um[s2[i]] == 0) um.erase(s2[i]);
        }

        for (int i = n1; i < n2; i++)
        {
            if (um.size() == 0) return true;

            if (++um[s2[i - n1]] == 0) um.erase(s2[i - n1]);
            if (--um[s2[i     ]] == 0) um.erase(s2[i     ]);
        }

        return um.size() == 0;
    }
};