#include <stack>
#include <string>

class Solution {
public:
    int countCollisions(std::string directions) {
        int res = 0;
        int idx = 0;
        std::stack<char> s;

        while (idx < directions.size()) {
            if (directions[idx] == 'L') {
                if (!s.empty()) {
                    if (s.top() == 'S') {
                        s.pop();
                    }
                    while (idx < directions.size() && directions[idx] == 'L') {
                        s.push('L');
                        ++idx;
                    }
                    int cnt = 0;
                    while (!s.empty()) {
                        s.pop();
                        ++cnt;
                    }
                    res += cnt;
                } else {
                    while (idx < directions.size() && directions[idx] == 'L')
                        ++idx;
                }
                continue;
            } else if (directions[idx] == 'R') {
                if (!s.empty() && s.top() == 'S') {
                    while (!s.empty()) {
                        s.pop();
                    }
                }
                s.push('R');
            } else if (directions[idx] == 'S') {
                if (!s.empty()) {
                    if (s.top() == 'R') {
                        int cnt = 0;
                        while (!s.empty()) {
                            s.pop();
                            cnt++;
                        }
                        res += cnt;
                    } else if (s.top() == 'S') {
                        s.pop();
                    }
                }
                s.push('S');
            }

            ++idx;
        }

        return res;
    }
};