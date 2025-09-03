#include <set>
#include <vector>

class KthLargest {
  public:
    KthLargest(int k, std::vector<int> &nums)
        : k(k),
          s(std::multiset<int, std::less<int>>(nums.begin(), nums.end())) {}

    int add(int val) {
        s.insert(val);
        while (s.size() > k)
            s.erase(s.begin());
        return *s.begin();
    }

  private:
    int k;
    std::multiset<int, std::less<int>> s;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
