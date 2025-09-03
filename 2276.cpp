#include <set>

class CountIntervals {
  public:
    CountIntervals() {}

    void add(int left, int right) {
        int L = left;
        int R = right;

        auto iter = s.lower_bound({left - 1, -2e9});
        while (iter != s.end()) {
            if (iter->second > right + 1)
                break;

            L = std::min(L, iter->second);
            R = std::max(R, iter->first);
            cnt -= iter->first - iter->second + 1;
            s.erase(iter++);
        }

        cnt += R - L + 1;
        s.insert({R, L});
    }

    int count() { return cnt; }

  private:
    int cnt = 0;
    std::set<std::pair<int, int>> s;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */