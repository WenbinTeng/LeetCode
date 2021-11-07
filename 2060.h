#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    bool possiblyEquals(std::string s1, std::string s2) {
        int n = s1.size();
        int m = s2.size();
        std::vector<std::vector<std::unordered_set<int>>> dp(n + 1, std::vector<std::unordered_set<int>>(m + 1));

        auto isDigit = [](char c){ return c >= '0' && c <= '9'; };

        dp[0][0].insert(0);
                
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int delta : dp[i][j]) {
                    int num = 0;
                    for (int p = i; p < std::min(i + 3, n); ++p) {
                        if (isDigit(s1[p])) {
                            num = num * 10 + s1[p] - '0';
                            dp[p + 1][j].insert(delta + num);
                        } else {
                            break;
                        }
                    }
                    
                    num = 0;
                    for (int q = j; q < std::min(j + 3, m); ++q) {
                        if (isDigit(s2[q])) {
                            num = num * 10 + s2[q] - '0';
                            dp[i][q + 1].insert(delta - num);
                        } else {
                            break;
                        }
                    }
                    
                    if (i < n && delta < 0 && !isDigit(s1[i])) 
                        dp[i + 1][j].insert(delta + 1);
                            
                    if (j < m && delta > 0 && !isDigit(s2[j])) 
                        dp[i][j + 1].insert(delta - 1);
                            
                    if (i < n && j < m && delta == 0 && s1[i] == s2[j])
                        dp[i + 1][j + 1].insert(0);
                }
            }
        }
        
        return dp[n][m].count(0);
    }
};