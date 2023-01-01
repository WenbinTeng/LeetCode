#include <string>
#include <vector>

class Solution {
public:
    int minCharacters(std::string a, std::string b) {
        int res = a.size() + b.size();

        int aCount[26] = {0};
        int bCount[26] = {0};

        for (int i = 0; i < a.size(); aCount[a[i++] - 'a']++)
            ;
        for (int i = 0; i < b.size(); bCount[b[i++] - 'a']++)
            ;

        for (int i = 0; i < 26; i++)
            res = std::min(res, (int)a.size() + (int)b.size() - aCount[i] - bCount[i]);

        auto foo = [&](int *a, int *b) {
            for (int count, i = 1; i < 26; i++) {
                count = 0;

                for (int j = i; j < 26; j++)
                    count += a[j];
                for (int j = 0; j < i; j++)
                    count += b[j];

                res = std::min(res, count);
            }
        };

        foo(aCount, bCount);
        foo(bCount, aCount);

        return res;
    }
};