#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <vector>

class RandomizedSet {
  public:
    RandomizedSet() { std::srand((unsigned)std::time(NULL)); }

    bool insert(int val) {
        if (index.count(val)) {
            return false;
        }
        index[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!index.count(val)) {
            return false;
        }
        int i = index[val];
        int n = nums.back();
        index[n] = i;
        index.erase(val);
        nums[i] = n;
        nums.pop_back();
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }

  private:
    std::vector<int> nums;
    std::unordered_map<int, int> index;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */