#include <vector>

class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded) {
        int all = 0;
        int odd = 0;

        for (int i = 1; i <= encoded.size() + 1; ++i)
        {
            all ^= i;
        }

        for (int i = 1; i < encoded.size(); i += 2)
        {
            odd ^= encoded[i];
        }

        encoded.insert(encoded.begin(), all ^ odd);

        for (int i = 1; i < encoded.size(); ++i)
        {
            encoded[i] = encoded[i - 1] ^ encoded[i];
        }

        return encoded;
    }
};