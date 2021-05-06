#include <vector>

class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded, int first) {
        encoded.insert(encoded.begin(), first);
        
        for (int i = 1; i < encoded.size(); ++i)
        {
            encoded[i] = encoded[i] ^ encoded[i - 1];
        }

        return encoded;
    }
};