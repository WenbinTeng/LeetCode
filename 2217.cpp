#include <string>
#include <vector>

class Solution {
  public:
    std::vector<long long> kthPalindrome(std::vector<int> &queries,
                                         int intLength) {
        std::vector<long long> res;

        for (int i = 0; i <= intLength; ++i) {
            cnt.push_back(getPalindromeCnt(i));
        }

        for (const auto query : queries) {
            auto num = getkthPalindrome(query, intLength, false);
            if (!exist) {
                res.push_back(-1);
            } else {
                res.push_back(std::stoll(num));
            }
            exist = true;
        }

        return res;
    }

  private:
    std::vector<int> cnt;
    bool exist = true;

    std::string getkthPalindrome(int query, int len, bool prevZero) {
        std::string res;

        if (len == 1) {
            if (prevZero && query > 10 || !prevZero && query > 9) {
                exist = false;
                return "0";
            } else {
                res.push_back(query + '0' - (prevZero ? 1 : 0));
                return res;
            }
        }
        if (len == 2) {
            if (prevZero && query > 10 || !prevZero && query > 9) {
                exist = false;
                return "0";
            } else {
                res.push_back(query + '0' - (prevZero ? 1 : 0));
                res.push_back(query + '0' - (prevZero ? 1 : 0));
                return res;
            }
        }

        for (int i = prevZero ? 0 : 1; i <= 9; ++i) {
            if (query <= cnt[len - 2]) {
                char head = i + '0';
                char tail = i + '0';
                res = head + getkthPalindrome(query, len - 2, true) + tail;
                break;
            } else {
                query -= cnt[len - 2];
            }
        }

        if (res.empty()) {
            exist = false;
        }

        return res;
    }

    int getPalindromeCnt(int len) {
        return len <= 2 ? 10 : 10 * getPalindromeCnt(len - 2);
    }
};