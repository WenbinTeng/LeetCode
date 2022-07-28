#include <vector>
#include <queue>
#include <unordered_set>

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {

    }
    
    int popSmallest() {
        if (prev.empty())
        {
            return curr++;
        }
        else
        {
            int ret = prev.top();
            prev.pop();
            prevSet.erase(ret);
            return ret;
        }
    }
    
    void addBack(int num) {
        if (num < curr && !prevSet.count(num))
        {
            prev.push(num);
            prevSet.insert(num);
        }
    }

private:
    int curr = 1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> prev;
    std::unordered_set<int> prevSet;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */